import java.util.*;

class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n = sc.nextInt();

        boolean isNegative = n < 0;
        n = Math.abs(n);

        String str = String.valueOf(n);
        int len = str.length();

        int[] arr = new int[len];

        for (int i = 0; i < len; i++) {
            arr[i] = str.charAt(i) - '0';
        }

        for (int i = 0; i < len - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < len; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        StringBuilder sb = new StringBuilder();

        if (!isNegative) {
            int firstNonZero = -1;

            for (int i = 0; i < len; i++) {
                if (arr[i] != 0) {
                    firstNonZero = i;
                    break;
                }
            }

            if (firstNonZero != -1) {
                sb.append(arr[firstNonZero]);

                for (int i = 0; i < len; i++) {
                    if (i != firstNonZero) {
                        sb.append(arr[i]);
                    }
                }
            } else {
                sb.append(0);
            }

        } else {
            for (int i = len - 1; i >= 0; i--) {
                sb.append(arr[i]);
            }
            sb.insert(0, "-");
        }

        System.out.println("Minimum number: " + sb.toString());
    }
}