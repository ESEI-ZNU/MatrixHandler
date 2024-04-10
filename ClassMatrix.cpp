#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix
{

private:
    int** data;
    int rows;
    int cols;

public:
    /// Конструктор класу
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
    }
    /// Деструктор класу
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    /// Метод генерації матриці
    void generateMatrix(int min, int max)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = rand() % (max - min + 1) + min;
            }
        }
    }

    /// Метод вводу матриці
    void inputMatrix()
    {
        cout << "Enter the matrix elements";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter the element in the position [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }
    /// Метод виводу матриці
    void outputMatrix()
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    /// Операція множення двох матриць
    Matrix multiply(const Matrix& other) const
    {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                for (int k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    /// Операція множення матриці на число
    Matrix scalarMultiply(int scalar) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    /// Операція транспонування матриці
    Matrix transpose() const
    {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};