import java.util.*;

class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter rows of Matrix 1: ");
        int r1 = sc.nextInt();

        System.out.println("Enter columns of Matrix 1: ");
        int c1 = sc.nextInt();

        System.out.println("Enter rows of Matrix 2: ");
        int r2 = sc.nextInt();

        System.out.println("Enter columns of Matrix 2: ");
        int c2 = sc.nextInt();

        int[][] matrix1 = new int[r1][c1];
        int[][] matrix2 = new int[r2][c2];

        System.out.println("Enter elements of Matrix 1:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                matrix1[i][j] = sc.nextInt();
            }
        }

        System.out.println("Enter elements of Matrix 2:");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                matrix2[i][j] = sc.nextInt();
            }
        }

        if(c1 != r2){
            System.out.println("Multiplicaton not possible.");
            return;
        }

        int[][] result = new int[r1][c2];

        for(int i = 0; i < r1; i++){
            for(int j = 0; j < c2; j++){
                int sum = 0;
                for(int k = 0; k < c1; k++){
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                result[i][j] = sum;
            }
        }

        System.out.println("Result Matrix:");

        for(int i = 0; i < r1; i++){
            for(int j = 0; j < c2; j++){
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}