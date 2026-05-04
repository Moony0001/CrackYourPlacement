class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        int i = 0;
        int j = n-1;

        while(i<j){
            for(int x = 0;x<n;x++){
                int temp = matrix[i][x];
                matrix[i][x] = matrix[j][x];
                matrix[j][x] = temp;
            }
            i++;
            j--;
        }

        for(int x=0;x<n;x++){
            for(int y=x+1;y<n;y++){
                int temp = matrix[x][y];
                matrix[x][y] = matrix[y][x];
                matrix[y][x] = temp;
            }
        }
    }
}