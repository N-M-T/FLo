/***************************************************************************
**                                                                        **
**  Fixation Logger (FLo)                                                 **
**                                                                        **
**  Copyright (C) 2017-2018 Neil Thomas                                   **
**  All rights reserved.                                                  **
**                                                                        **
**  This file is part of the FLo.                                         **
**                                                                        **
**  The FLo is free software: you can redistribute it and/or modify       **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Neil Thomas                                          **
**          Contact: neil.thomas@uni.cumbria.ac.uk                        **
**             Date: 22.05.17                                             **
**          Version: 1.0.0-beta                                           **
****************************************************************************/

#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myPlayer = new Player();

    QObject::connect(myPlayer, SIGNAL(processedImage(QImage)), this, SLOT(updatePlayerUI(QImage)));

    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(seek(int)));
    connect(ui->horizontalSlider, SIGNAL(sliderPressed()), this, SLOT(isSliderPressed()));

    ui->video->hide();
    ui->startLabel->hide();
    ui->horizontalSlider->hide();
    ui->endLabel->hide();
    ui->frameLabel->hide();
    ui->textBrowser->hide();
    ui->feat1Lab->hide();
    ui->feat2Lab->hide();
    ui->feat3Lab->hide();
    ui->feat4Lab->hide();
    ui->feat5Lab->hide();

    ui->play_pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->leftButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->rightButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->reloadButton->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    ui->reloadButton->setEnabled(false);

    ui->actionEnterFeatures->setEnabled(false);
    ui->actionBasic->setEnabled(false);
}

void MainWindow::updatePlayerUI(QImage img)
{
    if (!img.isNull())
    {
        ui->video->setAlignment(Qt::AlignCenter);
        ui->video->setPixmap(QPixmap::fromImage(img).scaled(ui->video->size(),
                                           Qt::KeepAspectRatio, Qt::FastTransformation));

        ui->horizontalSlider->setValue(myPlayer->getCurrentFrame()-1);
        ui->startLabel->setText(getFormattedTime(myPlayer->getCurrentFrame()/fps));
        ui->frameLabel->setText(QString::number(myPlayer->getCurrentFrame()));

        //update play button when video finishes
        if(myPlayer->getCurrentFrame()==frames)
        {
            ui->play_pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        }
    }
}

MainWindow::~MainWindow()
{
    delete myPlayer;
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    filename = QFileDialog::getOpenFileName(this,
                                          tr("Open Video"), ".",
                                          tr("Video Files (*.avi *.mpg *.mp4)"));
    name = filename;

    if (!filename.isEmpty())
    {
        if (!myPlayer->loadVideo(filename.toAscii().data()))
        {
            QMessageBox msgBox;
            msgBox.setText("Neine!");
            msgBox.exec();
        }
        else
        {
            load_refreshVideo();
        }
    }
}

void MainWindow::load_refreshVideo()
{
    this->setWindowTitle(name.fileName());

    frames = myPlayer->getNumberOfFrames();
    fps = myPlayer->getFrameRate();

    ui->video->show();
    ui->startLabel->show();
    ui->endLabel->setText(getFormattedTime(frames/fps));
    ui->endLabel->show();
    ui->frameLabel->show();
    ui->textBrowser->setText(QString(name.fileName() + ": Loaded"));
    ui->textBrowser->show();

    ui->horizontalSlider->setMaximum(frames-1);
    ui->horizontalSlider->show();
    ui->horizontalSlider->setEnabled(true);

    ui->actionEnterFeatures->setEnabled(true);
    ui->play_pauseButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
    ui->leftButton->setEnabled(true);
    ui->rightButton->setEnabled(true);
    ui->reloadButton->setEnabled(true);
    ui->actionBasic->setEnabled(false);

    ui->feat1Lab->hide();
    ui->feat2Lab->hide();
    ui->feat3Lab->hide();
    ui->feat4Lab->hide();
    ui->feat5Lab->hide();

    //clear old elements
    if(!feat1.isEmpty())
    {
        feat1.clear();
        feat2.clear();
        feat3.clear();
        feat4.clear();
        feat5.clear();

        x_forAxis.resize(0);
        featNoAdded.resize(0);
        feat1Added.resize(0);
        feat2Added.resize(0);
        feat3Added.resize(0);
        feat4Added.resize(0);
        feat5Added.resize(0);
    }

    myPlayer->setCurrentFrame(0);
    myPlayer->emitCurrentFrame();
}

void MainWindow::on_play_pauseButton_clicked()
{
    if (myPlayer->isStopped() && myPlayer->getCurrentFrame() < frames)
    {
        myPlayer->Play();
        ui->play_pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    else
    {
        myPlayer->Stop();
        ui->play_pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void MainWindow::on_stopButton_clicked()
{
    if(!myPlayer->isStopped())
    {
        myPlayer->Stop();
        ui->play_pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }

    if(myPlayer->getCurrentFrame() == frames)
    {
        myPlayer->setCurrentFrame(0);
        myPlayer->emitCurrentFrame();
        ui->play_pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void MainWindow::on_leftButton_clicked()
{
    if(myPlayer->isStopped() && myPlayer->getCurrentFrame()>1) //so we don't crash the program)
    {
        myPlayer->left();
        ui->frameLabel->setText(QString::number(myPlayer->getCurrentFrame()));

        //delete previous fixation if we have recorded gaze data
        if(!feat1.isEmpty())
        {
            x_forAxis.removeLast();
            feat1Added.removeLast();

            if(!feat2.isEmpty())
            {
                feat2Added.removeLast();
            }

            if(!feat3.isEmpty())
            {
                feat3Added.removeLast();
            }

            if(!feat4.isEmpty())
            {
                feat4Added.removeLast();
            }

            if(!feat5.isEmpty())
            {
                feat5Added.removeLast();
            }

            ui->textBrowser->setText("Fixation deleted");
        }
    }
}

void MainWindow::on_rightButton_clicked()
{
    if(myPlayer->isStopped() && myPlayer->getCurrentFrame() < frames)
    {
        myPlayer->right();
        ui->frameLabel->setText(QString::number(myPlayer->getCurrentFrame()));

        if(!feat1.isEmpty()) //add no fixation to vectors
        {
            x_forAxis.append(myPlayer->getCurrentFrame() / fps);
            feat1Added.append(0);
            feat2Added.append(0);
            feat3Added.append(0);
            feat4Added.append(0);
            feat5Added.append(0); //using binary to indicate whether feature was fixated or not

            ui->textBrowser->setText("No fixation");
        }
    }
}

void MainWindow::on_reloadButton_clicked()
{
    if(myPlayer->isStopped())
    {
        load_refreshVideo();
    }
}

void MainWindow::seek(int value)
{
    ui->frameLabel->setText(QString::number(value));
    myPlayer->setCurrentFrame(value);
    myPlayer->emitCurrentFrame();
}

void MainWindow::isSliderPressed()
{
    myPlayer->Stop();
    ui->play_pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

void MainWindow::on_actionEnterFeatures_triggered()
{
    if(fps>0)
    {
        if(!feat1.isEmpty())
        {
            myFeatures->setFeatures(feat1, feat2, feat3, feat4, feat5); //if already loaded, send current features
            myFeatures->show();                                         //back to feature dialog
        }
        else
        {
            myFeatures = new featureDialog;
            QObject::connect(myFeatures, SIGNAL(sendFeatures(const featureStruct)), this, SLOT(updateFeatures(const featureStruct)));
            myFeatures->show();
        }
    }
}

//update feature list
void MainWindow::updateFeatures(const featureStruct features)
{
    if(!features.feature1.isEmpty())
    {
        feat1 = features.feature1;

        myPlayer->setCurrentFrame(0); //will remove this later on
        myPlayer->emitCurrentFrame();

        ui->feat1Lab->setText(QString("Feature 1:  " + feat1));
        ui->feat1Lab->show();
        ui->feat1Lab->setEnabled(false);
        ui->textBrowser->setText("Features updated");
        ui->horizontalSlider->setEnabled(false);
        ui->play_pauseButton->setEnabled(false);
    }

    if(!features.feature2.isEmpty())
    {
        feat2 = features.feature2;
        ui->feat2Lab->setText(QString("Feature 2:  " + feat2));
        ui->feat2Lab->show();
        ui->feat2Lab->setEnabled(false);

    }

    if(!features.feature3.isEmpty())
    {
        feat3 = features.feature3;
        ui->feat3Lab->setText(QString("Feature 3:  " + feat3));
        ui->feat3Lab->show();
        ui->feat3Lab->setEnabled(false);
    }

    if(!features.feature4.isEmpty())
    {
        feat4 = features.feature4;
        ui->feat4Lab->setText(QString("Feature 4:  " + feat4));
        ui->feat4Lab->show();
        ui->feat4Lab->setEnabled(false);
    }

    if(!features.feature5.isEmpty())
    {
        feat5 = features.feature5;
        ui->feat5Lab->setText(QString("Feature 5:  " + feat5));
        ui->feat5Lab->show();
        ui->feat5Lab->setEnabled(false);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(myPlayer->isStopped() && fps > 0) //is video loaded?
    {
        if(!feat1.isEmpty() && myPlayer->getCurrentFrame() < frames) //are we within the video sequence?
        {
            if(event->key()== Qt::Key_1) //define key event actions
            {
                x_forAxis.append(myPlayer->getCurrentFrame() / fps);
                feat1Added.append(1);
                feat2Added.append(0);
                feat3Added.append(0);
                feat4Added.append(0);
                feat5Added.append(0);

                ui->feat1Lab->setEnabled(true);
                ui->textBrowser->setText("Fixation added");

                myPlayer->right();

                resultsEnable();
            }
        }

        if(event->key()== Qt::Key_2)
        {
            if(!feat2.isEmpty() && myPlayer->getCurrentFrame() < frames)
            {
                x_forAxis.append(myPlayer->getCurrentFrame() / fps);
                feat1Added.append(0);
                feat2Added.append(1);
                feat3Added.append(0);
                feat4Added.append(0);
                feat5Added.append(0);

                ui->feat2Lab->setEnabled(true);
                ui->textBrowser->setText("Fixation added");

                myPlayer->right();

                resultsEnable();
            }
        }

        if(event->key()== Qt::Key_3)
        {
            if(!feat3.isEmpty() && myPlayer->getCurrentFrame() < frames)
            {
                x_forAxis.append(myPlayer->getCurrentFrame() / fps);
                feat1Added.append(0);
                feat2Added.append(0);
                feat3Added.append(1);
                feat4Added.append(0);
                feat5Added.append(0);

                ui->feat3Lab->setEnabled(true);
                ui->textBrowser->setText("Fixation added");

                myPlayer->right();

                resultsEnable();
            }
        }

        if(event->key()== Qt::Key_4)
        {
            if(!feat4.isEmpty() && myPlayer->getCurrentFrame() < frames)
            {
                x_forAxis.append(myPlayer->getCurrentFrame() / fps);
                feat1Added.append(0);
                feat2Added.append(0);
                feat3Added.append(0);
                feat4Added.append(1);
                feat5Added.append(0);

                ui->feat4Lab->setEnabled(true);
                ui->textBrowser->setText("Fixation added");

                myPlayer->right();

                resultsEnable();
            }
        }

        if(event->key()== Qt::Key_5)
        {
            if(!feat5.isEmpty() && myPlayer->getCurrentFrame() < frames)
            {
                x_forAxis.append(myPlayer->getCurrentFrame() / fps);
                feat1Added.append(0);
                feat2Added.append(0);
                feat3Added.append(0);
                feat4Added.append(0);
                feat5Added.append(1);

                ui->feat5Lab->setEnabled(true);
                ui->textBrowser->setText("Fixation added");

                myPlayer->right();

                resultsEnable();
            }
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_1)
    {
        ui->feat1Lab->setEnabled(false);
    }
    if(event->key()== Qt::Key_2)
    {
        ui->feat2Lab->setEnabled(false);
    }
    if(event->key()== Qt::Key_3)
    {
        ui->feat3Lab->setEnabled(false);
    }
    if(event->key()== Qt::Key_4)
    {
        ui->feat4Lab->setEnabled(false);
    }
    if(event->key()== Qt::Key_5)
    {
        ui->feat5Lab->setEnabled(false);
    }
}

void MainWindow::resultsEnable()
{
    if(x_forAxis.size() > 0)
    {
        ui->actionBasic->setEnabled(true);
    }
    else
    {
        ui->actionBasic->setEnabled(false);
    }
}

QString MainWindow::getFormattedTime(double timeInSeconds)
{
    int msec = timeInSeconds * 1000;

    int seconds   = (int) (msec / 1000) % 60 ;
    int minutes   = (int) ((msec / (1000*60)) % 60);
    int hours     = (int) ((msec / (1000*60*60)) % 24);

    QTime t(hours, minutes, seconds);

    if (hours == 0 )
        return t.toString("mm:ss");

    else
        return t.toString("h:mm:ss");
}

void MainWindow::on_actionBasic_triggered()
{
    myResultsDialog = new resultsDialog;
    myResultsDialog->passVectors(x_forAxis, feat1Added, feat2Added, feat3Added, feat4Added, feat5Added);
    myResultsDialog->outcomeMeasures(feat1, feat2, feat3, feat4, feat5);
    myResultsDialog->passFilename(filename);
    myResultsDialog->show();
}
