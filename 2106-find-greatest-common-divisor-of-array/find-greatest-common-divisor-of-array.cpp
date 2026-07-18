class Solution {
public:
    int findGCD(vector<int>& arr) {
     int mini = INT_MAX;
     int maxi = INT_MIN;
     int ans;

     for(int i = 0 ; i < arr.size() ; i++){
        if( arr[i] > maxi) maxi = arr[i];
        if( arr[i] < mini) mini = arr[i];
       // cout << maxi << mini;
     }
      ans = __gcd(maxi,mini);
     return ans;   
    }
};