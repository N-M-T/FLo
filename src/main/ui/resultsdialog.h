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
    QVector<double> times, feat1Add, feat2Add, feat3Add, feat4Add, feat5Add;
    QString file;

public:
    explicit resultsDialog(QWidget *parent = 0);
    ~resultsDialog();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

public slots:
    void passVectors(QVector<double> x_forAxis, QVector<double> feat1Added, QVector<double> feat2Added,
                    QVector<double> feat3Added, QVector<double> feat4Added, QVector<double> feat5Added);

    void outcomeMeasures(QString feat1, QString feat2, QString feat3, QString feat4, QString feat5);

    void passFilename(QString fileName);

    int fixationNumberFinder(QVector<double> inputVector);

    double fixationDurationFinder(QVector<double> inputVector);

    void setData1(QString feat1, int fix1, double dur1);
    void setData2(QString feat2, int fix2, double dur2);
    void setData3(QString feat3, int fix3, double dur3);
    void setData4(QString feat4, int fix4, double dur4);
    void setData5(QString feat5, int fix5, double dur5);

private:
    Ui::resultsDialog *ui;
};

#endif // RESULTSDIALOG_H
