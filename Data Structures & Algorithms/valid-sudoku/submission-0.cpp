class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> line(9);

        for (int i = 0; i < 9; i++) {
            if (arrayValid(board[i]) == false) return false;
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                line[j] = board[j][i];
            }
            if (arrayValid(line) == false) return false;
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int row = 3 * (i / 3) + (j / 3);
                int col = 3 * (i % 3) + (j % 3); 
                line[j] = board[row][col];
            }
            if (arrayValid(line) == false) return false;
        }
        return true;
    }

   private:
    bool arrayValid(const vector<char>& line) {
        array<int, 9> amount = {0};

        for (int i = 0; i < 9; i++) {
            if (line[i] == '.') continue;
            if (amount[line[i] - '1'] == 1) return false;
            amount[line[i] - '1']++;
        }
        return true;
    }
};
