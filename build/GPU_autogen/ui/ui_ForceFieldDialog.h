/********************************************************************************
** Form generated from reading UI file 'ForceFieldDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORCEFIELDDIALOG_H
#define UI_FORCEFIELDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForceFieldDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpinBox *height;
    QSpinBox *spinBox_2;
    QSlider *forceSlider;

    void setupUi(QDialog *ForceFieldDialog)
    {
        if (ForceFieldDialog->objectName().isEmpty())
            ForceFieldDialog->setObjectName(QStringLiteral("ForceFieldDialog"));
        ForceFieldDialog->resize(573, 319);
        buttonBox = new QDialogButtonBox(ForceFieldDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 250, 551, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        verticalLayoutWidget = new QWidget(ForceFieldDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(190, 120, 178, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 30));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        height = new QSpinBox(verticalLayoutWidget);
        height->setObjectName(QStringLiteral("height"));

        horizontalLayout->addWidget(height);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout);

        forceSlider = new QSlider(verticalLayoutWidget);
        forceSlider->setObjectName(QStringLiteral("forceSlider"));
        forceSlider->setMaximumSize(QSize(300, 16777215));
        forceSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(forceSlider);


        retranslateUi(ForceFieldDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ForceFieldDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ForceFieldDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ForceFieldDialog);
    } // setupUi

    void retranslateUi(QDialog *ForceFieldDialog)
    {
        ForceFieldDialog->setWindowTitle(QApplication::translate("ForceFieldDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ForceFieldDialog", "Width x Height", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ForceFieldDialog: public Ui_ForceFieldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORCEFIELDDIALOG_H
