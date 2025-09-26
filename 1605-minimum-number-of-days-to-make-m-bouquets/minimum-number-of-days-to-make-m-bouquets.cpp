class Solution {
public:
    bool possibilities(vector<int> &a, int m, int k, int midDay) {
        int cnt=0, noOfBouquets=0;
        for(auto x: a) {
            if(midDay>=x) cnt++;
            else {
                noOfBouquets += (cnt/k);
                cnt=0;
            }
        }
        noOfBouquets += (cnt/k);
        return (noOfBouquets >= m) ;
    }
    int minDays(vector<int>& a, int m, int k) {
        if(1ll*m*k > a.size()) return -1;
        int low=1e9, high=-1e9, mid, ans=-1;
        for(auto x: a) {
            low=min(low, x);
            high=max(high, x);
        }
        while(low<=high) {
            mid=(low+high)>>1;
            if(possibilities(a, m, k, mid)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};