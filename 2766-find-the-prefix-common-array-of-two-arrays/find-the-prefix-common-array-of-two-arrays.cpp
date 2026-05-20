// approach #1 string se
// approach #2 using set
// approach #3 using "greedy counting idea"

//Frequency Approach->Optimal approach
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> freq(n+1,0),res(n);
        int count=0;
        for(int i=0;i<n;++i){
            freq[A[i]]++;
            if(freq[A[i]]==2)  count++;

            freq[B[i]]++;
            if(freq[B[i]]==2)  count++;

            res[i] = count;
        }
        return res;
    }
};

/*
//Set approach
class Solution {
    int prefixMatch(vector<int>& A,unordered_set<int> &set_B,int &size){
        int count=0;
        for(int i=0;i<=size;++i){
            if(set_B.count(A[i]))
                count++;
        }
        return count;
    }
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> res;
        unordered_set<int> set_B;
        for(int i=0;i<n;++i){
            set_B.insert(B[i]);
            res.push_back(prefixMatch(A,set_B,i));
        }
        return res;
    }
};

*/
