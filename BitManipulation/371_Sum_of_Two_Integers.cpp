// Total Accepted: 30714
// Total Submissions: 59405
// Difficulty: Easy
// 0ms 100%

class Solution {
public:
    int getSum(int a, int b) {
        while (b) { // b != 0
            int carr = (a & b) << 1;
            a = a ^ b;
            b = carr;
        }
        return a;
    }
};