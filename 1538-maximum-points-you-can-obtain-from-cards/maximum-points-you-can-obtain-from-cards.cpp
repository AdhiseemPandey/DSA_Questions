class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;

        // take first k cards from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        maxSum = lsum;

        int rightIndex = cardPoints.size() - 1;

        // slide: remove from left, add from right
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};
