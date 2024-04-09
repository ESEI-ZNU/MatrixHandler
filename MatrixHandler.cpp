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
    // Конструктор класу
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
    }
    // Деструктор класу
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    // Метод генерації матриці
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

    // Метод вводу матриці
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
    // Метод виводу матриці
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

    // Операція множення двох матриць
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

    // Операція множення матриці на число
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

    // Операція транспонування матриці
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

int main()
{

    setlocale(LC_ALL, "");
    int min = 1;
    int max = 10;
    int rows;
    int cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;

    Matrix matrix1(rows, cols);
    Matrix matrix2(rows, cols);

    matrix1.generateMatrix(min, max);
    matrix2.generateMatrix(min, max);

    cout << "First matrix:" << endl;
    matrix1.outputMatrix();
    cout << endl;

    cout << "Second matrix:" << endl;
    matrix2.outputMatrix();
    cout << endl;

    Matrix multiplied = matrix1.multiply(matrix2);
    cout << "Result of multiplication of the first and second matrices:" << endl;
    multiplied.outputMatrix();
    cout << endl;

    int scalar;
    cout << "Enter the number to multiply: ";
    cin >> scalar;
    Matrix scalarMultiplied = matrix1.scalarMultiply(scalar);
    cout << "Result of multiplying a matrix by number " << scalar << ":" << endl;
    scalarMultiplied.outputMatrix();
    cout << endl;

    Matrix transposed = matrix1.transpose();
    cout << "Transposed first matrix:" << endl;
    transposed.outputMatrix();
    cout << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
