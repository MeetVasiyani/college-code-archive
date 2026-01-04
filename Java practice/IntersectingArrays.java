import java.util.*;

class Main {
    public static void main(String[] args) {
        int[] nums1 = {1,4,6,7,9,9};
        int[] nums2 = {2,4,3,7,9,9};

        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;

        while(i < nums1.length && j < nums2.length) {
            if(nums1[i] == nums2[j]) {
                result.add(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        System.out.println(result);
    }
}
