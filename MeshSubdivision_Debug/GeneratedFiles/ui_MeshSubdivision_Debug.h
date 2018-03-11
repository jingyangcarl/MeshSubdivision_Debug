/********************************************************************************
** Form generated from reading UI file 'MeshSubdivision_Debug.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHSUBDIVISION_DEBUG_H
#define UI_MESHSUBDIVISION_DEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeshSubdivision_DebugClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_widget;
    QGridLayout *gridLayout_cmd;
    QTextEdit *textEdit_cmd;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MeshSubdivision_DebugClass)
    {
        if (MeshSubdivision_DebugClass->objectName().isEmpty())
            MeshSubdivision_DebugClass->setObjectName(QStringLiteral("MeshSubdivision_DebugClass"));
        MeshSubdivision_DebugClass->resize(727, 452);
        centralWidget = new QWidget(MeshSubdivision_DebugClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_widget = new QGridLayout();
        gridLayout_widget->setSpacing(6);
        gridLayout_widget->setObjectName(QStringLiteral("gridLayout_widget"));

        gridLayout->addLayout(gridLayout_widget, 0, 0, 1, 1);

        gridLayout_cmd = new QGridLayout();
        gridLayout_cmd->setSpacing(6);
        gridLayout_cmd->setObjectName(QStringLiteral("gridLayout_cmd"));
        textEdit_cmd = new QTextEdit(centralWidget);
        textEdit_cmd->setObjectName(QStringLiteral("textEdit_cmd"));
        textEdit_cmd->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_cmd->addWidget(textEdit_cmd, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_cmd, 0, 1, 1, 1);

        MeshSubdivision_DebugClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MeshSubdivision_DebugClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 727, 23));
        MeshSubdivision_DebugClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MeshSubdivision_DebugClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MeshSubdivision_DebugClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MeshSubdivision_DebugClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MeshSubdivision_DebugClass->setStatusBar(statusBar);

        retranslateUi(MeshSubdivision_DebugClass);

        QMetaObject::connectSlotsByName(MeshSubdivision_DebugClass);
    } // setupUi

    void retranslateUi(QMainWindow *MeshSubdivision_DebugClass)
    {
        MeshSubdivision_DebugClass->setWindowTitle(QApplication::translate("MeshSubdivision_DebugClass", "MeshSubdivision_Debug", 0));
    } // retranslateUi

};

namespace Ui {
    class MeshSubdivision_DebugClass: public Ui_MeshSubdivision_DebugClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHSUBDIVISION_DEBUG_H
