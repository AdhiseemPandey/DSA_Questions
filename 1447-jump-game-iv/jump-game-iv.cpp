class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>>mp;

        for( int i = 0 ; i < n ; i++ ){
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0 ; 

        while( !q.empty() ){
            int s = q.size();

            while(s--){
                int curr = q.front();
                q.pop();

                if( curr == n-1 ){
                    return steps;
                    // Example 2 wala case 
                }


                int left = curr - 1;
                int right = curr + 1 ; 

                if( left >= 0 && visited[left] == false ){
                    q.push(left);
                    visited[left] = true;
                }
                if( right < n && !visited[right] ){
                    q.push(right);
                    visited[right] = true;
                }

                // equla to array me wala cas e
                for( const int &idx : mp[arr[curr]] ){
                    if(!visited[idx] ){
                        q.push(idx);
                        visited[idx] = true;
                    }
                }
                mp.erase(arr[curr] ) ; 
            }
            steps++;

        }
        return -1 ; 
    }
};

// chances -1 , +1 , jaha pe equal ho  => to jump 