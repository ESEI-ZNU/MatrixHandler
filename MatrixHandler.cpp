#include <iostream>

#include "ClassMatrix.cpp" ///Підключення файлу з класом

using namespace std; /// Простір імен

int main()
{
    /// Ініціалізація змінних
    setlocale(LC_ALL, "");
    string metod;  /// Змінна для вибора методу створення матриці
    int min = 0;   /// Мінімальне значення для генерації матриці
    int max = 0;   /// Максисальне значення для генерації матриці
    int rows;
    int cols;
    string action;   /// Змінна для вибору дії

    cout << "Enter rows: ";
    cin >> rows;   /// Ввод рядків матриці
    cout << "Enter cols: ";
    cin >> cols;   /// Ввод строк матриці

    Matrix matrix1(rows, cols);  /// Створення об'єкту першої матриці
    Matrix matrix2(rows, cols);  /// Створення об'єкту другої матриці

    cout << "Enter the matrix creation method(generate or input): ";
    cin >> metod;   /// Вибір методу створення матриці
    if (metod == "generate")
    {
        cout << "Enter the min: ";
        cin >> min;       /// Ввод мінімального значення для генерації
        cout << "Enter the max: ";
        cin >> max;       /// Введення максимального значення для генерації

        matrix1.generateMatrix(min, max);    /// Генерація першої матриці
        matrix2.generateMatrix(min, max);    /// Генерація другої матриці
    }
    else if (metod == "input")
    {

        matrix1.inputMatrix();    /// Ввод першої матриці
        matrix2.inputMatrix();    /// Ввод другої матриці

    }
    else {
        cout << "Enter the correct method" << endl;  /// Помилка про не вірний ввод метода
        return 0;
    }
    cout << "First matrix:" << endl;
    matrix1.outputMatrix();   ///Виведення першої матриці
    cout << endl;

    cout << "Second matrix:" << endl;
    matrix2.outputMatrix();   /// Виведення другої матриці
    cout << endl;

    cout << "select an action: " << endl;
    cout << "x - multiplication of two matrices" << endl;
    cout << "xn - matrix multiplication by a number" << endl;
    cout << "t - matrix transposition" << endl;
    cin >> action;    /// Вибір дії
    if (action == "x")
    {
        Matrix multiplied = matrix1.multiply(matrix2); /// Множення матриць
        cout << "Result of multiplication of the first and second matrices:" << endl;
        multiplied.outputMatrix();  ///Виведення результату множення
        cout << endl; 
    }
    else if (action == "xn")
    {
        int scalar;
        cout << "Enter the number to multiply: ";
        cin >> scalar; /// Ввод числа для множення 
        Matrix scalarMultiplied = matrix1.scalarMultiply(scalar);  /// Множення матриці на число
        cout << "Result of multiplying a matrix by number " << scalar << ":" << endl;
        scalarMultiplied.outputMatrix();  /// Виведення результату
        cout << endl;
    }
    else if (action == "t")
    {
        Matrix transposed = matrix1.transpose();  /// Транспонування матриці
        cout << "Transposed first matrix:" << endl;
        transposed.outputMatrix();  /// Виведення результату
        cout << endl;
    }
    else 
    {
        cout << "Error";
    }

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
