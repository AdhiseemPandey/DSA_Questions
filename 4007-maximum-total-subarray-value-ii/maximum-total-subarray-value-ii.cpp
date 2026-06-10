class SegmentTree {
public:
    vector<int> segmentTree;
    bool isMinTree;

    // Segment Tree is a binary tree data structure used for range queries
    // (like min/max/sum) and updates in O(log n) time.
    // It stores information about intervals/subarrays in a hierarchical way.

    SegmentTree(vector<int>& nums, bool flag) {
        int n = nums.size();
        this->isMinTree = flag;

        // Segment tree size is ~4*n to safely store all nodes.
        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        // Base case: leaf node represents a single element
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        // Recursively build left and right child
        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        // Internal node stores min or max depending on tree type
        if (isMinTree) {
            segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        } else {
            segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        }
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        // Querying segment tree is done in O(log n).
        // We check overlap between query range [start,end] and node range [l,r].

        // No overlap
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        // Complete overlap
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        // Partial overlap → query both children
        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        if (isMinTree) {
            return min(a, b);
        }

        return max(a, b);
    }

    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    typedef long long ll;

    ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        // Using segment tree we can get min and max in O(log n)
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);

        return (ll)maxEl - minEl;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        // Build two segment trees: one for min, one for max
        SegmentTree minST(nums, true);   // true → min tree
        SegmentTree maxST(nums, false);  // false → max tree

        // Priority queue stores {value, l, r} with max heap
        priority_queue<tuple<ll, int, int>> pq;

        // Step-1: Initialize heap with best values for ranges [l, n-1]
        for (int l = 0; l < n; l++) {
            ll value = getValue(l, n - 1, minST, maxST, n);
            pq.push({value, l, n - 1});
        }

        // Step-2: Extract top k values
        ll result = 0;
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            result += value;

            // Shrink range and push next best candidate
            if (r > l) {
                ll nextBestValue = getValue(l, r - 1, minST, maxST, n);
                pq.push({nextBestValue, l, r - 1});
            }
        }

        return result;
    }
};
