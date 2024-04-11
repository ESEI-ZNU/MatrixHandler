#include <iostream>
#include <cstdlib>
using namespace std; /// Простір імен

class Matrix  /// Визначення класу
{

private:
    int** data; /// Вказівник на двовимірний масив
    int rows;
    int cols;

public:
    /// Конструктор класу
    Matrix(int rows, int cols) : rows(rows), cols(cols)  /// Ініціалізує поля класу та виділяє пам'ять для матриці
    {  
        data = new int* [rows];  /// Виділення пам'яті для рядків
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];   /// Виділення пам'яті для стовпців
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;   /// Ініціалізація кожного елемента нулем
            }
        }
    }
    /// Деструктор класу
    ~Matrix()   /// Видаляє виділену пам'ять
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i]; /// Видалення пам'яті рядків
        }
        delete[] data;  /// Видалення пам'яті вказівника
    }

    /// Метод генерації матриці
    void generateMatrix(int min, int max)  
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = rand() % (max - min + 1) + min; /// Генерація емементів матриці
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
                cin >> data[i][j];  /// Ввод елементів матриці
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
                cout << data[i][j] << " "; /// Виведення елементів матриці
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
                result.data[i][j] = data[i][j] * scalar;  /// Множення кожного елемента на число
            }
        }
        return result; /// Повернення результату
    }

    /// Операція транспонування матриці
    Matrix transpose() const
    {
        Matrix result(cols, rows); /// Створення транспонованої матриці з оберненмим розмірами
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[j][i] = data[i][j];  /// Заповнення елементів
            }
        }
        return result; /// Повернення результату
    }
};
