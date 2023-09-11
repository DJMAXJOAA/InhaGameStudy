class MedianFinder {
private:
    priority_queue<int> maxHeap;//절반 기준 작은 부분
    priority_queue<int, vector<int>, greater<int>> minHeap;//절반 기준 큰 부분
    bool first = false;
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if(!first)
        {
            maxHeap.push(num);
            first = true;
            return;
        }
        if(maxHeap.top()<num)
        {
            minHeap.push(num);
        }
        else
        {
            maxHeap.push(num);
        }
        //더 큰쪽에서 작은 쪽으로 움직이는 로직
        if(maxHeap.size()>minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if(minHeap.size()>maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if((minHeap.size() + maxHeap.size())%2 == 0)
            return (double)(maxHeap.top() + minHeap.top()) / double(2);
        else
            return (double)maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */