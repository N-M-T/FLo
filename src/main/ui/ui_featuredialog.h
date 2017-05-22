/********************************************************************************
** Form generated from reading UI file 'featuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATUREDIALOG_H
#define UI_FEATUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_featureDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *a;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *b;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *c;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *d;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *e;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QWidget *featureDialog)
    {
        if (featureDialog->objectName().isEmpty())
            featureDialog->setObjectName(QStringLiteral("featureDialog"));
        featureDialog->resize(136, 236);
        QIcon icon;
        icon.addFile(QStringLiteral("gibbon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        featureDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(featureDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(featureDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        a = new QLineEdit(frame);
        a->setObjectName(QStringLiteral("a"));
        a->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_6->addWidget(a);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        b = new QLineEdit(frame);
        b->setObjectName(QStringLiteral("b"));
        b->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_5->addWidget(b);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        c = new QLineEdit(frame);
        c->setObjectName(QStringLiteral("c"));
        c->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_4->addWidget(c);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        d = new QLineEdit(frame);
        d->setObjectName(QStringLiteral("d"));
        d->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(d);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        e = new QLineEdit(frame);
        e->setObjectName(QStringLiteral("e"));
        e->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(e);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okButton = new QPushButton(frame);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(featureDialog);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(featureDialog);
    } // setupUi

    void retranslateUi(QWidget *featureDialog)
    {
        label_6->setText(QApplication::translate("featureDialog", "Features", 0));
        label->setText(QApplication::translate("featureDialog", "1:", 0));
        label_2->setText(QApplication::translate("featureDialog", "2:", 0));
        label_3->setText(QApplication::translate("featureDialog", "3:", 0));
        label_4->setText(QApplication::translate("featureDialog", "4:", 0));
        label_5->setText(QApplication::translate("featureDialog", "5:", 0));
        okButton->setText(QApplication::translate("featureDialog", "Ok", 0));
        Q_UNUSED(featureDialog);
    } // retranslateUi

};

namespace Ui {
    class featureDialog: public Ui_featureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATUREDIALOG_H
