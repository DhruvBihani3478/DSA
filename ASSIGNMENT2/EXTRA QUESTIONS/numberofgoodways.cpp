// class Solution {
// public:
//     int numSplits(string s) {
//         vector<int> left(26, 0), right(26, 0);
//         int distinctLeft = 0, distinctRight = 0, res = 0;
//         for (char c : s) if (right[c - 'a']++ == 0) distinctRight++;
//         for (char c : s) {
//             if (left[c - 'a']++ == 0) distinctLeft++;
//             if (--right[c - 'a'] == 0) distinctRight--;
//             if (distinctLeft == distinctRight) res++;
//         }
//         return res;
//     }
// };
