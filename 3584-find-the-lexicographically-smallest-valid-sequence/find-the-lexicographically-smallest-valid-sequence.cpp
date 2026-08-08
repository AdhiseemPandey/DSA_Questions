class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> rightSide_MatchedLength(n, 0);
        int rightMatched = 0;
        int i = n - 1;
        int j = m - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }
            rightSide_MatchedLength[i] = rightMatched;
            i--;
        }

        vector<int> seq;
        bool changePower = true;
        i = 0;
        j = 0;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if (changePower && i + 1 < n && rightSide_MatchedLength[i + 1] >= m - j - 1) {
                seq.push_back(i);
                j++;
                changePower = false;
            }
            i++;
        }
        return j == m ? seq : vector<int>();
    }
};
