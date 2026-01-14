/*
class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int n = nums.length;
        int occurence = (int)Math.floor(n/2);
        for(int i = 0; i < n; i++){
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);
            if(map.get(nums[i]) > occurence){
                return nums[i];
            }
        }
        return -1;
    }
}
*/
/*
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int occurence = (int)Math.floor(n/2);
        for(int i = 0; i < n; i++){
            int freq = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == nums[i]){
                    freq++;
                }
            }
            if(freq > occurence){
                return nums[i];
            }
        }
        return -1;
    }
}
*/
/*
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        
        Arrays.sort(nums);
        int freq = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                freq++;
            }else{
                freq = 1;
            }

            if(freq > n/2){
                return nums[i];
            }
        }
        return -1;
    }
}
 */
// Boyer-Moore Voting Algorithm
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int freq = 0, ans = 0;
        for(int i = 1; i < n; i++){
            if(freq == 0){
                ans = nums[i];
            }else if(nums[i] == nums[i-1]){
                freq++;
            }else{
                freq--;
            }
        }
        return ans;
    }
}