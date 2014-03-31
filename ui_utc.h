/********************************************************************************
** Form generated from reading UI file 'utc.ui'
**
** Created: Mon Mar 31 17:02:02 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTC_H
#define UI_UTC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_utc
{
public:
    QGridLayout *gridLayout;
    QLabel *label_a;
    QGroupBox *groupBox_a;
    QGridLayout *gridLayout_2;
    QRadioButton *a0;
    QRadioButton *a1;
    QRadioButton *a2;
    QLabel *label_b;
    QGroupBox *groupBox_b;
    QGridLayout *gridLayout_3;
    QRadioButton *b0;
    QRadioButton *b1;
    QRadioButton *b2;
    QLabel *label_c;
    QGroupBox *groupBox_c;
    QGridLayout *gridLayout_4;
    QRadioButton *c0;
    QRadioButton *c1;
    QRadioButton *c2;
    QLabel *label_d;
    QGroupBox *groupBox_d;
    QGridLayout *gridLayout_5;
    QRadioButton *d0;
    QRadioButton *d1;
    QRadioButton *d2;
    QLabel *num_question;
    QSpinBox *test_no;
    QLabel *label;
    QLabel *total;
    QLabel *quest;
    QLabel *label_3;
    QLabel *label_2;
    QSpinBox *exam_max;
    QSpacerItem *horizontalSpacer;
    QLabel *aplus;
    QLabel *bplus;
    QLabel *cplus;
    QLabel *dplus;
    QPushButton *load;
    QSpinBox *quest_no;
    QPushButton *save;
    QLabel *exam;
    QLabel *label_4;
    QPushButton *calc;

    void setupUi(QDialog *utc)
    {
        if (utc->objectName().isEmpty())
            utc->setObjectName(QString::fromUtf8("utc"));
        utc->resize(234, 371);
        utc->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(utc);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_a = new QLabel(utc);
        label_a->setObjectName(QString::fromUtf8("label_a"));
        label_a->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_a, 2, 1, 1, 1);

        groupBox_a = new QGroupBox(utc);
        groupBox_a->setObjectName(QString::fromUtf8("groupBox_a"));
        groupBox_a->setMinimumSize(QSize(138, 0));
        gridLayout_2 = new QGridLayout(groupBox_a);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        a0 = new QRadioButton(groupBox_a);
        a0->setObjectName(QString::fromUtf8("a0"));
        a0->setChecked(true);

        gridLayout_2->addWidget(a0, 0, 0, 1, 1);

        a1 = new QRadioButton(groupBox_a);
        a1->setObjectName(QString::fromUtf8("a1"));

        gridLayout_2->addWidget(a1, 0, 1, 1, 1);

        a2 = new QRadioButton(groupBox_a);
        a2->setObjectName(QString::fromUtf8("a2"));

        gridLayout_2->addWidget(a2, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_a, 2, 3, 1, 3);

        label_b = new QLabel(utc);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_b, 3, 1, 1, 1);

        groupBox_b = new QGroupBox(utc);
        groupBox_b->setObjectName(QString::fromUtf8("groupBox_b"));
        groupBox_b->setMinimumSize(QSize(138, 0));
        gridLayout_3 = new QGridLayout(groupBox_b);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        b0 = new QRadioButton(groupBox_b);
        b0->setObjectName(QString::fromUtf8("b0"));
        b0->setChecked(true);

        gridLayout_3->addWidget(b0, 0, 0, 1, 1);

        b1 = new QRadioButton(groupBox_b);
        b1->setObjectName(QString::fromUtf8("b1"));

        gridLayout_3->addWidget(b1, 0, 1, 1, 1);

        b2 = new QRadioButton(groupBox_b);
        b2->setObjectName(QString::fromUtf8("b2"));

        gridLayout_3->addWidget(b2, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_b, 3, 3, 1, 3);

        label_c = new QLabel(utc);
        label_c->setObjectName(QString::fromUtf8("label_c"));
        label_c->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_c, 4, 1, 1, 1);

        groupBox_c = new QGroupBox(utc);
        groupBox_c->setObjectName(QString::fromUtf8("groupBox_c"));
        groupBox_c->setMinimumSize(QSize(144, 0));
        gridLayout_4 = new QGridLayout(groupBox_c);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        c0 = new QRadioButton(groupBox_c);
        c0->setObjectName(QString::fromUtf8("c0"));
        c0->setChecked(true);

        gridLayout_4->addWidget(c0, 0, 0, 1, 1);

        c1 = new QRadioButton(groupBox_c);
        c1->setObjectName(QString::fromUtf8("c1"));

        gridLayout_4->addWidget(c1, 0, 1, 1, 1);

        c2 = new QRadioButton(groupBox_c);
        c2->setObjectName(QString::fromUtf8("c2"));
        c2->setMinimumSize(QSize(35, 0));

        gridLayout_4->addWidget(c2, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_c, 4, 3, 1, 3);

        label_d = new QLabel(utc);
        label_d->setObjectName(QString::fromUtf8("label_d"));
        label_d->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_d, 5, 1, 1, 1);

        groupBox_d = new QGroupBox(utc);
        groupBox_d->setObjectName(QString::fromUtf8("groupBox_d"));
        groupBox_d->setMinimumSize(QSize(138, 0));
        gridLayout_5 = new QGridLayout(groupBox_d);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        d0 = new QRadioButton(groupBox_d);
        d0->setObjectName(QString::fromUtf8("d0"));
        d0->setChecked(true);

        gridLayout_5->addWidget(d0, 0, 0, 1, 1);

        d1 = new QRadioButton(groupBox_d);
        d1->setObjectName(QString::fromUtf8("d1"));

        gridLayout_5->addWidget(d1, 0, 1, 1, 1);

        d2 = new QRadioButton(groupBox_d);
        d2->setObjectName(QString::fromUtf8("d2"));

        gridLayout_5->addWidget(d2, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_d, 5, 3, 1, 3);

        num_question = new QLabel(utc);
        num_question->setObjectName(QString::fromUtf8("num_question"));
        num_question->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(num_question, 0, 1, 1, 1);

        test_no = new QSpinBox(utc);
        test_no->setObjectName(QString::fromUtf8("test_no"));
        test_no->setMinimum(1000);
        test_no->setMaximum(9999);
        test_no->setValue(1000);

        gridLayout->addWidget(test_no, 0, 3, 1, 1);

        label = new QLabel(utc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 6, 1, 1, 1);

        total = new QLabel(utc);
        total->setObjectName(QString::fromUtf8("total"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(30);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(total->sizePolicy().hasHeightForWidth());
        total->setSizePolicy(sizePolicy);
        total->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(total, 6, 3, 1, 1);

        quest = new QLabel(utc);
        quest->setObjectName(QString::fromUtf8("quest"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(30);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(quest->sizePolicy().hasHeightForWidth());
        quest->setSizePolicy(sizePolicy1);
        quest->setMaximumSize(QSize(26, 16777215));

        gridLayout->addWidget(quest, 6, 5, 1, 1);

        label_3 = new QLabel(utc);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 4, 1, 1);

        label_2 = new QLabel(utc);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 8, 1, 1, 1);

        exam_max = new QSpinBox(utc);
        exam_max->setObjectName(QString::fromUtf8("exam_max"));
        exam_max->setMinimum(10);

        gridLayout->addWidget(exam_max, 8, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        aplus = new QLabel(utc);
        aplus->setObjectName(QString::fromUtf8("aplus"));

        gridLayout->addWidget(aplus, 2, 6, 1, 1);

        bplus = new QLabel(utc);
        bplus->setObjectName(QString::fromUtf8("bplus"));

        gridLayout->addWidget(bplus, 3, 6, 1, 1);

        cplus = new QLabel(utc);
        cplus->setObjectName(QString::fromUtf8("cplus"));

        gridLayout->addWidget(cplus, 4, 6, 1, 1);

        dplus = new QLabel(utc);
        dplus->setObjectName(QString::fromUtf8("dplus"));

        gridLayout->addWidget(dplus, 5, 6, 1, 1);

        load = new QPushButton(utc);
        load->setObjectName(QString::fromUtf8("load"));

        gridLayout->addWidget(load, 9, 3, 1, 1);

        quest_no = new QSpinBox(utc);
        quest_no->setObjectName(QString::fromUtf8("quest_no"));
        quest_no->setMinimum(1);

        gridLayout->addWidget(quest_no, 0, 4, 1, 1);

        save = new QPushButton(utc);
        save->setObjectName(QString::fromUtf8("save"));

        gridLayout->addWidget(save, 9, 4, 1, 1);

        exam = new QLabel(utc);
        exam->setObjectName(QString::fromUtf8("exam"));

        gridLayout->addWidget(exam, 8, 5, 1, 1);

        label_4 = new QLabel(utc);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 8, 4, 1, 1);

        calc = new QPushButton(utc);
        calc->setObjectName(QString::fromUtf8("calc"));

        gridLayout->addWidget(calc, 10, 3, 1, 2);


        retranslateUi(utc);

        QMetaObject::connectSlotsByName(utc);
    } // setupUi

    void retranslateUi(QDialog *utc)
    {
        utc->setWindowTitle(QApplication::translate("utc", "Test checker, v.1.1, 5.02.2014", 0, QApplication::UnicodeUTF8));
        label_a->setText(QApplication::translate("utc", "a)", 0, QApplication::UnicodeUTF8));
        groupBox_a->setTitle(QApplication::translate("utc", "a", 0, QApplication::UnicodeUTF8));
        a0->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        a1->setText(QApplication::translate("utc", "yes", 0, QApplication::UnicodeUTF8));
        a2->setText(QApplication::translate("utc", "no", 0, QApplication::UnicodeUTF8));
        label_b->setText(QApplication::translate("utc", "b)", 0, QApplication::UnicodeUTF8));
        groupBox_b->setTitle(QApplication::translate("utc", "b", 0, QApplication::UnicodeUTF8));
        b0->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        b1->setText(QApplication::translate("utc", "yes", 0, QApplication::UnicodeUTF8));
        b2->setText(QApplication::translate("utc", "no", 0, QApplication::UnicodeUTF8));
        label_c->setText(QApplication::translate("utc", "c)", 0, QApplication::UnicodeUTF8));
        groupBox_c->setTitle(QApplication::translate("utc", "c", 0, QApplication::UnicodeUTF8));
        c0->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        c1->setText(QApplication::translate("utc", "yes", 0, QApplication::UnicodeUTF8));
        c2->setText(QApplication::translate("utc", "no", 0, QApplication::UnicodeUTF8));
        label_d->setText(QApplication::translate("utc", "d)", 0, QApplication::UnicodeUTF8));
        groupBox_d->setTitle(QApplication::translate("utc", "d", 0, QApplication::UnicodeUTF8));
        d0->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        d1->setText(QApplication::translate("utc", "yes", 0, QApplication::UnicodeUTF8));
        d2->setText(QApplication::translate("utc", "no", 0, QApplication::UnicodeUTF8));
        num_question->setText(QApplication::translate("utc", "Test", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("utc", "Total", 0, QApplication::UnicodeUTF8));
        total->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        quest->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("utc", "   Quest", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("utc", "Exam", 0, QApplication::UnicodeUTF8));
        aplus->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        bplus->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        cplus->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        dplus->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("utc", "Load", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("utc", "Save", 0, QApplication::UnicodeUTF8));
        exam->setText(QApplication::translate("utc", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("utc", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">   Points</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        calc->setText(QApplication::translate("utc", "Calculate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class utc: public Ui_utc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTC_H
