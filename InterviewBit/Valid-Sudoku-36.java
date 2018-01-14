class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        HashSet<String> set = new HashSet<>();
        
        for(int row=0; row < 9; row++){
            for(int column=0; column < 9; column++){
                
                if(board[row][column] != '.'){
                    
                    char number = board[row][column];
                    
                    /* Generate string for each number and check uniqueness within row, column and block */
                    if(!set.add(number + " in row " + row) ||
                       !set.add(number + " in column " + column) ||
                       !set.add(number + " in block " + row/3 + " - " + column/3))
                        return false;
                }
            }
        }
        return true;
        
    }
}
