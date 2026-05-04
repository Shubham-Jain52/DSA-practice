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

//best approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return 0;
        int biggest = nums[0];
        int local_biggest = nums[0];
        int local_smallest = nums[0];
        for(int i = 1; i < len; i++){
           int curr = nums[i];

           int temp_max = max({curr, curr*local_biggest, curr*local_smallest}); // finding the local biggest by comparing the current element, current element*local biggest and current element*local smallest.
           
           local_smallest = min({curr, local_biggest*curr, local_smallest*curr}); // finding the local smallest by comparing the current element, current element*local biggest and current element*local smallest.
           
           local_biggest = temp_max;

           biggest = max(biggest, local_biggest);
        }
        return biggest;
    }
};