class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string max_s = s;
        string min_s = s;
        int n = s.size();

        //Maximize number: The first digit<9 should be made 9
        for(int i=0;i<n;++i){
            if(s[i]!='9'){
                for(int j=0;j<n;++j)
                    if(max_s[j]==s[i])
                        max_s[j]='9';
                break;
            }
        }

        //Minimize number
        if(s[0]>'1'){
            for(int i=0;i<n;++i)
                if(min_s[i]==s[0])
                    min_s[i]='1';
        }else{
            //Find 1st digit>0 from index 1 to (n-1)
            for(int i=1;i<n;++i){
                if(s[i]>'1'){
                    for(int j=i;j<n;++j)
                        if(min_s[j]==s[i])
                            min_s[j]='0';
                    break;
                }
            }
        }
        return stoi(max_s)-stoi(min_s);
    }
};