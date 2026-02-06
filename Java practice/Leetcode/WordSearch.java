class Solution {
    public boolean dfs(char[][] board, String word,int i,int j,boolean[][] visited,int k){
        if(k == word.length()){
            return true;
        }
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length || 
            word.charAt(k) != board[i][j] || visited[i][j]){
            return false;
        }
        visited[i][j] = true;

        boolean res = (dfs(board, word, i + 1, j,visited, k + 1) ||
                       dfs(board, word, i - 1, j,visited, k + 1) ||
                       dfs(board, word, i, j + 1,visited, k + 1) ||
                       dfs(board, word, i, j - 1,visited, k + 1));
        visited[i][j] = false;
        return res;
    }

    public boolean exist(char[][] board, String word) {
        int rows = board.length;
        int cols = board[0].length;

        boolean [][] visited = new boolean[rows][cols];

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dfs(board,word,i,j,visited,0)){
                    return true;
                }
            }
        }
        return false;
    }
}