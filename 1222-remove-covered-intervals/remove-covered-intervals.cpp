class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;

        int n = intervals.size();

        auto lambda = []( vector<int> &vec1, vector<int> & vec2 ){
            if( vec1[0] == vec2[0] ){
                return vec1[1] > vec2[1];
            }
            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);

        answer.push_back(intervals[0]);

        for( int i = 1; i < n; i++ ){
            if( answer.back()[0] <= intervals[i][0] && answer.back()[1] >= intervals[i][1]){
                continue;
            }

            answer.push_back(intervals[i]);
        }
        return answer.size();
    }
};   