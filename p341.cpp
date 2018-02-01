/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push(nestedList.cbegin());
        ed.push(nestedList.cend());
    }

    int next() {
        int res = st.top()->getInteger();
        st.top()++;
        return res;
    }

    bool hasNext() {
        while (!st.empty() && (st.top() == ed.top() || !st.top()->isInteger())) {
            if (st.top() == ed.top()) {
                st.pop();
                ed.pop();
                if (!st.empty())
                    st.top()++;
            } else {
                ed.push(st.top()->getList().cend());
                st.push(st.top()->getList().cbegin());
            }
        }
        return !st.empty();
    }

private:
    typedef vector<NestedInteger>::const_iterator Citer;
    stack<Citer> st, ed;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
