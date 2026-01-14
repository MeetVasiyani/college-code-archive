class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int lastEle = n*n;
        int [] freq = new int [lastEle+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                freq[grid[i][j]]++;
            }
        }
        int duplicated = 0,missing = 0;

        for(int i = 1; i <= lastEle; i++){
            if(freq[i] == 2){
                duplicated = i;
            }
            else if(freq[i] == 0){
                missing = i;
            }
        }

        return new int[] {duplicated,missing};
    }
}