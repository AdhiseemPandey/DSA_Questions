class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        // check if no. +ve 
        // initial idx + "k" size 
        // size % n too ;

        vector<int> temp;
        for( auto it : nums ){
            if( it >= 0 ) temp.push_back(it);
        }

        int n = temp.size();

        vector<int> temp2(n,0);
        for( int i = 0 ; i < n ; i++ ){
            int oldpos = ( i + k ) % n ; 
            temp2[i] = temp[oldpos];
        }

        int i = 0 ; 
        for ( int j = 0 ; j < nums.size() ; j++ ){
            if( nums[j] >= 0 ){
                nums[j] = temp2[i];
                i++;
            }
        }

        return nums;
    }
};