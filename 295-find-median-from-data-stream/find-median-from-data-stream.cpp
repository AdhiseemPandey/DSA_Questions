class MedianFinder {
private:
    // Max-heap to store the smaller half of the data
    priority_queue<int> maxHeap;

    // Min-heap to store the larger half of the data
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Constructor to initialize MedianFinder object
    MedianFinder() {
    }

    // Function to add a new number to the data stream
    void addNum(int num) {
        // Step 1: Add to maxHeap first
        maxHeap.push(num);

        // Step 2: Balance by pushing the largest from maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: If minHeap has more elements, move top back to maxHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Function to find the current median
    double findMedian() {
        // If both heaps are of equal size, take the average of the tops
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // If odd size, the top of maxHeap is the median
        return maxHeap.top();
    }
};


/*
//Approach-1 (O(n^2) - TLE
//T.C : O(n^2)
//S.C : O(50001) ~= O(1)
class MedianFinder {
public:
    vector<int> vec;
    int i = 0;
    MedianFinder() {
        vec.resize(5*10000+1);
    }
    
    void addNum(int num) {
        if(i == 0) {
            vec[i++] = num;
            return;
        }
        int j = i-1;
        while(j >= 0 && vec[j] > num) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = num;
        i++;
    }
    
    double findMedian() {
        int n = i;
        if(n%2 == 0) {
            int l = n/2-1;
            int r = n/2;
            return (float)(vec[l]+vec[r])/2;
        }
        
        return vec[n/2];
    }
};

//Approach-2 (O(logn) insertion using priority_queue) - Accepeted
//T.C : The overall time complexity is O(log N) for the addNum method and O(1) for the findMedian method.
//S.C : O(N).
class MedianFinder {
public:
    priority_queue<int> left_max_heap; //max heap
    priority_queue<int, vector<int>, greater<int>> right_min_heap; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }
        
        
        //always maintain left_max_heap size one greater than rigfht_min_heap size
        //ya fir, dono ka size equal ho
        
        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if(left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()) {
            // matlab even number of elements hue honge
            
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        }
        
        //else hamare paas odd number of elemenes hue honge
        return left_max_heap.top();
    }
};





*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */