using ll = long long;
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // first height is 0
        // last height si n-1
        restrictions.push_back({1,0});
        restrictions.push_back({n, n-1});

        sort( restrictions.begin(), restrictions.end());

        int a = restrictions.size();
        for( int i = 1 ; i < a ; i++ ){
            int dist = restrictions[i][0] - restrictions[i-1][0];

            restrictions[i][1] = min ( restrictions[i][1], restrictions[i-1][1] + dist ); 
        }

        for( int i = a - 2 ;  i >= 0 ; i-- ){
            int dist = restrictions[i+1][0] - restrictions[i][0];

            restrictions[i][1] = min( restrictions[i][1], restrictions[i+1][1] + dist );
        }

        ll ans = 0;

        for (int i = 1; i < a; i++) {
            ll x1 = restrictions[i - 1][0];
            ll h1 = restrictions[i - 1][1];

            ll x2 = restrictions[i][0];
            ll h2 = restrictions[i][1];

            ll dist = x2 - x1;

            ll peak =
                max(h1, h2) +
                (dist - llabs(h1 - h2)) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};