class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
	if(len == 0) return;
	int pivotIndex=-1;
	for(int i=len-1; i > 0; i--){
		if(nums[i-1]<nums[i]){
			pivotIndex = i-1;
			break;
		}
	}
	if(pivotIndex==-1){
		reverse(nums.begin(), nums.end());
		return;
	}
	int nextSmallest = nums[pivotIndex];
	for(int j = len-1; j>pivotIndex; j--){
		if(nums[j] > nextSmallest){
			swap(nums[pivotIndex], nums[j]);
			break;
		}
	}
	reverse(nums.begin()+pivotIndex+1, nums.end());
    }
};
