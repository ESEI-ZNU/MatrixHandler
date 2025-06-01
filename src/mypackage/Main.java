package mypackage;
import mypackage.Matrix;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введіть розмір квадратної матриці (n x n): ");
        int n = scanner.nextInt();

        Matrix matrix = new Matrix(n, n);

        System.out.print("Оберіть режим (1 - випадкова генерація, 2 - введення вручну): ");
        int choice = scanner.nextInt();

        if (choice == 1) {
            matrix.fillRandom(0, 100);
        } else if (choice == 2) {
            matrix.inputFromConsole(scanner);
        } else {
            System.out.println("Невірний вибір.");
            return;
        }

        matrix.printMatrix();

        // Заготовка: вибір операцій (без реалізації)
        System.out.println("\nОберіть операцію над матрицею:");
        System.out.println("1 - Обчислити суму всіх елементів (ще не реалізовано)");
        System.out.println("2 - Знайти максимальний елемент (ще не реалізовано)");
        System.out.println("3 - Транспонувати матрицю (ще не реалізовано)");
        System.out.println("Інакше - Вихід");

        int operation = scanner.nextInt();

        switch (operation) {
            case 1 -> System.out.println("Сума поки не реалізована.");
            case 2 -> System.out.println("Пошук максимуму поки не реалізований.");
            case 3 -> System.out.println("Транспонування поки не реалізоване.");
            default -> {
                System.out.println("Вихід з програми.");
                System.exit(0);
            }
        }
    }
}
