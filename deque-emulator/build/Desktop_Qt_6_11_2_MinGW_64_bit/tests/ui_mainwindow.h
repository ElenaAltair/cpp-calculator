/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *txt_elem_content;
    QPushButton *btn_edit;
    QPushButton *btn_find;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *le_count;
    QPushButton *btn_count;
    QLabel *lbl_count;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *btn_pop_front;
    QPushButton *btn_push_front;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btn_pop_back;
    QPushButton *btn_push_back;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_erase;
    QPushButton *btn_insert;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *btn_clear;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *btn_min_element;
    QPushButton *btn_max_element;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *btn_sort;
    QPushButton *btn_sOrT;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *btn_unique;
    QPushButton *btn_reverse;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *btn_shuffle;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *btn_lower_bound;
    QPushButton *btn_upper_bound;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_dec_iterator;
    QPushButton *btn_inc_iterator;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btn_begin;
    QPushButton *btn_end;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_tea;
    QPushButton *btn_cakes;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_3;
    QLineEdit *txt_size;
    QPushButton *btn_resize;
    QListWidget *list_widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(681, 631);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(310, 10, 361, 611));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        txt_elem_content = new QLineEdit(verticalLayoutWidget);
        txt_elem_content->setObjectName("txt_elem_content");

        horizontalLayout_5->addWidget(txt_elem_content);

        btn_edit = new QPushButton(verticalLayoutWidget);
        btn_edit->setObjectName("btn_edit");

        horizontalLayout_5->addWidget(btn_edit);

        btn_find = new QPushButton(verticalLayoutWidget);
        btn_find->setObjectName("btn_find");

        horizontalLayout_5->addWidget(btn_find);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        le_count = new QLineEdit(verticalLayoutWidget);
        le_count->setObjectName("le_count");

        horizontalLayout_13->addWidget(le_count);

        btn_count = new QPushButton(verticalLayoutWidget);
        btn_count->setObjectName("btn_count");

        horizontalLayout_13->addWidget(btn_count);

        lbl_count = new QLabel(verticalLayoutWidget);
        lbl_count->setObjectName("lbl_count");

        horizontalLayout_13->addWidget(lbl_count);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout_6->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        btn_pop_front = new QPushButton(verticalLayoutWidget);
        btn_pop_front->setObjectName("btn_pop_front");

        horizontalLayout_19->addWidget(btn_pop_front);

        btn_push_front = new QPushButton(verticalLayoutWidget);
        btn_push_front->setObjectName("btn_push_front");

        horizontalLayout_19->addWidget(btn_push_front);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btn_pop_back = new QPushButton(verticalLayoutWidget);
        btn_pop_back->setObjectName("btn_pop_back");

        horizontalLayout_7->addWidget(btn_pop_back);

        btn_push_back = new QPushButton(verticalLayoutWidget);
        btn_push_back->setObjectName("btn_push_back");

        horizontalLayout_7->addWidget(btn_push_back);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btn_erase = new QPushButton(verticalLayoutWidget);
        btn_erase->setObjectName("btn_erase");

        horizontalLayout_2->addWidget(btn_erase);

        btn_insert = new QPushButton(verticalLayoutWidget);
        btn_insert->setObjectName("btn_insert");

        horizontalLayout_2->addWidget(btn_insert);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        btn_clear = new QPushButton(verticalLayoutWidget);
        btn_clear->setObjectName("btn_clear");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_clear->sizePolicy().hasHeightForWidth());
        btn_clear->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(btn_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_14->addWidget(label_7);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        btn_min_element = new QPushButton(verticalLayoutWidget);
        btn_min_element->setObjectName("btn_min_element");

        horizontalLayout_15->addWidget(btn_min_element);

        btn_max_element = new QPushButton(verticalLayoutWidget);
        btn_max_element->setObjectName("btn_max_element");

        horizontalLayout_15->addWidget(btn_max_element);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        btn_sort = new QPushButton(verticalLayoutWidget);
        btn_sort->setObjectName("btn_sort");

        horizontalLayout_16->addWidget(btn_sort);

        btn_sOrT = new QPushButton(verticalLayoutWidget);
        btn_sOrT->setObjectName("btn_sOrT");

        horizontalLayout_16->addWidget(btn_sOrT);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        btn_unique = new QPushButton(verticalLayoutWidget);
        btn_unique->setObjectName("btn_unique");

        horizontalLayout_17->addWidget(btn_unique);

        btn_reverse = new QPushButton(verticalLayoutWidget);
        btn_reverse->setObjectName("btn_reverse");

        horizontalLayout_17->addWidget(btn_reverse);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        btn_shuffle = new QPushButton(verticalLayoutWidget);
        btn_shuffle->setObjectName("btn_shuffle");
        sizePolicy.setHeightForWidth(btn_shuffle->sizePolicy().hasHeightForWidth());
        btn_shuffle->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(btn_shuffle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        btn_lower_bound = new QPushButton(verticalLayoutWidget);
        btn_lower_bound->setObjectName("btn_lower_bound");

        horizontalLayout_20->addWidget(btn_lower_bound);

        btn_upper_bound = new QPushButton(verticalLayoutWidget);
        btn_upper_bound->setObjectName("btn_upper_bound");

        horizontalLayout_20->addWidget(btn_upper_bound);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btn_dec_iterator = new QPushButton(verticalLayoutWidget);
        btn_dec_iterator->setObjectName("btn_dec_iterator");

        horizontalLayout_4->addWidget(btn_dec_iterator);

        btn_inc_iterator = new QPushButton(verticalLayoutWidget);
        btn_inc_iterator->setObjectName("btn_inc_iterator");

        horizontalLayout_4->addWidget(btn_inc_iterator);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        btn_begin = new QPushButton(verticalLayoutWidget);
        btn_begin->setObjectName("btn_begin");

        horizontalLayout_10->addWidget(btn_begin);

        btn_end = new QPushButton(verticalLayoutWidget);
        btn_end->setObjectName("btn_end");

        horizontalLayout_10->addWidget(btn_end);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_8->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        btn_tea = new QPushButton(verticalLayoutWidget);
        btn_tea->setObjectName("btn_tea");

        horizontalLayout_9->addWidget(btn_tea);

        btn_cakes = new QPushButton(verticalLayoutWidget);
        btn_cakes->setObjectName("btn_cakes");

        horizontalLayout_9->addWidget(btn_cakes);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_11->addWidget(label_3);

        txt_size = new QLineEdit(verticalLayoutWidget);
        txt_size->setObjectName("txt_size");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txt_size->sizePolicy().hasHeightForWidth());
        txt_size->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(txt_size);

        btn_resize = new QPushButton(verticalLayoutWidget);
        btn_resize->setObjectName("btn_resize");

        horizontalLayout_11->addWidget(btn_resize);


        verticalLayout_3->addLayout(horizontalLayout_11);

        list_widget = new QListWidget(centralwidget);
        list_widget->setObjectName("list_widget");
        list_widget->setGeometry(QRect(10, 10, 291, 611));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "std::vector demo", nullptr));
        btn_edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        btn_find->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        btn_count->setText(QCoreApplication::translate("MainWindow", "count", nullptr));
        lbl_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264\321\213", nullptr));
        btn_pop_front->setText(QCoreApplication::translate("MainWindow", "pop_front", nullptr));
        btn_push_front->setText(QCoreApplication::translate("MainWindow", "push_front", nullptr));
        btn_pop_back->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
        btn_push_back->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        btn_erase->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        btn_insert->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213", nullptr));
        btn_min_element->setText(QCoreApplication::translate("MainWindow", "min_element", nullptr));
        btn_max_element->setText(QCoreApplication::translate("MainWindow", "max_element", nullptr));
        btn_sort->setText(QCoreApplication::translate("MainWindow", "merge sort", nullptr));
        btn_sOrT->setText(QCoreApplication::translate("MainWindow", "merge sOrT", nullptr));
        btn_unique->setText(QCoreApplication::translate("MainWindow", "unique", nullptr));
        btn_reverse->setText(QCoreApplication::translate("MainWindow", "reverse", nullptr));
        btn_shuffle->setText(QCoreApplication::translate("MainWindow", "shuffle", nullptr));
        btn_lower_bound->setText(QCoreApplication::translate("MainWindow", "lower_bound", nullptr));
        btn_upper_bound->setText(QCoreApplication::translate("MainWindow", "upper_bound", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\230\321\202\320\265\321\200\320\260\321\202\320\276\321\200\321\213", nullptr));
        btn_dec_iterator->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        btn_inc_iterator->setText(QCoreApplication::translate("MainWindow", "++", nullptr));
        btn_begin->setText(QCoreApplication::translate("MainWindow", "begin", nullptr));
        btn_end->setText(QCoreApplication::translate("MainWindow", "end", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\276\321\202\320\276\320\262\320\272\320\270", nullptr));
        btn_tea->setText(QCoreApplication::translate("MainWindow", "= \321\207\320\260\320\271", nullptr));
        btn_cakes->setText(QCoreApplication::translate("MainWindow", "= \321\202\320\276\321\200\321\202\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "size():", nullptr));
        btn_resize->setText(QCoreApplication::translate("MainWindow", "resize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
