class Solution {
public:
    // Helper function to calculate days needed for a given capacity
    int countDays(vector<int>& weights, int capacity) {
        int days = 1, currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // Minimum capacity must be at least the heaviest package
        int high = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity is sum of all weights

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countDays(weights, mid) <= days) {
                high = mid; // Try smaller capacity
            } else {
                low = mid + 1; // Increase capacity
            }
        }
        return low; // Minimum capacity that works
    }
};
