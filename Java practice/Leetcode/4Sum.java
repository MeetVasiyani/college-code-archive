class Solution {

    List<List<Integer>> result = new ArrayList<>();
    List<Integer> quad = new ArrayList<>();

    public void kSum(int[] nums, int k, int start, long target) {
        if (k != 2) {
            for (int i = start; i < nums.length - k + 1; i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue;
                }
                quad.add(nums[i]);
                kSum(nums, k - 1, i + 1, target - nums[i]);
                quad.remove(quad.size() - 1);
            }
            return;
        }
        
        int left = start, right = nums.length - 1;
        while (left < right) {
            long sum = (long) nums[left] + (long) nums[right];
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                List<Integer> temp = new ArrayList<>(quad);
                temp.add(nums[left]);
                temp.add(nums[right]);
                result.add(temp);
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            }
        }
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        kSum(nums, 4, 0, (long) target);
        return result;
    }
}