class Solution {
public:
    // TC = > O ( 2^2n * 2n ) // check it once - review TC 
    vector<string> result;

    bool isValid( string & str ){

        // stack ka bhi use kar sakte ha i

        int cnt = 0 ; 
        for ( char &ch : str ){
            if ( ch ==  '(') cnt ++ ; 
            else cnt -- ; 

            // eliminate all ")" as they are invalid from starting 
            if ( cnt < 0 ) return false;
        }
        return cnt == 0 ; 
    }

    void solve( string & curr , int n ){
        if( curr.length() == 2*n ){
            if(isValid(curr)) {
                result.push_back(curr);
            }
            return ; 
        }

        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr ="";
        solve(curr,n);
        return result;
    }
};