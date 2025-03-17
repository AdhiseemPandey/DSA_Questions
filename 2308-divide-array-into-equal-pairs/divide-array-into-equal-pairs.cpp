class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> remain;
        for(int ele : nums){
            if(remain.count(ele)) remain.erase(ele);
            else                  remain.insert(ele);
        }
        return remain.size()==0;
    }
    // T.C. => O(N)
    // S.C. => O(N)

};