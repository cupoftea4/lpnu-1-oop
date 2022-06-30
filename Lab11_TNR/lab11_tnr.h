#ifndef LAB11_TNR_H
#define LAB11_TNR_H

#include <QMainWindow>
#include <iostream>
#include <stack>
#include <queue>
#include <QLabel>

template<typename T, typename Container = std::deque<T>>
class iterable_stack
: public std::stack<T, Container>
{
    using std::stack<T, Container>::c;

public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return std::begin(c); }
    iterator end() { return std::end(c); }

    const_iterator begin() const { return std::begin(c); }
    const_iterator end() const { return std::end(c); }
};

template<typename T, typename Container=std::deque<T> >
class iterable_queue : public std::queue<T,Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

QT_BEGIN_NAMESPACE
namespace Ui { class Lab11_TNR; }
QT_END_NAMESPACE

class Lab11_TNR : public QMainWindow
{
    Q_OBJECT

public:

    Lab11_TNR(QWidget *parent = nullptr);
    ~Lab11_TNR();

private slots:

    void on_output1_tnr_pressed();

    void on_output2_tnr_pressed();

    void on_outputS_tnr_pressed();

    void on_outputQ_tnr_pressed();

    void on_rand1Btn_tnr_pressed();

    void on_randSBtn_tnr_pressed();

    void on_Sto1Btn_tnr_pressed();

    void on_sort1Btn_tnr_pressed();

    void on_sort2Btn_tnr_pressed();

    void on_mergeBtn_tnr_pressed();

    void on_getNum_tnr_pressed();

    void on_fill2from1Btn_tnr_pressed();

    void on_countQBtn_tnr_pressed();

    void on_delete_tnr_pressed();

    void on_clear_tnr_pressed();

    void on_clear1_tnr_pressed();

    void on_clear2_tnr_pressed();

    void on_addToSBtn_tnr_clicked();

    void on_addToQBtn_tnr_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void Restart();
    void DeleteNAfterM(int n, int m);
    bool condition(float num);
    enum SortWay { Descending, Ascending };
    void Sort(int Container, SortWay way = Ascending);
    void OutputStack();
    void OutputQueue();
    int StackMin(int i);
    int StackMax(int i);
    void StackSwap(int n, int m);
    int QueueMin(int i);
    int QueueMax(int i);
    void QueueSwap(int n, int m);
    void Output(QString str);
    const int Size = 10;
    int height = 20;
    iterable_stack<float> container1;
    iterable_queue<float> container2;
    iterable_stack<float> secondStack;
    iterable_queue<float> secondQueue;
    Ui::Lab11_TNR *ui;
};
#endif // LAB11_TNR_H
