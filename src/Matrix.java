/**
* Клас для роботи з матрцями.
*
* @author Савела Данил
* @version 1.0
*/

package mypackage; // Оголошення пакету

import java.util.Random; // Імпортуємо клас Random для генерації випадкових чисел
import java.util.Scanner; // Імпортуємо Scanner для зчитування з клавіатури

public class Matrix { // Оголошення класу Matrix
    private final int rows; // Кількість рядків матриці
    private final int cols; // Кількість стовпців матриці
    private final int[][] data; // Двовимірний масив для зберігання елементів

    public Matrix(int rows, int cols) { // Конструктор класу
        this.rows = rows; // Ініціалізуємо кількість рядків
        this.cols = cols; // Ініціалізуємо кількість стовпців
        this.data = new int[rows][cols]; // Створюємо масив для зберігання елементів
    }

    public void fillRandom(int min, int max) { // Метод заповнення випадковими числами
        Random rand = new Random(); // Створюємо об'єкт генератора випадкових чисел
        for (int i = 0; i < rows; i++) { // Проходимо по кожному рядку
            for (int j = 0; j < cols; j++) { // Проходимо по кожному стовпцю
                data[i][j] = rand.nextInt(max - min + 1) + min; // Генеруємо число в заданому діапазоні
            }
        }
    }

    public void inputFromConsole(Scanner scanner) { // Метод ручного введення матриці
        System.out.println("Введіть елементи матриці розміром " + rows + "x" + cols + ":");
        for (int i = 0; i < rows; i++) { // Ітеруємо по рядках
            for (int j = 0; j < cols; j++) { // Ітеруємо по стовпцях
                System.out.print("Елемент [" + i + "][" + j + "]: "); // Питаємо значення конкретного елемента
                data[i][j] = scanner.nextInt(); // Зчитуємо введене значення
            }
        }
    }

    public void printMatrix() { // Метод для виведення матриці
        System.out.println("Матриця:");
        for (int[] row : data) { // Для кожного рядка
            for (int val : row) { // Для кожного елемента у рядку
                System.out.printf("%4d", val); // Виводимо елемент з відступами
            }
            System.out.println(); // Переходимо на новий рядок
        }
    }
}
