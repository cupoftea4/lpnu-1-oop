#include "lab11_tnr.h"
#include "ui_lab11_tnr.h"


Lab11_TNR::Lab11_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab11_TNR)
{
    ui->setupUi(this);
    Restart();
    int a;
    qDebug() << a;
}

Lab11_TNR::~Lab11_TNR()
{
    delete ui;
}

void Lab11_TNR::DeleteNAfterM(int n, int m)
{
    Output("Deleting " + QString::number(n) + " elements after " + QString::number(m) + "th in container #1");
    int numToSave = container1.size() - m - n;
    float temp[numToSave];
    int i = 0, j = 0;
    for (auto & num : container1) {
        if (i >= m+n) {
            temp[j] = num;
            j++;
        }
        i++;
    }
    for (int i = 0; i < numToSave+n; i++) {
        container1.pop();
    }
    for (int i = 0; i < numToSave; i++) {
        container1.push(temp[i]);
    }
}

bool Lab11_TNR::condition(float num)
{
    float limiter = ui->conditionNum_TNR->value();
    QString cond = ui->condition1_TNR->currentText();
    if (cond == ">")
        return num > limiter;
    if (cond == "<")
        return num < limiter;
    return false;
}

void Lab11_TNR::Sort(int container, SortWay way)
{
    switch (container) {
        case 1:
            Output("Sorting container #1");
            for (std::size_t i = 0; i < container1.size(); i++)
                    if (way == Ascending) {
                        StackSwap(i, StackMin(i));
                    } else {
                        StackSwap(i, StackMax(i));
                    }
            break;
        case 2:
            Output("Sorting container #2");
            for (std::size_t i = 0; i < container2.size(); i++)
                    if (way == Ascending) {
                        QueueSwap(i, QueueMin(i));
                    } else {
                        QueueSwap(i, QueueMax(i));
                    }
    }
}

void Lab11_TNR::OutputStack()
{
    QString output;
    Output("Outputing container #1: ");
    for (auto & num : container1) {
        output += QString::number(num) + " ";
    }
    Output(output);
}

void Lab11_TNR::OutputQueue()
{
    QString output;
    Output("Outputing container #2: ");
    for (auto & num : container2) {
        output += QString::number(num) + " ";
    }
    Output(output);

}

int Lab11_TNR::StackMin(int start)
{
    int i = 0, minI = container1.size() - 1;
    float min = container1.top();
    for (auto & num : container1) {
        if (i >= start && num < min) {
            minI = i;
            min = num;
        }
        i++;
    }
    return minI;
}

int Lab11_TNR::StackMax(int start)
{
    int i = 0, maxI = container1.size() - 1;
    float max = container1.top();
    for (auto & num : container1) {
        if (i >= start && num > max) {
            maxI = i;
            max = num;
        }
        i++;
    }
    return maxI;
}

void Lab11_TNR::StackSwap(int n, int m) {
    int containerSize = container1.size();
    if (n > containerSize || m > containerSize) return;
    float temp[containerSize], tempNum;
    int i = 0;
    for (auto & num : container1) {
        temp[i] = num;
        i++;
    }
    for (int j = 0; j < containerSize; j++) container1.pop();
    tempNum = temp[n];
    temp[n] = temp[m];
    temp[m] = tempNum;
    for (int j = 0; j < i; j++) {
        container1.push(temp[j]);
    }
}

int Lab11_TNR::QueueMin(int start)
{
    int i = 0, minI = container2.size() - 1;
    float min = container2.back();
    for (auto & num : container2) {
        if (i >= start && num < min) {
            minI = i;
            min = num;
        }
        i++;
    }
    return minI;
}

int Lab11_TNR::QueueMax(int start)
{
    int i = 0, maxI = container2.size() - 1;
    float max = container2.back();
    for (auto & num : container2) {
        if (i >= start && num > max) {
            maxI = i;
            max = num;
        }
        i++;
    }
    return maxI;
}

void Lab11_TNR::QueueSwap(int n, int m)
{
    int containerSize = container2.size();
    if (n > containerSize || m > containerSize) return;
    float temp[containerSize], tempNum;
    int i = 0;
    for (auto & num : container2) {
        temp[i] = num;
        i++;
    }
    for (int j = 0; j < containerSize; j++) container2.pop();
    tempNum = temp[n];
    temp[n] = temp[m];
    temp[m] = tempNum;
    for (int j = 0; j < i; j++) {
        container2.push(temp[j]);
    }
}

void Lab11_TNR::Output(QString str)
{
    ui->out_tnr->setPlainText(ui->out_tnr->toPlainText() + "\n" +str);
}


void Lab11_TNR::Restart()
{
}


void Lab11_TNR::on_output1_tnr_pressed()
{
    OutputStack();
}


void Lab11_TNR::on_output2_tnr_pressed()
{
    OutputQueue();
}


void Lab11_TNR::on_outputS_tnr_pressed()
{
    QString output;
    Output("Outputing second stack container: ");
    for (auto & num : secondStack) {
        output += QString::number(num) + " ";
    }
    Output(output);
}


void Lab11_TNR::on_outputQ_tnr_pressed()
{
    QString output;
    Output("Outputing second queue container: ");
    for (auto & num : secondQueue) {
        output += QString::number(num) + " ";
    }
    Output(output);
}


void Lab11_TNR::on_rand1Btn_tnr_pressed()
{
    Output("Filling container #1");
    for(int i = 0; i < Size; i++) {
        container1.push(rand()%20);
    }
}


void Lab11_TNR::on_randSBtn_tnr_pressed()
{
    Output("Filling second stack container");
    for(int i = 0; i < Size; i++) {
        secondStack.push(rand()%20);
    }
}


void Lab11_TNR::on_Sto1Btn_tnr_pressed()
{
    Output("Pushing all from second stack container to container #1");
    for (auto & num : secondStack) {
        container1.push(num);
    }
}




void Lab11_TNR::on_sort1Btn_tnr_pressed()
{
   if (ui->sortWay_tnr->currentText() == "Ascending") {
       Sort(1);
   } else {
       Sort(1, Descending);
   }
}


void Lab11_TNR::on_sort2Btn_tnr_pressed()
{
    if (ui->sortWay_tnr->currentText() == "Ascending") {
        Sort(2);
    } else {
        Sort(2, Descending);
    }
}


void Lab11_TNR::on_mergeBtn_tnr_pressed()
{
    for (auto & num : container1) {
        secondQueue.push(num);
    }
    for (auto & num : container2) {
        secondQueue.push(num);
    }
}




void Lab11_TNR::on_getNum_tnr_pressed()
{
    Output("Outputing first condition number from container #1");
    for (auto & num : container1) {
        if (condition(num)) {
            Output(QString::number(num));
            break;
        }
    }
}


void Lab11_TNR::on_fill2from1Btn_tnr_pressed()
{
    Output("Filling container #2 with condition nums from container #1");
    for (auto & num : container1) {
        if (condition(num)) {
            container2.push(num);
        }
    }
}


void Lab11_TNR::on_countQBtn_tnr_pressed()
{
    int count = 0;
    for (auto & num : secondQueue) {
        if (condition(num)) {
            count++;
        }
    }
    ui->count_tnr->setText(QString::number(count));
    Output(QString::number(count) + " elements fulfil the condition in second queue container(mix)");
}


void Lab11_TNR::on_delete_tnr_pressed()
{
    int n = ui->n_TNR->value(), m = ui->m_TNR->value();
    DeleteNAfterM(n, m);
}


void Lab11_TNR::on_clear_tnr_pressed()
{
    ui->out_tnr->clear();
}


void Lab11_TNR::on_clear1_tnr_pressed()
{
    Output("Clearing container #1");
    while(!container1.empty()) {
        container1.pop();
    }
}


void Lab11_TNR::on_clear2_tnr_pressed()
{
    Output("Clearing container #2");
    while(!container2.empty()) {
        container2.pop();
    }
}


void Lab11_TNR::on_addToSBtn_tnr_clicked()
{
    container1.push(ui->addToSVal_tnr->value());
}


void Lab11_TNR::on_addToQBtn_tnr_clicked()
{
    container2.push(ui->addToQVal_tnr->value());
}


void Lab11_TNR::on_pushButton_clicked()
{
    container1.pop();
}


void Lab11_TNR::on_pushButton_2_clicked()
{
    container2.pop();
}

