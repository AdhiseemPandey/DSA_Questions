class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0 ; 
        int rightMax = 0 ; 
        int totalWater = 0 ; 
        int n = height.size();
        int left = 0;
        int right = n-1;

        while ( left < right ){
            // AIM :- To select smaller one and move the way
            if(height[left] <= height[right]){
                if(leftMax > height[left]){
                    totalWater += leftMax - height[left];
                }
                else{
                    leftMax = height[left];
                }
                left += 1 ; 
            }
            else{
                if(rightMax > height[right]){
                    totalWater += rightMax - height[right];
                }
                else{
                    rightMax = height[right];
                }
                right -= 1 ;                 
            }
        }
        return totalWater;
    }
};