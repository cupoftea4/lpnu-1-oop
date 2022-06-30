#include "mymatrix_tnr.h"

MyMatrix_TNR::MyMatrix_TNR()
{
    outdata.open("matrix.log", std::ofstream::out | std::ofstream::app);
    rows = 1; cols = 1;
    AllocMatrix();
}

/*
Handles wrong matrix size
*/
MyMatrix_TNR::MyMatrix_TNR(long rows, long cols) : rows(rows), cols(cols)
{
    outdata.open("matrix.log", std::ofstream::out | std::ofstream::app);
    if (this->rows <= 0 || this->cols <= 0 || this->rows > MaxSize || this->cols> MaxSize) {
        Log("Wrong matrix size!", Error);
        throw std::invalid_argument("Wrong matrix size!");
    }
    AllocMatrix();
}

/*
Handles wrong matrix size
*/
MyMatrix_TNR::MyMatrix_TNR(long size) : rows(size), cols(size)
{
    outdata.open("matrix.log", std::ofstream::out | std::ofstream::app);
    if (rows <= 0 || rows > MaxSize){
        Log("Wrong matrix size!", Error);
        throw std::invalid_argument("Wrong matrix size!");
    }
    AllocMatrix();
}

MyMatrix_TNR::MyMatrix_TNR(MyMatrix_TNR &matr)
{
    outdata.open("matrix.log", std::ofstream::out | std::ofstream::app);
    this->cols = matr.cols; this->rows = matr.cols;
    AllocMatrix();
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            this->SetAt(i, j, matr.matrix[i][j]);
        }
    }
}

MyMatrix_TNR::~MyMatrix_TNR()
{
    Free();
}

double MyMatrix_TNR::FindMax()
{
    double max = matrix[0][0];
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if ( matrix[i][j] > max) max = matrix[i][j];
        }
    }
    return max;
}

double MyMatrix_TNR::FindArithmeticMean()
{
    double sum = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return (sum / (rows * cols));
}


void MyMatrix_TNR::FillRandom(int max)
{
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            matrix[i][j] = rand()%max;
        }
    }
}

MyMatrix_TNR * MyMatrix_TNR::Pow(int n)
{
    MyMatrix_TNR * res = new MyMatrix_TNR(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            res->SetAt(i, j, pow(matrix[i][j], n));
        }
    }
    return res;
}

/*
Handles wrong matrix size
*/
void MyMatrix_TNR::SetSize(long rows, long cols)
{
    if (rows <= 0 || cols <= 0 || rows > (long)MaxSize || cols > (long)MaxSize) {
        Log("Wrong matrix size!", Error);
        throw std::invalid_argument("Wrong matrix size!");
    }
    size_t oldR = this->rows, oldC = this->cols, r  = rows, c = rows;
    c = min(oldC, c);
    r = min(oldR, r);
    MyMatrix_TNR temp(r, c);
    for (size_t i = 0; i < r; i ++) {
        for (size_t j = 0; j < c; j++) {
            temp.SetAt(i, j, matrix[i][j]);
        }
    }
    Free();
    this->rows = rows; this->cols = cols;
    AllocMatrix();
    for (size_t i = 0; i < r; i ++) {
        for (size_t j = 0; j < c; j++) {
            matrix[i][j] = temp.At(i, j);
        }
    }
    Log("Successfully resized matrix");
}

/*
Handles out of range indexes
*/
void MyMatrix_TNR::SetAt(long i, long j, double num)
{
    if (i >= (long)rows || i < 0 || j >= (long)cols || j < 0) {
        Log("Out of matrix range index", Error);
        throw std::out_of_range("Out of matrix range index");
    }
    matrix[i][j] = num;
}

/*
Handles out of range indexes
*/
double MyMatrix_TNR::At(long i, long j)
{
    if (i >= (long)rows || i < 0 || j >= (long)cols || j < 0) {
        Log("Out of matrix range index", Error);
        throw std::out_of_range("Out of matrix range index");
    }
    return matrix[i][j];
}

size_t MyMatrix_TNR::GetRows() const
{
    return rows;
}

size_t MyMatrix_TNR::GetCols() const
{
    return cols;
}

MyMatrix_TNR * MyMatrix_TNR::operator+(MyMatrix_TNR &matr)
{
    MyMatrix_TNR * res = new MyMatrix_TNR(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            res->SetAt(i, j, this->At(i, j) + matr.At(i, j));
        }
    }
    return res;
}

MyMatrix_TNR * MyMatrix_TNR::operator-(MyMatrix_TNR &matr)
{
    MyMatrix_TNR * res = new MyMatrix_TNR(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            res->SetAt(i, j, this->At(i, j) - matr.At(i, j));
        }
    }
    return res;
}

/*
Handles wrong matrixes multiplication
*/
MyMatrix_TNR * MyMatrix_TNR::operator*(MyMatrix_TNR &matr) {

    if (this->cols != matr.rows) {
        Log("Can't multiply matrices. First matrix cols count and second matrix rows count must be equal", Error);
        throw std::runtime_error("Can't multiply matrices. First matrix cols count and second matrix rows count must be equal");
    }
    size_t resRows = this->rows, resCols = matr.cols;
    MyMatrix_TNR * res = new MyMatrix_TNR(resRows, resCols);
    double sum = 0;
    for (size_t i = 0; i < resRows; ++i)
    {
        for (size_t j = 0; j < resCols; ++j) {
            sum = 0;
            for (size_t k = 0; k < this->cols; ++k)
            {
                sum += this->At(i, k) * matr.At(k, j);
            }
            res->SetAt(i, j, sum);
        }
    }
    Log("Successful multiplication");
    return res;
}

void MyMatrix_TNR::Log(std::string str, Type msgType)
{
    std::string type;
    if (msgType == Error) {
        type = "Error: ";
    } else if (msgType == Warning) {
        type = "Warning: ";
    }
    QDateTime current = QDateTime::currentDateTime();
    str = current.toString("[HH:mm:ss]").toStdString() + " " + type + str;
    outdata << str + "\n";
}

double MyMatrix_TNR::Round(double num, int n) const
{
    double coeff = pow(10, n);
    return round(num * coeff) / coeff;
}

/*
Handles not square matrix
*/
size_t MyMatrix_TNR::Size()
{
    if (rows == cols) return rows;
    Log("Can't use Size() when the matrix is not square", Warning);
    throw std::runtime_error("Can't use Size() when the matrix is not square");
}

void MyMatrix_TNR::SubMatrix(MyMatrix_TNR * temp, size_t size, std::vector<size_t> jSkips)
{
    bool shouldSkip = false;
    for (size_t i = 0, k = 0; i < size - 1; ++i)
    {
        for (size_t j = 0, l = 0; j < rows; ++j)
        {
            shouldSkip = false;
            for (auto &jSkip : jSkips) {
                if (j == jSkip) shouldSkip = true;
            }
            if (!shouldSkip) temp->SetAt(k, l++, matrix[i][j]);
        }
        k++;
    }
}

double MyMatrix_TNR::DeterminantRecursive(MyMatrix_TNR * temp, size_t size, std::vector<size_t> skips)
{

    int determinant = 0;
        if (size == 1) {
           return matrix[0][0];
        }
        if (size == 2) {
//            qDebug() << "Size: 2";
//            qDebug() << temp->matrix[0][0] << "*" << temp->matrix[1][1] << "-" << temp->matrix[0][1] << "*" << temp->matrix[1][0] << " = "
//                    << temp->matrix[0][0] * temp->matrix[1][1] << " - " << temp->matrix[1][0] * temp->matrix[0][1] << " = "
//                    << (temp->matrix[0][0] * temp->matrix[1][1]) - (temp->matrix[0][1] * temp->matrix[1][0]);
           return (temp->matrix[0][0] * temp->matrix[1][1]) - (temp->matrix[0][1] * temp->matrix[1][0]);
        }
        std::vector<int> tempSkips;
        bool shouldSkip = false;
        for (size_t i = 0; i < size; i++) {
            temp->Clear();
            for (size_t i = 0; i < rows; i++) {
                shouldSkip = false;
                for (auto &skip : skips) {
                    if (i == skip) shouldSkip = true;
                }
                if (!shouldSkip) tempSkips.push_back(i);
            }
            skips.push_back(tempSkips.at(i));
//            qDebug() << "SKIPS:";
            for (auto & skip : skips) qDebug() << skip;
            SubMatrix(temp, size, skips);
//            temp->Print("Temp #" + QString::number(size) + "." + QString::number(i));
//            qDebug() << pow(-1, i) << "*" <<  matrix[size - 1][skips.back()] << " * det";
            determinant += pow(-1, i + 1 + size) * matrix[size - 1][skips.back()] * DeterminantRecursive(temp, size - 1, skips);
            skips.pop_back();
//            qDebug() << "Determinant" << size << "-" << i  << " is " << determinant;
        }
        return determinant;
}

double MyMatrix_TNR::Minor(size_t n, size_t m)
{
    MyMatrix_TNR minor(rows - 1, cols - 1);
    for (size_t i = 0, k = 0; i < rows; ++i)
    {
        if (i == n) continue;
        for (size_t j = 0, l = 0; j < cols; ++j)
        {
            if (j != m)
            {
                minor.SetAt(k, l, matrix[i][j]);
                l++;
            }
        }
        k++;
    }
    return minor.Determinant();
}

MyMatrix_TNR *MyMatrix_TNR::operator=(MyMatrix_TNR *matr)
{
    delete this;
    return matr;
}


void MyMatrix_TNR::Print(QString str)
{
    qDebug() << "---------" + str + "--------";
    QString output;
    for (size_t i = 0; i < rows; i++) {
        output.clear();
        for (size_t j = 0; j < cols; j++) {
            output += QString::number(matrix[i][j]) + " ";
        }
        qDebug() << output;
    }
}

void MyMatrix_TNR::Clear(double num)
{
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            matrix[i][j] = num;
        }
    }
}

MyMatrix_TNR * MyMatrix_TNR::operator*(const double coeff)
{
    MyMatrix_TNR * res = new MyMatrix_TNR(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            res->SetAt(i, j, this->At(i, j) * coeff);
        }
    }
    return res;
}

void operator<<(QGridLayout &grid, const MyMatrix_TNR& matr) {
    int gridCount = grid.count();
    for (int i = 0; i < gridCount; i++)
        grid.itemAt(i)->widget()->deleteLater();

    for (size_t i = 0; i < matr.GetRows(); i++) {
        for (size_t j = 0; j < matr.GetCols(); j++) {
            QLineEdit * line = new QLineEdit;
            line->setText(QString::number(matr.Round(matr.matrix[i][j], 3)));
            grid.addWidget(line, i, j);
        }

    }
}

/*
Handles wrong input in QGridLayout
*/
void operator>>(const QGridLayout &grid, MyMatrix_TNR& matr) {
    for (size_t i = 0; i < matr.rows; i++) {
        for (size_t j = 0; j < matr.cols; j++) {
            QLineEdit * line = (QLineEdit *)grid.itemAtPosition(i, j)->widget();
            char* p;
            double converted = strtod(line->text().toUtf8().data(), &p);
            if (*p) {
                matr.Log("Wrong input. Only numbers are accaptable.", MyMatrix_TNR::Error);
                throw std::runtime_error("Wrong input. Only numbers are accaptable.");
                converted = 0;
            }
            matr.SetAt(i, j, converted);
        }
    }
    matr.Log("Successful input");
}

void operator<<(QTextEdit &textedit, MyMatrix_TNR& matr) {
    textedit.clear();
    for (size_t i = 0; i < matr.GetRows(); i++) {
        for (size_t j = 0; j < matr.GetCols(); j++) {
            textedit.setText(textedit.toPlainText() + " " + QString::number(matr.At(i, j)));
        }
        textedit.setText(textedit.toPlainText() + "\n");
    }
}

void MyMatrix_TNR::AllocMatrix()
{
    matrix = new double*[rows];
    for(size_t i = 0; i < rows; i++) {
        matrix[i] = new double[cols]();
    }
}

void MyMatrix_TNR::Free()
{

    for (size_t i = 0; i < rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
    matrix = nullptr;
}

size_t MyMatrix_TNR::min(size_t a, size_t b)
{
    if (a > b) return b;
    return a;
}

/*
Handles:
 -0 determinant
*/
MyMatrix_TNR * MyMatrix_TNR::Inverse() {
    if (Determinant() == 0) {
        Log("Can't inverse matrix. Determinant is 0.", Error);
        throw std::runtime_error("Can't inverse matrix. Determinant is 0.");
    }
    if (rows == 1 && cols == 1) return new MyMatrix_TNR(*this);
    MyMatrix_TNR * res = new MyMatrix_TNR(rows, cols);
    double det = Determinant();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            res->SetAt(i, j, pow(-1, i + j) * Minor(i, j) / det);
        }
    }
    res = res->Transpose();
    Log("Successfully inversed matrix");
    return res;
}

MyMatrix_TNR *MyMatrix_TNR::Transpose()
{
    MyMatrix_TNR * res = new MyMatrix_TNR(cols, rows);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            res->SetAt(j, i, matrix[i][j]);
        }
    }
    return res;
}

/*
Handles not square matrix
*/
double MyMatrix_TNR::Determinant()
{
    if (rows != cols) {
        Log("Can't find determinant. Matrix is not square", Error);
        throw std::runtime_error("Can't find determinant. Matrix is not square");;
    }
    MyMatrix_TNR * temp = new MyMatrix_TNR(*this);
    std::vector<size_t> skips;
    double determinant = DeterminantRecursive(temp, rows, skips);
    delete temp;
    temp = nullptr;
    Log("Successfully found determinant");
    return determinant;
}
