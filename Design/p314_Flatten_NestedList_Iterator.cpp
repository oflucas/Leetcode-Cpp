/**
 *  * // This is the interface that allows for creating nested lists.
 *   * // You should not implement it, or speculate about its implementation
 *    * class NestedInteger {
 *     *   public:
 *      *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *       *     bool isInteger() const;
 *        *
 *         *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *          *     // The result is undefined if this NestedInteger holds a nested list
 *           *     int getInteger() const;
 *            *
 *             *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *              *     // The result is undefined if this NestedInteger holds a single integer
 *               *     const vector<NestedInteger> &getList() const;
 *                * };
 *                 */

class NestedIterator {
    stack<const NestedInteger*> st; 
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto rit = nestedList.rbegin(); rit != nestedList.rend(); rit++)
            st.push(&(*rit));
    }

    int next() {
        int res = st.top()->getInteger();
        st.pop();
        return res;
    }

    bool hasNext() {
        while (!st.empty() && !st.top()->isInteger()) {
            const auto & nestedList = st.top()->getList();
            st.pop();
            for (auto rit = nestedList.rbegin(); rit != nestedList.rend(); rit++)
                st.push(&(*rit));
        }
        return !st.empty() && st.top()->isInteger();
    }
 
};


/* QUEUE Method
class NestedIterator {
    list<const NestedInteger*> q; 
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.begin(); it != nestedList.end(); it++)
            q.push_back(&(*it));
    }

    int next() {
        int res = q.front()->getInteger();
        q.pop_front();
        return res;
    }

    bool hasNext() {
        while (!q.empty() && !q.front()->isInteger()) {
            const auto & nestedList = q.front()->getList();
            q.pop_front();
            auto pos = q.begin();
            for (auto it = nestedList.begin(); it != nestedList.end(); it++)
                q.insert(pos, &(*it));
        }
        return !q.empty() && q.front()->isInteger();
    }
 
};  

*/

/**
 *  * Your NestedIterator object will be instantiated and called as such:
 *   * NestedIterator i(nestedList);
 *    * while (i.hasNext()) cout << i.next();
 *     */
