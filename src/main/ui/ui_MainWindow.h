/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *actionScaleToFitFrame;
    QAction *actionFullScreen;
    QAction *actionOpen;
    QAction *actionSet_Codec;
    QAction *actionAbout_Qt;
    QAction *actionHelp;
    QAction *actionAboutQt;
    QAction *actionEnterFeatures;
    QAction *actionBasic;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *videoFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *video;
    QHBoxLayout *horizontalLayout_3;
    QLabel *startLabel;
    QSlider *horizontalSlider;
    QLabel *endLabel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *stopButton;
    QToolButton *leftButton;
    QToolButton *play_pauseButton;
    QToolButton *rightButton;
    QToolButton *reloadButton;
    QSpacerItem *horizontalSpacer;
    QLabel *frameLabel;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *feat1Lab;
    QLabel *feat2Lab;
    QLabel *feat3Lab;
    QLabel *feat4Lab;
    QLabel *feat5Lab;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuFeatures;
    QMenu *menuResults;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 519);
        MainWindow->setMinimumSize(QSize(0, 0));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionScaleToFitFrame = new QAction(MainWindow);
        actionScaleToFitFrame->setObjectName(QStringLiteral("actionScaleToFitFrame"));
        actionScaleToFitFrame->setCheckable(true);
        actionFullScreen = new QAction(MainWindow);
        actionFullScreen->setObjectName(QStringLiteral("actionFullScreen"));
        actionFullScreen->setCheckable(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSet_Codec = new QAction(MainWindow);
        actionSet_Codec->setObjectName(QStringLiteral("actionSet_Codec"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionEnterFeatures = new QAction(MainWindow);
        actionEnterFeatures->setObjectName(QStringLiteral("actionEnterFeatures"));
        actionBasic = new QAction(MainWindow);
        actionBasic->setObjectName(QStringLiteral("actionBasic"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        videoFrame = new QFrame(centralWidget);
        videoFrame->setObjectName(QStringLiteral("videoFrame"));
        videoFrame->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoFrame->sizePolicy().hasHeightForWidth());
        videoFrame->setSizePolicy(sizePolicy);
        videoFrame->setMinimumSize(QSize(0, 0));
        videoFrame->setFrameShape(QFrame::StyledPanel);
        videoFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(videoFrame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        video = new QLabel(videoFrame);
        video->setObjectName(QStringLiteral("video"));
        sizePolicy.setHeightForWidth(video->sizePolicy().hasHeightForWidth());
        video->setSizePolicy(sizePolicy);
        video->setMinimumSize(QSize(600, 350));
        video->setMaximumSize(QSize(400, 16777215));
        video->setFrameShape(QFrame::Box);
        video->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(video);


        gridLayout->addWidget(videoFrame, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        startLabel = new QLabel(centralWidget);
        startLabel->setObjectName(QStringLiteral("startLabel"));

        horizontalLayout_3->addWidget(startLabel);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        endLabel = new QLabel(centralWidget);
        endLabel->setObjectName(QStringLiteral("endLabel"));

        horizontalLayout_3->addWidget(endLabel);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        stopButton = new QToolButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);

        horizontalLayout_4->addWidget(stopButton);

        leftButton = new QToolButton(centralWidget);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setEnabled(false);

        horizontalLayout_4->addWidget(leftButton);

        play_pauseButton = new QToolButton(centralWidget);
        play_pauseButton->setObjectName(QStringLiteral("play_pauseButton"));
        play_pauseButton->setEnabled(false);

        horizontalLayout_4->addWidget(play_pauseButton);

        rightButton = new QToolButton(centralWidget);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setEnabled(false);

        horizontalLayout_4->addWidget(rightButton);

        reloadButton = new QToolButton(centralWidget);
        reloadButton->setObjectName(QStringLiteral("reloadButton"));

        horizontalLayout_4->addWidget(reloadButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        frameLabel = new QLabel(centralWidget);
        frameLabel->setObjectName(QStringLiteral("frameLabel"));

        horizontalLayout_4->addWidget(frameLabel);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout_2->addWidget(textBrowser);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        feat1Lab = new QLabel(centralWidget);
        feat1Lab->setObjectName(QStringLiteral("feat1Lab"));

        verticalLayout_2->addWidget(feat1Lab);

        feat2Lab = new QLabel(centralWidget);
        feat2Lab->setObjectName(QStringLiteral("feat2Lab"));

        verticalLayout_2->addWidget(feat2Lab);

        feat3Lab = new QLabel(centralWidget);
        feat3Lab->setObjectName(QStringLiteral("feat3Lab"));

        verticalLayout_2->addWidget(feat3Lab);

        feat4Lab = new QLabel(centralWidget);
        feat4Lab->setObjectName(QStringLiteral("feat4Lab"));

        verticalLayout_2->addWidget(feat4Lab);

        feat5Lab = new QLabel(centralWidget);
        feat5Lab->setObjectName(QStringLiteral("feat5Lab"));

        verticalLayout_2->addWidget(feat5Lab);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        videoFrame->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFeatures = new QMenu(menuBar);
        menuFeatures->setObjectName(QStringLiteral("menuFeatures"));
        menuResults = new QMenu(menuBar);
        menuResults->setObjectName(QStringLiteral("menuResults"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuFeatures->menuAction());
        menuBar->addAction(menuResults->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionQuit);
        menuFeatures->addAction(actionEnterFeatures);
        menuResults->addAction(actionBasic);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Video event logger", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About RVM", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionScaleToFitFrame->setText(QApplication::translate("MainWindow", "Scale to fit frame", 0));
        actionFullScreen->setText(QApplication::translate("MainWindow", "Full Screen", 0));
        actionFullScreen->setShortcut(QApplication::translate("MainWindow", "F11", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSet_Codec->setText(QApplication::translate("MainWindow", "Set Codec", 0));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionEnterFeatures->setText(QApplication::translate("MainWindow", "Enter features", 0));
        actionBasic->setText(QApplication::translate("MainWindow", "Basic", 0));
        video->setText(QString());
        startLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        endLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        stopButton->setText(QApplication::translate("MainWindow", "...", 0));
        leftButton->setText(QApplication::translate("MainWindow", "...", 0));
        play_pauseButton->setText(QApplication::translate("MainWindow", "...", 0));
        rightButton->setText(QApplication::translate("MainWindow", "...", 0));
        reloadButton->setText(QApplication::translate("MainWindow", "...", 0));
        frameLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        feat1Lab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        feat2Lab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        feat3Lab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        feat4Lab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        feat5Lab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuFeatures->setTitle(QApplication::translate("MainWindow", "Features", 0));
        menuResults->setTitle(QApplication::translate("MainWindow", "Analyse", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
