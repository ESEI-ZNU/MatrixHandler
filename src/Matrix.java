package mypackage;

import java.util.Random;
import java.util.Scanner;

public class Matrix {
    private final int rows;
    private final int cols;
    private final int[][] data;

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = new int[rows][cols];
    }

    public void fillRandom(int min, int max) {
        Random rand = new Random();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = rand.nextInt(max - min + 1) + min;
            }
        }
    }

    public void inputFromConsole(Scanner scanner) {
        System.out.println("Введіть елементи матриці розміром " + rows + "x" + cols + ":");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("Елемент [" + i + "][" + j + "]: ");
                data[i][j] = scanner.nextInt();
            }
        }
    }

    public void printMatrix() {
        System.out.println("Матриця:");
        for (int[] row : data) {
            for (int val : row) {
                System.out.printf("%4d", val);
            }
            System.out.println();
        }
    }
}