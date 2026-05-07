class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIdx ; 
        unordered_map<string, int> wordToIdx ; 
        stringstream ss(s);

        string token;

        int cntToken = 0 ; 
        int i = 0 ; 
        int n = pattern.size();

        while ( ss >> token ){
            cntToken++;

            if( i == n ) return false;

            if( charToIdx[pattern[i]] != wordToIdx[token]) return false;

            charToIdx[pattern[i]] = i+1;
            wordToIdx[token] = i+1;

            i++;
        }

        if( cntToken != n ) return false;
        if( i != n )
            return false;

        return true;
    }
};