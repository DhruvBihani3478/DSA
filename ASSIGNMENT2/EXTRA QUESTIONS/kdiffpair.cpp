// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int i = 0, j = 1;
//         int count = 0;
//         while (i < n && j < n) {
//             if (i == j || nums[j] - nums[i] < k) j++; 
//             else if (nums[j] - nums[i] > k)  i++; 
//             else { 
//                 count++;
//                 i++;
//                 j++;
//                 while (i < n && nums[i] == nums[i-1]) i++;
//                 while (j < n && j < n && nums[j] == nums[j-1]) j++;
//             }
//         }
//         return count;
//     }
// };