class TicTacToe {
    int *vcnt, *hcnt;
    int ldcnt, rdcnt;
    int n;
    int win;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): ldcnt(0), rdcnt(0), win(0) {
        this->n = n;
        vcnt = new int[n]();
        hcnt = new int[n]();
    }
    
    /** Player {player} makes a move at ({row}, {col}).
 *         @param row The row of the board.
 *                 @param col The column of the board.
 *                         @param player The player, can be either 1 or 2.
 *                                 @return The current winning condition, can be either:
 *                                                 0: No one wins.
 *                                                                 1: Player 1 wins.
 *                                                                                 2: Player 2 wins. */
    int move(int row, int col, int player) {
        update_cnt(vcnt[col], player);
        update_cnt(hcnt[row], player);
        if (isLeftDiagnal(row, col))
            update_cnt(ldcnt, player);
        if (isRightDiagnal(row, col))
            update_cnt(rdcnt, player);
        return win;
    }
    
    void update_cnt(int& cnt, int player) {
        if (win != 0 || cnt == n + 1)
            return;
            
        if (player == 1) {
            if (cnt < 0)
                cnt = n + 1;
            else
                if (++cnt == n)
                    win = 1;
        }
        
        if (player == 2) {
            if (cnt > 0)
                cnt = n + 1;
            else
                if (--cnt == -n)
                    win = 2;
        }
    }
    
    bool isLeftDiagnal(int i, int j) { return i == j; }
    bool isRightDiagnal(int i, int j) { return i + j == n - 1; }
};

/**
 *  * Your TicTacToe object will be instantiated and called as such:
 *   * TicTacToe obj = new TicTacToe(n);
 *    * int param_1 = obj.move(row,col,player);
 *     */
