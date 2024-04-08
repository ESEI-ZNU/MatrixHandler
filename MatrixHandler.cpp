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
        cout << "Введiть елементи матрицi";
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                cout << "Введiть елемент у позицiю [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }
    // Метод виводу матриці
    void outputMatrix() 
    {
        cout << "Матриця:" << endl;
        for (int i = 0; i < rows; i++) 
        {
            for(int j = 0; j < cols; j++) 
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }


};

int main()
{
   
    setlocale(LC_ALL, "");
    int min = 1;
    int max = 10;
    int rows;
    int cols;
    cout << "Введiть кiлькiсть строк: ";
    cin >> rows;
    cout << "Введiть кiлькiсть стовпцiв: ";
    cin >> cols;

    Matrix matrix(rows, cols);

    matrix.generateMatrix(min, max);
    matrix.outputMatrix();

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
