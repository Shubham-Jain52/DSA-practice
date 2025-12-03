// This program rotates the elements of an array to the left by one position.

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
	if(nums.size() <=1) return;
	int first = nums[0];
	for(int i=0; i < nums.size()-1; i++){
		nums[i]=nums[i+1];
	}
	nums[nums.size()-1]=first;
    }
};
