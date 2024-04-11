#include <iostream> /// Підключення стандартної библіотеки засобів введення-виведення
#include "ClassMatrix.cpp" /// Підключення файлу з класом Matrix

using namespace std;

class MatrixOperationsDeveloper3 ///Визначення класу MatrixOperationsDeveloper3
{
public:
    /// Функція ноження двох матриць
    static Matrix multiply(const Matrix& mat1, const Matrix& mat2) 
    {
        int rows1 = mat1.getRows(); /// Кількість рядків першої матриці
        int cols1 = mat1.getCols(); /// Кількість стовпців першої матриці
        int rows2 = mat2.getRows(); /// Кількість рядків другої матриці
        int cols2 = mat2.getCols(); /// Кількість стовпців другої матриці

        /// Перевірка сумісності розмірів матриць для множення
        if (cols1 != rows2) 
        {
            cerr << "Error: Incompatible matrix sizes for multiplication" << endl;
            exit(1);
        }

        Matrix result(rows1, cols2);

        for (int i = 0; i < rows1; ++i) 
        {
            for (int j = 0; j < cols2; ++j) 
            {
                int sum = 0;
                for (int k = 0; k < cols1; ++k) 
                {
                    sum += mat1.getData()[i][k] * mat2.getData()[k][j];
                }
                result.getData()[i][j] = sum;
            }
        }

        return result;
    }

    /// Функція множення матриці на число
    static Matrix scalarMultiply(const Matrix& mat, int scalar) 
    {
        int rows = mat.getRows(); /// Кількість рядків матриці
        int cols = mat.getCols(); /// Кількість стовпців матриці

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result.getData()[i][j] = mat.getData()[i][j] * scalar;
            }
        }

        return result;
    }

    /// Функція транспонування матриці
    static Matrix transpose(const Matrix& mat) 
    {
        int rows = mat.getRows(); /// Кількість рядків матриці
        int cols = mat.getCols(); /// Кількість стовпців матриці

        Matrix result(cols, rows);

        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result.getData()[j][i] = mat.getData()[i][j];
            }
        }

        return result;
    }
};