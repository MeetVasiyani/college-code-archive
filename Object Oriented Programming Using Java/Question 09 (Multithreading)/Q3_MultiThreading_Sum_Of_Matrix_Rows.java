/*Write a complete multi-threaded program to meet following requirements: 
    i.Read matrix [A] m x n
    ii.Create m number of threads
    iii.Each thread computes summation of elements of one row, i.e. ith row of the matrix is processed by ith thread. Where 
        0 <= i< m.
    iv. Print the results. 
*/

import java.util.Scanner;

public class Q3_MultiThreading_Sum_Of_Matrix_Rows {

    static int[][] matrix;
    static int m, n;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows: ");
        m = scanner.nextInt();

        System.out.print("Enter the number of columns: ");
        n = scanner.nextInt();

        matrix = new int[m][n];

        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        scanner.close();

        Thread[] threads = new Thread[m];
        for (int i = 0; i < m; i++) {
            threads[i] = new Thread(new RowSumTask(i));
            threads[i].start();
        }

        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class RowSumTask implements Runnable {
        int row;

        public RowSumTask(int row) {
            this.row = row;
        }

        @Override
        public void run() {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += matrix[row][j];
            }
            System.out.println("Sum of row " + row + ": " + sum);
        }
    }
}
