class Solution {
public:
    // n log n tak => some case me n^2 = 10^8
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map word -> to vector 
        unordered_map<string, vector<string>> dictionary; 
        for ( string it : strs ){
            string t = it ; 
            sort(t.begin(), t.end());
            dictionary[t].push_back(it);
        }
        vector<vector<string>> ans;
        for( auto it : dictionary ) {
            ans.push_back(it.second);
        }
        return ans;
    }
};