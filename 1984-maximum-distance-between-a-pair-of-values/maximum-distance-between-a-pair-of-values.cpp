
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0; //nums1
        int j = 0; //nums2

        int result = 0;

        while(i < m && j < n) {
            if(nums1[i] > nums2[j]) {
                i++;
            } else {
                result = max(result, j-i);
                j++;
            }
        }
        
        return result;
    }
};


/*
// BRUTE FORCE O(N) & O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        int res = 0;
        for( int i = 0 ; i < a ; i++ ){
            for ( int j = 0 ; j < b ; j++ ) {
                if ( nums2[j] >= nums1[i] && j >= i ){
                    int ans = abs(j-i);
                    res = max(res, ans);
                }
            }
        }
        return res;
    }
};

*/