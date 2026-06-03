class Solution {
public:

    int findFinishTime(vector<int>& firstStart, vector<int>& firstDuration,
                       vector<int>& secondStart, vector<int>& secondDuration) {

        int firstFinish = INT_MAX;
        for (int i = 0; i < firstStart.size(); i++) {
            firstFinish = min(firstFinish, firstStart[i] + firstDuration[i]);
        }

        int secondFinish = INT_MAX;
        for (int i = 0; i < secondStart.size(); i++) {
            secondFinish = min(secondFinish, max(firstFinish, secondStart[i]) + secondDuration[i]);
        }

        return secondFinish;
    }

    int earliestFinishTime(vector<int>& landStart, vector<int>& landDuration,
                           vector<int>& waterStart, vector<int>& waterDuration) {
        int landThenWater = findFinishTime(landStart, landDuration, waterStart, waterDuration);

        int waterThenLand = findFinishTime(waterStart, waterDuration, landStart, landDuration);

        return min(landThenWater, waterThenLand);
    }
};
