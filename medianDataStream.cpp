class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    void addNum(int num)
    {
        if (maxHeap.size() == 0 || maxHeap.top() > num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        if (maxHeap.size() == minHeap.size() + 2) {
            int num = maxHeap.top();
            maxHeap.pop();
            minHeap.push(num);
        }
        
        if (minHeap.size() == maxHeap.size() + 2) {
            int num = minHeap.top();
            minHeap.pop();
            maxHeap.push(num);
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top())/2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        };
        
        return minHeap.top();
    }
};
