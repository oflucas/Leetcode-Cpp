// Total Accepted: 122311
// Total Submissions: 246617
// Difficulty: Easy
// 6ms 100%

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};