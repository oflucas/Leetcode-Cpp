class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter(): hitCnt(0), time_window(300) {}
    
    /** Record a hit.
 *         @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (q.empty() || q.front().timestamp < timestamp)
            q.push_front(HitEvent(timestamp, 0));
        q.front().cnt++;
        hitCnt++;
    }
    
    /** Return the number of hits in the past 5 minutes.
 *         @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && q.back().timestamp <= timestamp - time_window) {
            hitCnt -= q.back().cnt;
            q.pop_back();
        }
        return hitCnt;
    }
    
private:
    struct HitEvent {
        HitEvent(int tt, int n): timestamp(tt), cnt(n) {}
        
        int timestamp;
        int cnt;
    };

    deque<HitEvent> q;
    int hitCnt;
    int time_window;
};

/**
 *  * Your HitCounter object will be instantiated and called as such:
 *   * HitCounter obj = new HitCounter();
 *    * obj.hit(timestamp);
 *     * int param_2 = obj.getHits(timestamp);
 *      */
