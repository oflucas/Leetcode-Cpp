class MedianFinder {
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();
        if (minQ.size() > maxQ.size()) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
    
    double findMedian() {
        return minQ.size() < maxQ.size() ? 
            maxQ.top() : (minQ.top() + maxQ.top()) / 2.0;
    }
};

/**
 *  * Your MedianFinder object will be instantiated and called as such:
 *   * MedianFinder obj = new MedianFinder();
 *    * obj.addNum(num);
 *     * double param_2 = obj.findMedian();
 *      */
