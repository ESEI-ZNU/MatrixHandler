/**
 * Клас для роботи з матрцями.
 *
 * @author Савела Данил
 * @version 1.0
 */

package mypackage;
import mypackage.Matrix;

import java.util.Scanner;// Імпортуємо клас Scanner для зчитування даних з консолі

public class Main { // Оголошення головного класу Main
    public static void main(String[] args) { // Точка входу в програму
        Scanner scanner = new Scanner(System.in); // Створюємо об'єкт Scanner для зчитування з клавіатури

        System.out.print("Введіть розмір квадратної матриці (n x n): "); // Просимо ввести розмірність матриці
        int n = scanner.nextInt(); // Зчитуємо розмір матриці

        Matrix matrix = new Matrix(n, n); // Створюємо об'єкт матриці розміром n x n

        System.out.print("Оберіть режим (1 - випадкова генерація, 2 - введення вручну): "); // Запитуємо режим заповнення
        int choice = scanner.nextInt(); // Зчитуємо вибір користувача

        if (choice == 1) { // Якщо обрано випадкову генерацію
            matrix.fillRandom(0, 100); // Заповнюємо матрицю випадковими числами від 0 до 100
        } else if (choice == 2) { // Якщо обрано ручне введення
            matrix.inputFromConsole(scanner); // Користувач вводить елементи матриці вручну
        } else { // Якщо введено щось інше
            System.out.println("Невірний вибір."); // Повідомляємо про помилку
            return; // Завершуємо програму
        }

        matrix.printMatrix(); // Виводимо матрицю на екран

        // Меню операцій (ще не реалізовані)
        System.out.println("\nОберіть операцію над матрицею:");
        System.out.println("1 - Обчислити суму всіх елементів (ще не реалізовано)");
        System.out.println("2 - Знайти максимальний елемент (ще не реалізовано)");
        System.out.println("3 - Транспонувати матрицю (ще не реалізовано)");
        System.out.println("Інакше - Вихід");

        int operation = scanner.nextInt(); // Зчитуємо вибрану операцію

        switch (operation) { // Виконуємо дію в залежності від вибору
            case 1 -> System.out.println("Сума поки не реалізована."); // Пункт 1 - сума
            case 2 -> System.out.println("Пошук максимуму поки не реалізований."); // Пункт 2 - максимум
            case 3 -> System.out.println("Транспонування поки не реалізоване."); // Пункт 3 - транспонування
            default -> { // Будь-яке інше значення
                System.out.println("Вихід з програми."); // Завершуємо програму
                System.exit(0); // Вихід з кодом 0
            }
        }
    }
}
