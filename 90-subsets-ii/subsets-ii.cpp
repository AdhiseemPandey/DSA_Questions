using vii = vector<vector<int>>;
using vi  = vector<int>;
// using I = int
class Solution {
private: 
    void findSubsets( int index , vi & nums , vi &ds , vii &ans ){
        ans.push_back(ds);
        for( int i = index ; i < nums.size() ; i++ ){
            if( i != index && nums[i] == nums[ i - 1 ] ) continue; 
            ds.push_back( nums[i] );
            findSubsets( i+1 , nums , ds , ans );
            ds.pop_back();
        }
    }
public:
    vii subsetsWithDup( vi & nums) {
        vii ans ; 
        vi ds ; 
        sort ( nums.begin() , nums.end() );
        findSubsets( 0 , nums, ds, ans );
        return ans ; 
    }
};