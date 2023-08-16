class Solution {
    public void solveSudoku(char[][] board) {
        if(board == null) return;
        solve(board);
    }
    
    private boolean solve(char[][] board) {
        for(int i=0; i<board.length; i++) {
            for(int j=0; j<board[0].length; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;
                            
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    private boolean isValid(char[][] board, int row, int col, char c) {
        for(int i=0; i<board[0].length; i++) {
            if(board[row][i] == c) return false;
        }
        for(int i=0; i<board.length; i++) {
            if(board[i][col] == c) return false;
        }
        int xReg = 3 * (row / 3);
        int yReg = 3 * (col / 3);
        
        for(int i=0; i<9; i++) {
            if(board[xReg + i / 3][yReg + i % 3] == c) return false;
        }
        return true;
    }
}