class Solution {
public:
    bool win(vector<string>& board, char ch) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == ch && board[i][1] == ch && board[i][2] == ch)
                return true;
            if (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch)
                return true;
        }

        if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch)
            return true;

        if (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch)
            return true;

        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;

        for (auto &row : board) {
            for (char c : row) {
                if (c == 'X') x++;
                else if (c == 'O') o++;
            }
        }

        if (!(x == o || x == o + 1))
            return false;

        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');

        if (xWin && oWin)
            return false;

        if (xWin && x != o + 1)
            return false;

        if (oWin && x != o)
            return false;

        return true;
    }
};