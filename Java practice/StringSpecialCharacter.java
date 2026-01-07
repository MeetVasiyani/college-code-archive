class Solution {
    public static String reverseOnlyLetters(String str) {
        char[] arr = str.toCharArray();
        int left = 0, right = arr.length - 1;

        while (left < right) {
            if (!Character.isLetter(arr[left])) {
                left++;
            } else if (!Character.isLetter(arr[right])) {
                right--;
            } else {
                char temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
        return new String(arr);
    }

    public static void main(String[] args) {
        System.out.println(reverseOnlyLetters("a!!!b.c.d,e'f,ghi"));
        System.out.println(reverseOnlyLetters("Ab,c,de!$"));
    }
}
