#include "lab10_tnr.h"
#include "ui_lab10_tnr.h"

Lab10_TNR::Lab10_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab10_TNR)
{
    ui->setupUi(this);
    ui->randBtn_tnr->setIcon(QIcon(":/icons/dice.png"));
    String_TNR str1("looool");
    String_TNR str2("uwueuwu");
    strArr->Append(str1);
    strArr->Append(str2);
    UpdateList();
}

Lab10_TNR::~Lab10_TNR()
{
    delete polArr;
    delete strArr;
    delete ui;
}

void Lab10_TNR::on_addToEndBtn_tnr_pressed()
{
    if (mode == String_TNRs) {
        String_TNR str(ui->item_tnr->text());
        strArr->Append(str);
    } else {
        Polynom_TNR pol;
        pol.SetPolynom(ui->item_tnr->text());
        polArr->Append(pol);
    }
    UpdateList();
}

void Lab10_TNR::on_setAtBtn_tnr_clicked()
{
    int i = ui->posVal_tnr->value();
    if (mode == String_TNRs) {
        String_TNR str(ui->item_tnr->text());
        strArr->SetAt(i, str);
    } else {
        Polynom_TNR pol;
        pol.SetPolynom(ui->item_tnr->text());
        polArr->SetAt(i, pol);
    }
    UpdateList();
}

void Lab10_TNR::on_randBtn_tnr_clicked()
{
    if (mode == String_TNRs) {
        int i = rand()%SIZE;
        ui->item_tnr->setText(randStrings[i]);
    } else {
        double a = rand()%MAX_COEFF, b = rand()%MAX_COEFF, c = rand()%MAX_COEFF;
        ui->item_tnr->setText(QString::number(a) + ", " +  QString::number(b) + ", " + QString::number(c));
    }

}

void Lab10_TNR::on_sortABtn_tnr_pressed()
{
    if (mode == String_TNRs) {
        strArr->Sort();
    } else {
        polArr->Sort();
    }
    UpdateList();
}

void Lab10_TNR::UpdateList()
{
    ui->array_tnr->clear();
    if (mode == String_TNRs) {
        for (auto& item : *strArr) {
            ui->array_tnr->addItem(item.ToQString());
        }
    } else {
        for (auto& item : *polArr) {
            ui->array_tnr->addItem(item.GetQPolynom());
        }
    }
}

void Lab10_TNR::on_sortDBtn_tnr_pressed()
{
    if (mode == String_TNRs) {
        strArr->Sort(Array_TNR<String_TNR>::Descending);
    } else {
        polArr->Sort(Array_TNR<Polynom_TNR>::Descending);
    }
    UpdateList();
}

void Lab10_TNR::on_minBtn_tnr_pressed()
{
    if (mode == String_TNRs) {
        ui->minLabel_tnr->setText(strArr->Minimum().ToQString());
    } else {
        ui->minLabel_tnr->setText(polArr->Minimum().GetQPolynom());
    }
}

void Lab10_TNR::on_fillBtn_tnr_pressed()
{
    int n = ui->numLinesVal_tnr->value(), randNum;
    if (mode == String_TNRs) {
        strArr->Clear();
        for (int i = 0; i < n; i++) {
            randNum = rand()%SIZE;
            String_TNR str(randStrings[randNum]);
            strArr->Append(str);
        }
    } else {
        polArr->Clear();
        double a, b, c;
        for (int i = 0; i < n; i++) {
            a = rand()%MAX_COEFF, b = rand()%MAX_COEFF, c = rand()%MAX_COEFF;
            Polynom_TNR pol(a, b, c);
            polArr->Append(pol);
        }
    }

    UpdateList();
}


void Lab10_TNR::on_clearBtn_tnr_pressed()
{
    if (mode == String_TNRs) {
        strArr->Clear();
    } else {
        polArr->Clear();
    }
    ui->array_tnr->clear();
}


void Lab10_TNR::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0) {
        mode = String_TNRs;
    } else {
        mode = Polynom_TNRs;
    }
    UpdateList();
}

