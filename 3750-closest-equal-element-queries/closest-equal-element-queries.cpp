class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for ( int i = 0 ; i < n ; i++ ){
            mp[nums[i]].push_back(i);
        }  

        vector<int>result;
        for( int qi: queries ){ // q 
            int element = nums[qi];
            vector<int> &vec = mp[element];

            int sizee = vec.size();

            if ( sizee == 1 ){
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec); // log n
            int res = INT_MAX;

            // right neighbour - pso+1
            int right = vec[(pos+1) % sizee];
            int d = abs( qi - right );
            int circularDist = n-d;
            res = min({res, d, circularDist});

            // right neighbour - pso+1
            int left = vec[(pos-1+sizee) % sizee];
            d = abs( qi - left );
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }
        return result;
    }
};
// TC => q *  log(n)