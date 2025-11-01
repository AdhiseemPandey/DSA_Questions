using vi  = vector<int>;          
using vvi = vector<vector<int>>;  

class Solution {
private:
    void findCombinations(int index , int target , vi & arr , vvi & ans , vi & ds){
        if ( index == arr.size()){
            if( target == 0 ){
                ans.push_back(ds);
            }
            return ; 
        }
        // picking element 
        if ( arr[index] <= target ){
            ds.push_back(arr[index]);
            findCombinations(index, target - arr [ index ] , arr ,ans , ds );
            // removing element as we move up in recursive tree
            ds.pop_back();
        }
        findCombinations( index + 1 , target, arr, ans, ds);
    }
public:
    vvi combinationSum(vi & candidates, int target) {
        vvi ans;
        vi ds;
        findCombinations( 0, target, candidates, ans, ds);
        return ans ; 
    }
};