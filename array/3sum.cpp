// Brute Force Solution: 

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0) return {};
//         set<vector<int>> result;
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < len; i++){
//             for(int j = i+1; j < len; j++){
//                 for(int k = j+1; k < len; k++){
//                     if(nums[i]+nums[k]+nums[j] == 0){
//                         result.insert({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> res(result.begin(),result.end());
//         return res;

//     }
// };

// Optimal Solution:
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0) return {};
//         set<vector<int>> triplets;
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < len; i++){
//             int mid = i+1; 
//             int high = len - 1;
//             while(mid < high){
//                 int sum = nums[i]+nums[mid]+nums[high];
//                 if(sum == 0){
//                     triplets.insert({nums[i],nums[mid],nums[high]});
//                     mid++;
//                     high--;
//                 }
//                 else if(sum < 0){
//                     mid++;
//                 }
//                 else{
//                     high--;
//                 }
//             }
//         }
//         vector<vector<int>> result(triplets.begin(),triplets.end());
//         return result;

//     }
// };