class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int> maxQ;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int maxSz = maxQ.size();
        int minSz = minQ.size();

        // minQ에 넣을 때는 maxQ의 사이즈가 더 클 때
        if(maxSz > minSz)
        {
            if(!maxQ.empty() && num < maxQ.top())
            {
                maxQ.push(num);
                minQ.push(maxQ.top());
                maxQ.pop();
            }
            else
            {
                minQ.push(num);
            }
        }
        // maxQ에 넣기
        else
        {
            // num이 minQ.top() 보다 크면 minQ에 넣고 minQ.top을 maxQ에 넣어줌
            if(!minQ.empty() && num > minQ.top())
            {
                minQ.push(num);
                maxQ.push(minQ.top());
                minQ.pop();
            }
            else
            {
                maxQ.push(num);
            }
        }
    }
    
    double findMedian() {
        int minSz = minQ.size();
        int maxSz = maxQ.size();

        if((minSz + maxSz) % 2 == 0)
        {
            return (minQ.top() + maxQ.top()) / 2.0;
        }

        return maxQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */