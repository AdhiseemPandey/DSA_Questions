class Solution {
public:
    int minOperations(vector<string>& logs) {
     int cnt = 0 ; 
     for( const auto & ops : logs ){
        if( ops == "../"){
            cnt = max(0, cnt-1);
        }
        else if( ops != "./"){
            ++cnt;
        }
     }  
     return cnt; 
    }
};