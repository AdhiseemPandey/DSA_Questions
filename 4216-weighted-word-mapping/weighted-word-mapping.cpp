class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for( string &word : words) {
            int temp = 0 ; 
            for( char & ch : word ){
                temp += weights[ch-'a'];
            }
            ans += 'z'-temp%26;
        }
        return ans;
    }
};