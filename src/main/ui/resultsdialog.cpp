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

#include "resultsdialog.h"
#include "ui_resultsdialog.h"

resultsDialog::resultsDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultsDialog)
{
    ui->setupUi(this);
}

resultsDialog::~resultsDialog()
{
    delete ui;
}


void resultsDialog::passFeatures(QString feat1, QString feat2, QString feat3, QString feat4, QString feat5)
{
    Feat1 = feat1;
    Feat2 = feat2;
    Feat3 = feat3;
    Feat4 = feat4;
    Feat5 = feat5;
}

void resultsDialog::passVectors(QVector<double> x_forAxis, QVector<double> feat1Added, QVector<double> feat2Added,
                QVector<double> feat3Added, QVector<double> feat4Added, QVector<double> feat5Added, QVector<double> noFixation)
{
    times = x_forAxis;
    feat1Add = feat1Added;
    feat2Add = feat2Added;
    feat3Add = feat3Added;
    feat4Add = feat4Added;
    feat5Add = feat5Added;
    nofixation = noFixation;
}

void resultsDialog::passFilename(QString fileName)
{
    file = fileName.section(".",0,0); //remove file extension
}

//function to find number of fixations logged as ones in QVector
//does not log as new fixation on the same object after no data collected
void resultsDialog::fixationNumberFinder()
{
    int feat = 0;
    fixation1 = 0;
    fixation2 = 0;
    fixation3 = 0;
    fixation4 = 0;
    fixation5 = 0;

    for(int i = 0; i < times.size(); i++)
    {
        if(feat1Add[i] == 1 && (!(feat==1)))
        {
            fixation1++;
            feat = 1;
        }
        if(feat2Add[i] == 1 && (!(feat==2)))
        {
            fixation2++;
            feat = 2;
        }
        if(!Feat3.isEmpty() && feat3Add[i] == 1 && (!(feat==3)))
        {
            fixation3++;
            feat = 3;
        }
        if(!Feat4.isEmpty() && feat4Add[i] == 1 && (!(feat==4)))
        {
            fixation4++;
            feat = 4;
        }
        if(!Feat5.isEmpty() && feat5Add[i] == 1 && (!(feat==5)))
        {
            fixation5++;
            feat = 5;
        }
    }
}

//function to find duration of fixations logged in QVector
double resultsDialog::fixationDurationFinder(QVector<double> inputVector)
{
    //find duration of fixation on each feature
    double duration = 0;

    for(int i = 0; i < inputVector.size(); i++)
    {
        if(inputVector[i] == 1)
        {
            duration += times[0]; //use x_forAxis[0] as duration in seconds of one video frame
        }
    }

    return duration;
}

int resultsDialog::noFixationFinder(QVector<double> inputVector)
{
    bool fixation = false;
    int fixations = 0;

    //find single fixation at start
    if(inputVector.size()==1 && inputVector[0]==1)
    {
        fixations++;
    }

    //find clumps of fixations or subsequent single fixations later on
    for(int i = 0; i < inputVector.size(); i++)
    {
        if((inputVector[i] == inputVector[i+1] && inputVector[i] == 1)
            || (inputVector[i-1] == 0 && inputVector[i]==1)
            || (inputVector[i] == 1 && inputVector[i+1]==0))
        {
            if(!fixation)
            {
                fixation = true;
                fixations++;
            }
        }
        else
        {
            fixation = false;
        }
    }
    return fixations;
}

void resultsDialog::outcomeMeasures()
{
    fixationNumberFinder();

    double vidduration = 0;
    for(int i = 0; i < times.size(); i++)
    {
        vidduration += times[0];
    }

    setData1(Feat1, fixation1, fixationDurationFinder(feat1Add),
                fixationDurationFinder(feat1Add) / vidduration * 100);

    if(!Feat1.isEmpty())
    {
        setData2(Feat2, fixation2, fixationDurationFinder(feat2Add),
                fixationDurationFinder(feat2Add) / vidduration * 100);
    }
    if(!Feat3.isEmpty())
    {
        setData3(Feat3, fixation3, fixationDurationFinder(feat3Add),
                fixationDurationFinder(feat3Add) / vidduration * 100);
    }
    if(!Feat4.isEmpty())
    {
    setData4(Feat4, fixation4, fixationDurationFinder(feat4Add),
                fixationDurationFinder(feat4Add) / vidduration * 100);
    }
    if(!Feat5.isEmpty())
    {
    setData5(Feat5, fixation5, fixationDurationFinder(feat5Add),
                fixationDurationFinder(feat5Add) / vidduration * 100);
    }
    setNoFixation(noFixationFinder(nofixation), fixationDurationFinder(nofixation),
                fixationDurationFinder(nofixation) / vidduration * 100);
}

void resultsDialog::setData1(QString feat1, int fixations1, double durations1, double percentage1)
{
    ui->tableWidget->verticalHeaderItem(0)->setText(feat1);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem(QString::number(fixations1, 'g', 3)));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem(QString::number(durations1, 'f', 2)));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem(QString::number((int)percentage1)));
}

void resultsDialog::setData2(QString feat2, int fixations2, double durations2, double percentage2)
{
    ui->tableWidget->verticalHeaderItem(1)->setText(feat2);
    ui->tableWidget->setItem(1,0, new QTableWidgetItem(QString::number(fixations2, 'g', 3)));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem(QString::number(durations2, 'f', 2)));
    ui->tableWidget->setItem(1,2, new QTableWidgetItem(QString::number((int)percentage2)));
}

void resultsDialog::setData3(QString feat3, int fixations3, double durations3, double percentage3)
{
    ui->tableWidget->verticalHeaderItem(2)->setText(feat3);
    ui->tableWidget->setItem(2,0, new QTableWidgetItem(QString::number(fixations3, 'g', 3)));
    ui->tableWidget->setItem(2,1, new QTableWidgetItem(QString::number(durations3, 'f', 2)));
    ui->tableWidget->setItem(2,2, new QTableWidgetItem(QString::number((int)percentage3)));
}

void resultsDialog::setData4(QString feat4, int fixations4, double durations4, double percentage4)
{
    ui->tableWidget->verticalHeaderItem(3)->setText(feat4);
    ui->tableWidget->setItem(3,0, new QTableWidgetItem(QString::number(fixations4, 'g', 3)));
    ui->tableWidget->setItem(3,1, new QTableWidgetItem(QString::number(durations4, 'f', 2)));
    ui->tableWidget->setItem(3,2, new QTableWidgetItem(QString::number((int)percentage4)));
}

void resultsDialog::setData5(QString feat5, int fixations5, double durations5, double percentage5)
{
    ui->tableWidget->verticalHeaderItem(4)->setText(feat5);
    ui->tableWidget->setItem(4,0, new QTableWidgetItem(QString::number(fixations5, 'g', 3)));
    ui->tableWidget->setItem(4,1, new QTableWidgetItem(QString::number(durations5, 'f', 2)));
    ui->tableWidget->setItem(4,2, new QTableWidgetItem(QString::number((int)percentage5)));
}

void resultsDialog::setNoFixation(int noFixation, double noDur, double noPercentage)
{
    ui->tableWidget->setItem(5,0, new QTableWidgetItem(QString::number(noFixation, 'g', 3)));
    ui->tableWidget->setItem(5,1, new QTableWidgetItem(QString::number(noDur, 'f', 2)));
    ui->tableWidget->setItem(5,2, new QTableWidgetItem(QString::number((int)noPercentage)));
}

void resultsDialog::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save results"), file,
                                                          tr("Text files (*.txt)"));

    if(!filename.isEmpty())
    {
        //Save outcome variables
        QFile fileResults(filename + "_" + "results");

        if(!fileResults.open(QIODevice::WriteOnly))
        {

        }
        else
        {
            QTextStream results(&fileResults);
            QStringList strList;

            int rows = ui->tableWidget->rowCount();

            for (int row = 0; row < rows; row++)
            {
                strList.clear();

                QTableWidgetItem* item1 = ui->tableWidget->item(row, 0);
                //QTableWidgetItem* item2 = ui->tableWidget->item(row, 1);

                if (!item1)// || !item2)
                {
                    ui->tableWidget->verticalHeaderItem(row)->setText("");
                    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(""));
                    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(""));
                    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(""));
                }

                strList << ui->tableWidget->verticalHeaderItem(row)-> data(Qt::DisplayRole).toString() + "   "
                                + ui->tableWidget->item(row, 0)->text() + "   "
                                + ui->tableWidget->item(row, 1)->text() + "   "
                                + ui->tableWidget->item(row, 2)->text();

                results << strList.join( ";" ) + "\n";
            }
            fileResults.close();
        }

        //save raw data if required (checked by default)
        if(ui->rawBox->isChecked())
        {
            QFile fileRaw(filename + "_" + "raw"); //save raw data
            if(!fileRaw.open(QIODevice::WriteOnly))
            {
                //textBrowser->setText("Cancelled");
            }
            else
            {

                QTextStream out(&fileRaw);

                for( int i = 0; i < times.size(); i++)
                {
                    out << times[i] << "," << feat1Add[i] << "," << feat2Add[i]<< ","
                    << feat3Add[i]<< "," << feat4Add[i]<< "," << feat5Add[i]<< "," << nofixation[i] <<"\n";
                }
            }
            fileRaw.close();
            close();
        }
    }
}

void resultsDialog::on_cancelButton_clicked()
{
    close();
}
