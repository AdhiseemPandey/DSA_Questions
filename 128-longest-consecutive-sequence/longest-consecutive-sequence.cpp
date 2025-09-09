// OPTIMAL => Using SET 
// if no colisions T.C. O(3N) , if collisions are present then brute/better  is  better
// S.C. => O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if( n==0 ) return 0;
        int longest = 1; 
        unordered_set<int> ap;
        for(int i = 0 ; i < n ; i++){
            ap.insert(nums[i]);
        }

        for(auto it : ap ){
            if(ap.find(it - 1) == ap.end()){
                int cnt = 1 ; 
                int x = it ; 
                while(ap.find(x+1) != ap.end()){
                    x = x + 1 ; 
                    cnt = cnt + 1 ; 
                }
                longest = max(longest,cnt);
            }
        }
        return longest ;
    }
};




// BETTER => Sort and Find
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         // sort adn find 
//         if ( nums.size() == 0 ) return 0;
//         sort( nums.begin() , nums.end() );
//         int n = nums.size();
//         int lastSmaller = INT_MIN;
//         int cnt = 0 ;
//         int longest = 1;
//         for(int i = 0 ; i < n ; i++ ){
//             if(nums[i] -1 == lastSmaller ){
//                 cnt+=1;
//                 lastSmaller = nums[i];
//             }
//             else if ( lastSmaller != nums[i]){
//                 cnt = 1 ; 
//                 lastSmaller = nums[i];
//             }
//             longest = max(longest,cnt);
//         }
//         return longest;
//     }
// };