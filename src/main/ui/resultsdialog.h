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

#ifndef RESULTSDIALOG_H
#define RESULTSDIALOG_H

#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class resultsDialog;
}

class resultsDialog : public QWidget
{
    Q_OBJECT

private:
    QString Feat1;
    QString Feat2;
    QString Feat3;
    QString Feat4;
    QString Feat5;
    QVector<double> times, feat1Add, feat2Add, feat3Add, feat4Add, feat5Add, nofixation;
    double vidduration;
    QString file;
    int fixation1;
    int fixation2;
    int fixation3;
    int fixation4;
    int fixation5;

public:
    explicit resultsDialog(QWidget *parent = 0);
    ~resultsDialog();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

public slots:
    void passFeatures(QString feat1, QString feat2, QString feat3, QString feat4, QString feat5);
    void passVectors(QVector<double> x_forAxis, QVector<double> feat1Added, QVector<double> feat2Added,
                    QVector<double> feat3Added, QVector<double> feat4Added, QVector<double> feat5Added,
                    QVector<double>noFixation);

    void passFilename(QString fileName);

    void outcomeMeasures();

    void fixationNumberFinder();

    int noFixationFinder(QVector<double> inputVector);

    double fixationDurationFinder(QVector<double> inputVector);

    void setData1(QString feat1, int fix1, double dur1, double percentage1);
    void setData2(QString feat2, int fix2, double dur2, double percentage2);
    void setData3(QString feat3, int fix3, double dur3, double percentage3);
    void setData4(QString feat4, int fix4, double dur4, double percentage4);
    void setData5(QString feat5, int fix5, double dur5, double percentage5);
    void setNoFixation(int noFixation, double noDur, double noPercentage);

private:
    Ui::resultsDialog *ui;
};

#endif // RESULTSDIALOG_H
