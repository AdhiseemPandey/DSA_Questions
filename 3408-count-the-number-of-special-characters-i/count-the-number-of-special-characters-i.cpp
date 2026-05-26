class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());

        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++) {
            if(s.count(c) && s.count(toupper(c))) {
                ans++;
            }
        }

        return ans;
    }
};

/*

// Approach 1 : use two arrays 
class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for(char c : word) {

            if(islower(c))
                lower[c - 'a'] = 1;

            else
                upper[c - 'A'] = 1;
        }

        int ans = 0;

        for(int i = 0; i < 26; i++) {

            if(lower[i] && upper[i])
                ans++;
        }

        return ans;
    }
};

*******************************************************************************************

// Two sets 

class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> lower;
        unordered_set<char> upper;

        for(char c : word) {

            if(islower(c))
                lower.insert(c);

            else
                upper.insert(c);
        }

        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++) {

            if(lower.count(c) && upper.count(toupper(c))) {
                ans++;
            }
        }

        return ans;
    }
};

*******************************************************************************************

// toUpper and toLower 

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());

        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++) {
            if(s.count(c) && s.count(toupper(c))) {
                ans++;
            }
        }

        return ans;
    }
};

*******************************************************************************************

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            if (s.count(c) && s.count(c - 'a' + 'A')) {
                ans++;
            }
        }

        return ans;
    }
};


*/