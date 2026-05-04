//brute force approach

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int len = nums.size();
//         if(len==0) return 0;
//         int max = INT_MIN;
//         int curr = 1;
//         for(int i = 0; i < len; i++){
//             for(int j = i; j < len; j++){
//                 if(max < nums[j]*curr){
//                     max = nums[j]*curr;
//                     curr = max;
//                 }
//                 else{
//                     curr = curr*nums[j];
//                 }
//             }
//             curr = 0;
//         }
//         return max;
//     }
// };

