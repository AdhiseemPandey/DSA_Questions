class Solution {
public:
    bool isAnagram(string a, string b) {
        if( a.length() != b.length() ){
            return false;
        }
        unordered_map<char,int> ap;
        for ( int i = 0 ; i < a.length() ; i++ ){
            ap[a[i]]++;
        }
        for( int i = 0 ; i < b.length() ; i++ ){
            if( ap.find(b[i]) != ap.end() ){
                ap[b[i]] -= 1;
            }
            else{
                return false;
            }
        }
        for(auto items : ap ){
            if(items.second != 0 ){
                return false;
            }
        }
        return true;
    }
};
// cnt of string same ho for all elements 

// Approach 1 => sort and match 
// Approach 2 => cnt and match cnt array ~(2n) ~ O(n)

// Approach 3 => unordered map