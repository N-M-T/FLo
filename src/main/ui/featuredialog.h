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

#ifndef FEATUREDIALOG_H
#define FEATUREDIALOG_H

#include <QWidget>
#include <QString>
#include <QMessageBox>

namespace Ui {
class featureDialog;
}

struct featureStruct
{
    QString feature1;
    QString feature2;
    QString feature3;
    QString feature4;
    QString feature5;
};

Q_DECLARE_METATYPE(featureStruct);

class featureDialog : public QWidget
{
    Q_OBJECT

public:
    explicit featureDialog(QWidget *parent = 0);
    ~featureDialog();

signals:
    //void string1(QString feature1);
    void sendFeatures(const featureStruct features);

private slots:
    void on_okButton_clicked();

public slots:
    void setFeatures(QString feat1, QString feat2, QString feat3, QString feat4, QString feat5);
    void aChanged();
    void bChanged();
    void cChanged();
    void dChanged();

private:
    Ui::featureDialog *ui;
};

#endif // FEATUREDIALOG_H
