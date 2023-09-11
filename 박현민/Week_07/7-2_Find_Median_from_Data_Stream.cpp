class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        // 1. insert
        if (maxHeap.empty() || num > maxHeap.top())
        {
            minHeap.push(num);
        }
        else
        {
            maxHeap.push(num);
        }

        // 2. re-balancing
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() + 1 < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size())
            return (double)maxHeap.top();
        else if (maxHeap.size() < minHeap.size())
            return (double)minHeap.top();
        else
            return (double)((maxHeap.top() + minHeap.top()) / 2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */