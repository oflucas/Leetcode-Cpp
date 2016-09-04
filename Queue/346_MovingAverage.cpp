// Total Accepted: 7326
// Total Submissions: 12999
// Difficulty: Easy
// 56ms 73%

class MovingAverage {
private:
    int size, sum;
    queue<int> q;
    
public:
    /** Initialize your data structure here. */
    
    MovingAverage(int size) {
        this->size = size; // *this.size = size IS WRONG!
        sum = 0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum * 1. / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */