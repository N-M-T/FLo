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

#include "featuredialog.h"
#include "ui_featuredialog.h"

featureDialog::featureDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::featureDialog)
{
    ui->setupUi(this);

    ui->b->setDisabled(true);
    ui->c->setDisabled(true);
    ui->d->setDisabled(true);
    ui->e->setDisabled(true);

    connect(ui->a, SIGNAL(textChanged(QString)), this, SLOT(aChanged()));
    connect(ui->b, SIGNAL(textChanged(QString)), this, SLOT(bChanged()));
    connect(ui->c, SIGNAL(textChanged(QString)), this, SLOT(cChanged()));
    connect(ui->d, SIGNAL(textChanged(QString)), this, SLOT(dChanged()));
}

featureDialog::~featureDialog()
{
    delete ui;
}

void featureDialog::setFeatures(QString feat1, QString feat2, QString feat3, QString feat4, QString feat5)
{
    ui->a->setText(feat1);
    ui->b->setText(feat2);
    ui->c->setText(feat3);
    ui->d->setText(feat4);
    ui->e->setText(feat5);
}

void featureDialog::aChanged()
{
    if(ui->a->text().isEmpty())
    {
        ui->b->setDisabled(true);
    }
    else
    {
        ui->b->setEnabled(true);
    }
}

void featureDialog::bChanged()
{
    if(ui->b->text().isEmpty())
    {
        ui->c->setDisabled(true);
    }
    else
    {
        ui->c->setEnabled(true);
    }
}

void featureDialog::cChanged()
{
    if(ui->c->text().isEmpty())
    {
        ui->d->setDisabled(true);
    }
    else
    {
        ui->d->setEnabled(true);
    }
}

void featureDialog::dChanged()
{
    if(ui->d->text().isEmpty())
    {
        ui->e->setDisabled(true);
    }
    else
    {
        ui->e->setEnabled(true);
    }
}

void featureDialog::on_okButton_clicked()
{
    //emit string1(ui->a->text());
    featureStruct features;
    features.feature1 = ui->a->text();
    features.feature2 = ui->b->text();
    features.feature3 = ui->c->text();
    features.feature4 = ui->d->text();
    features.feature5 = ui->e->text();

    emit sendFeatures(features);
    /*
    if(!features.feature1.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Slider and play button are now deactivated. Moving through the video will now add or delete fixation data.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    */
    close();
}
