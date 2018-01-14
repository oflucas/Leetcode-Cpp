// Total Accepted: 4496
// Total Submissions: 7951
// Difficulty: Easy
// 152ms 23%

class Logger {
public:
    unordered_map<string, int> h;

    /** Initialize your data structure here. */
    Logger() {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (!h.count(message) || h[message] <= timestamp - 10) {
            h[message] = timestamp;
            return true;
        }
        return false; 
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */