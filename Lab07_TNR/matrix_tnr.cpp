#include "matrix_tnr.h"

Matrix_TNR::Matrix_TNR() {
    rows = 1; cols = 1;
    AllocMatrix();
}

Matrix_TNR::Matrix_TNR(int rows, int cols) : rows(rows), cols(cols)
{
    AllocMatrix();
}

Matrix_TNR::Matrix_TNR(Matrix_TNR *matr)
{
    matr.SetSize(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matr[i][j] = matrix[i][j];
        }
    }
}

Matrix_TNR::~Matrix_TNR()
{
    for (int i = 0; i < rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
    matrix = nullptr;
}

double Matrix_TNR::FindMax()
{
    double max = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ( matrix[i][j] > max) max = matrix[i][j];
        }
    }
    return max;
}

double Matrix_TNR::FindArithmeticMean()
{
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return (sum / (rows * cols));
}

void Matrix_TNR::SortRowAcsending(int index)
{
    if (index >= rows) return;
    SelectionSort(matrix[index], rows, Ascending);
}

void Matrix_TNR::SortColumnDescending(int index)
{
    if (index >= cols) return;
    double temp[cols];
    for (int i = 0; i < cols; i++) temp[i] = matrix[i][index];
    SelectionSort(temp, cols, Descending);
    for (int i = 0; i < cols; i++) matrix[i][index] = temp[i];
}

void Matrix_TNR::FillRandom()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand()%20;
        }
    }
}

Matrix_TNR * Matrix_TNR::Pow(int n)
{
    Matrix_TNR * res = new Matrix_TNR(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res->SetAt(i, j, pow(matrix[i][j], n));
        }
    }
    return res;
}

void Matrix_TNR::SetSize(int rows, int cols)
{
    int oldR = this->rows, oldC = this->cols, r  = rows, c = rows;
    c = std::min(oldC, c);
    r = std::min(oldR, r);
    double ** tempMatr = new double*[r];
    for(int i = 0; i < r; i++) {
        tempMatr[i] = new double[c]();
    }
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j++) {
            tempMatr[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < this->rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
    this->rows = rows; this->cols = cols;
    AllocMatrix();
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = tempMatr[i][j];
        }
    }
    for (int i = 0; i < r; ++i)
        delete [] tempMatr[i];
    delete [] tempMatr;

}

Matrix_TNR * Matrix_TNR::operator+(const Matrix_TNR &matr)
{
    Matrix_TNR * res = new Matrix_TNR(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res->SetAt(i, j, this->At(i, j) + matr[i][j]);
        }
    }
    return res;
}

Matrix_TNR * Matrix_TNR::operator-(const Matrix_TNR &matr)
{
    Matrix_TNR * res = new Matrix_TNR(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res->SetAt(i, j, this->At(i, j) - matr[i][j]);
        }
    }
    return res;
}

Matrix_TNR * Matrix_TNR::operator*(const Matrix_TNR &matr) {
    if (this->cols != matr.rows) return nullptr;
    int resRows = this->rows, resCols = matr.cols;
    Matrix_TNR * res = new Matrix_TNR(resRows, resCols);
    double sum = 0;
    for (int i = 0; i < resRows; ++i)
    {
        for (int j = 0; j < resCols; ++j) {
            sum = 0;
            for (int k = 0; k < this->cols; ++k)
            {
                sum += this->At(i, k) * matr[k][j];
            }
            res->SetAt(i, j, sum);
        }
    }
    return res;
}

Matrix_TNR *Matrix_TNR::operator=(Matrix_TNR *matr)
{
    delete this;
    return matr;
}

double* &Matrix_TNR::operator[](const int &index) const
{
    return  matrix[index];
}

Matrix_TNR * Matrix_TNR::operator*(const double coeff)
{
    Matrix_TNR * res = new Matrix_TNR(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res->SetAt(i, j, this->At(i, j) * coeff);
        }
    }
    return res;
}

void operator<<(QGridLayout &grid, const Matrix_TNR& matr) {
    int gridCount = grid.count();
    for (int i = 0; i < gridCount; i++)
        grid.itemAt(i)->widget()->deleteLater();

    for (int i = 0; i < matr.rows; i++) {
        for (int j = 0; j < matr.cols; j++) {
            QLineEdit * line = new QLineEdit;
            line->setText(QString::number(matr[i][j]));
            grid.addWidget(line, i, j);
        }

    }
}

void operator>>(const QGridLayout &grid, Matrix_TNR& matr) {
    for (int i = 0; i < matr.rows; i++) {
        for (int j = 0; j < matr.cols; j++) {
            QLineEdit * line = (QLineEdit *)grid.itemAtPosition(i, j)->widget();
            matr.SetAt(i, j, line->text().toDouble());
        }
    }
}

void operator<<(QTextEdit &textedit, const Matrix_TNR& matr) {
    textedit.clear();
    for (int i = 0; i < matr.rows; i++) {
        for (int j = 0; j < matr.cols; j++) {
            textedit.setText(textedit.toPlainText() + " " + QString::number(matr[i][j]));
        }
        textedit.setText(textedit.toPlainText() + "\n");
    }
}

void Matrix_TNR::AllocMatrix()
{
    matrix = new double*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new double[cols]();
    }
}

int Matrix_TNR::Min(const double *array, int start, int n)
{
    double min = array[start];
    int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int Matrix_TNR::Max(const double *array, int start, int n)
{
    double max = array[start];
    int maxIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void Matrix_TNR::Swap(double *array, int n, int m)
{
    double temp = array[n];
    array[n] = array[m];
    array[m] = temp;
}

void Matrix_TNR::SelectionSort(double *array, int n, SortWay way = Ascending)
{
    for (int i = 0; i < n; i++) {
        if (way == Ascending) {
            Swap(array, i, Min(array, i, n));
        } else if (way == Descending) {
            Swap(array, i, Max(array, i, n));
        }
    }
}
