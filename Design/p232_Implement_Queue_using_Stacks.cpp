class MyQueue {
    stack<int> front, rear;
    
public:
    /** Push element x to the back of queue. */
    void push(int x) {
        rear.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = this->peek();
        front.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (front.empty()) this->transport();
        return front.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return front.empty() && rear.empty(); 
    }

private:    
    void transport() {
        while (!rear.empty()) {
            front.push(rear.top());
            rear.pop();
        }
    }
};

/**
 *  * Your MyQueue object will be instantiated and called as such:
 *   * MyQueue obj = new MyQueue();
 *    * obj.push(x);
 *     * int param_2 = obj.pop();
 *      * int param_3 = obj.peek();
 *       * bool param_4 = obj.empty();
 *        */
