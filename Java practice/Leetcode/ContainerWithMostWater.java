class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int result = 0;

        while (i < j) {
            result = Math.max(result, (j - i) * Math.min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return result;

    }
}
