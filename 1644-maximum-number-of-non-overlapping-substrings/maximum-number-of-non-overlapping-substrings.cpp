class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Step 1: record first and last occurrence
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> ranges;

        // Step 2: compute minimal valid range for each character
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int l = first[c], r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int d = s[i] - 'a';
                if (first[d] < l) {
                    l = first[d];
                    i = l - 1; // restart scan from new l
                }
                if (last[d] > r) {
                    r = last[d];
                }
            }

            // Validate containment
            for (int i = l; i <= r; i++) {
                int d = s[i] - 'a';
                if (first[d] < l || last[d] > r) {
                    valid = false;
                    break;
                }
            }

            if (valid && l == first[c]) {
                ranges.push_back({l, r});
            }
        }

        // Step 3: greedy selection
        sort(ranges.begin(), ranges.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        vector<string> res;
        int prevEnd = -1;
        for (auto &[l, r] : ranges) {
            if (l > prevEnd) {
                res.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return res;
    }
};



/*
/*
  -> Strongly connected components 
  -> Kosaraju Algorithm 

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
       int n = s.size();
       vector < int > first ( 26,-1), last ( 26,-1);
       for ( int i = 0 ; i < n ; i++ ){
        if ( first [s[i] - 'a'] == -1 ) first [ s[i] - 'a'] = i ; 
        last [ s[i] - 'a' ] = i ; 
       } 
       vector <pair <int, int > > validRange;
       for ( int i = 0; i < 26; i++){
        if ( first[i] == -1) continue;
        int start = first[i], end = last[i];
        bool valid = true;
        

        int l = start , r = end ; 
        while ( true ){
            bool changed = false ;
            for ( int j = l ; j <= r ; j++ ){
                char c = s[j] - 'a';
                if ( first[c] < l ){
                    l = first[c];
                    changed  = true;
                }
                if ( last[c] > r ){
                    r = first[c];
                    changed  = true;
                }
            }
            if ( !changed ) break;
        } 
        for ( int j = l ; j <= r ; j++){
            char c = s[j] - 'a' ;
            if ( first[c] < l || last[c] > r ){
                valid = false ; 
                break;
            }
        }
        if ( valid && start == l ){
            validRange.push_back( {l,r} );
        }
       }
       sort ( validRange.begin(), validRange.end(), [](auto &a, auto &b){
        return a.second < b.second ; 
       });
        vector < string > res;
        // check overlapping condtion
        int prevend = -1;
        for ( auto & [start, end] : validRange){
            if ( start > prevend ){
                res.push_back(s.substr(start, end - start + 1));
                prevend = end;
            }
        }
        
        return res;

    }
};

*/
