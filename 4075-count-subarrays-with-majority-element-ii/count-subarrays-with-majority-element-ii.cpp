class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // cummSum -> Cnt 
        int cummSum = 0;
        mp[0] = 1; 

        long long validLeft = 0;
        long long result = 0;

        for( int i = 0 ; i < nums.size() ; i++ ){
            if( nums[i] == target ){
                validLeft += mp[cummSum];
                cummSum += 1;
            }
            else{
                cummSum -= 1;
                validLeft -= mp[cummSum];
            }
            mp[cummSum] += 1;
            result += validLeft;
        }
        return result;
    }
};




/*

//Approach-1 (Brute Force) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int count = 0;

            for (int j = i; j < n; ++j) {
                count += (nums[j] == target ? 1 : -1);

                if (count > 0) {
                    result++;
                }

            }
        }

        return result;
    }
};



//Approach-2 (Brute Force Prefix Sum) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }

        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int sum = nums[r] - ((l > 0) ? nums[l-1] : 0);

                if(sum > 0)
                    ans++;
            }
        }

        return ans;

    }
};

*/