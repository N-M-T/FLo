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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include <QMessageBox>
#include <QTime>
#include <QString>

#include <QKeyEvent>
#include <QApplication>

#include "player.h"
#include "featuredialog.h"
#include "resultsdialog.h"
#include "qcustomplot.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString feat1;
    QString feat2;
    QString feat3;
    QString feat4;
    QString feat5;
    int length;
    int frames;
    int fps;
    QString filename;
    QFileInfo name;

    QVector<double> x_forAxis, featNoAdded, feat1Added, feat2Added, feat3Added, feat4Added, feat5Added;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Display video frame in player UI
    void updatePlayerUI(QImage img);

    void on_actionOpen_triggered();

    void load_refreshVideo();

    void on_play_pauseButton_clicked();

    void on_stopButton_clicked();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_reloadButton_clicked();

    void seek(int value);

    void isSliderPressed();

    void on_actionEnterFeatures_triggered();

    void resultsEnable();

    void on_actionBasic_triggered();

    QString getFormattedTime(double timeInSeconds);

public slots:
    void updateFeatures(const featureStruct features);//QString feature1);

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;

    Player* myPlayer;

    featureDialog *myFeatures;

    resultsDialog *myResultsDialog;
};

#endif // MAINWINDOW_H
