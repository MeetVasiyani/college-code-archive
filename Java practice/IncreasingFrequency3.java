import java.util.*;

class Main {
    static int checkArray(int[] A) {
        if (A.length == 0) return 0;

        for (int i = 1; i < A.length; i++) {
            if (A[i] < A[i - 1]) {
                return 0;
            }
        }

        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : A) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        for (int count : freq.values()) {
            if (count >= 3) {
                return 1;
            }
        }

        return 0;
    }

    public static void main(String[] args) {
        int[] A1 = {1, 1, 1, 2, 2};
        int[] A2 = {1, 1, 1, 3, 3, 3, 3};

        System.out.println(checkArray(A1));
        System.out.println(checkArray(A2));
    }
}
