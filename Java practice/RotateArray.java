import java.util.*;

class Main {

    public static int[] reverse(int i, int j, int[] nums) {
        int start = i, end = j;
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
        return nums;
    }

    public static void main(String[] args) {
        int k = 3;
        int[] nums = {1,2,3,4,5,6,7};
        int n = nums.length;

        k = k % n;

        reverse(0, n - 1, nums);
        reverse(0, k - 1, nums);
        reverse(k, n - 1, nums);

        for (int i = 0; i < n; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}
