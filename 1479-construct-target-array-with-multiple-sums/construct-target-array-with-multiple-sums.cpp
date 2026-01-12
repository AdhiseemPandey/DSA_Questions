class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>p;
        long long sum = 0;

        for ( int i = 0 ; i < target.size() ; i++ ){
            p.push(target[i]);
            sum += target[i];
        }

        long long MaxEle , RemSum , Element; 

        while ( p.top() != 1 ){

            MaxEle = p.top();
            p.pop();
            RemSum = sum - MaxEle ; 

            // edge cases 
            if ( RemSum <= 0 || RemSum >= MaxEle ) return 0 ; 

            Element = MaxEle % RemSum ; 
            if ( Element == 0 ) {
                if ( RemSum != 1 ) return 0;
                else return 1; 
            }
            sum = RemSum + Element ; 
            p.push( Element );
        }
        return true;
    }
};



/* Right logic but TLE 

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>p;
        int sum = 0;

        for ( int i = 0 ; i < target.size() ; i++ ){
            p.push(target[i]);
            sum += target[i];
        }

        int MaxEle , RemSum , Element; 

        while ( p.top() != 1 ){

            MaxEle = p.top();
            p.pop();
            RemSum = sum - MaxEle ; 

            // edge cases 
            if ( RemSum <= 0 || RemSum >= MaxEle ) return 0 ; 

            Element = MaxEle - RemSum ; 
            sum = RemSum + Element ; 
            p.push( Element );
        }
    }
};

*/