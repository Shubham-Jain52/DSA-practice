  // * Algorithm: Dutch National Flag / 3-way Partitioning
  // * Time Complexity: O(N) (single pass through the array)
  // * Space Complexity: O(1) (in-place sorting)
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int len = nums.size();
	if(len == 0) return;
	int mid=0,low=0,high=len-1;
	while(mid<=high){
		if(nums[mid]==0){
			int temp = nums[low];
			nums[low]=nums[mid];
			nums[mid]=temp;
			low++;
			mid++;
		}
		else if(nums[mid]==2){
			int temp = nums[high];
                       	nums[high]=nums[mid];
                       	nums[mid]=temp;
			high--;// we don't move mid here as we don't know weather the number that high replaced is 0 or 1 so until the next iteration we can't move mid.
		}
		else{
			mid++;
		}
	}
    }
};
