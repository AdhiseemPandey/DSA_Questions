class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        
        int curr = 0;
        for(int &g : gain) {
            curr += g;

            maxi = max(maxi, curr);
        }

        return maxi;
    }
};