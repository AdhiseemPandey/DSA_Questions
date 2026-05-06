class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int a = boxGrid.size();
        int b = boxGrid[0].size();

        // safe space 
        vector<vector<char>> temp(a, vector<char>(b));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                temp[i][j] = boxGrid[i][j];
            }
        }

        // gravity up to down ie left to right 
        for (int i = 0; i < a; i++) {
            int empty = b - 1;
            for (int j = b - 1; j >= 0; j--) {
                if (temp[i][j] == '*') {
                    empty = j - 1;
                } else if (temp[i][j] == '#') {
                    swap(temp[i][j], temp[i][empty]);
                    empty--;
                }
            }
        }

        // rotate 
        vector<vector<char>> rotated(b, vector<char>(a));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                rotated[j][a - 1 - i] = temp[i][j];
            }
        }

        return rotated;
    }
};
