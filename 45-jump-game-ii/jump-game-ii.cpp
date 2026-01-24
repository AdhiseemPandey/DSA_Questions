// Approach 1 => Recurison : n^n & n
// Approach 2 => DP : n^2 & n^2 
// Approach 3 => Greeedy Algo O(n) & O(1) below  =>> ( carrying ranges ) same to valid parenthesis ( 678 )
class Solution {
public:
    int jump(vector<int>& nums) {
        int jmp = 0 ; 
        int l = 0 ; 
        int r = 0 ; 
        while  ( r < nums.size() - 1 ){
            int sabse_door = 0 ; 
            for (  int i = l ; i <= r ; i++ ){
                sabse_door = max ( ( i + nums[i] ) , sabse_door );
            }
            l = r + 1 ; 
            r = sabse_door ; 
            jmp++ ; 
        }
        return jmp ; 
    }
};