class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      	// Aha Moments for Longest Consecutive Sequence Problem (Sorting Method):
	// 1. Initial Approach: Sorting the array is a good first step as it brings consecutive elements together.
	// 2. Handling Duplicates: When iterating through the sorted array, if 'nums[i] == nums[i-1]' (diff == 0),
	//    it means we encountered a duplicate. This duplicate should be skipped ('continue')
	//    without affecting the current streak, as it neither extends nor breaks the sequence.
	// 3. Resetting Streak: If 'nums[i]' is not consecutive to 'nums[i-1]' (diff != 1 and diff != 0),
	//    the current streak is broken. The 'current_longest' streak should be reset to 1 (for 'nums[i]' itself),
	//    not 0, because 'nums[i]' starts a new potential consecutive sequence.
	// 4. Correct Sorting Syntax: The standard C++ way to sort a vector is 'std::sort(vec.begin(), vec.end())'.
	//    This requires '#include <algorithm>'. Also, '#include <vector>' is needed for std::vector.
	// 5. Loop Bounds: Ensure the loop correctly handles array boundaries, specifically 'i-1' access.
	//    Starting 'i' from 1 and iterating up to 'len-1' is a common pattern when comparing 'nums[i]' with 'nums[i-1]'.
	// 6. Empty Array Edge Case: For an empty array, the length of the longest consecutive sequence is 0.
      	int len = nums.size();	if(len==0) return 0;
	int current_longest = 1;
	int global_longest = 1;
	sort(nums.begin(), nums.end());
	for(int i = 1; i < len; i++){
		int diff = nums[i] - nums[i-1];
		if(diff==0){
			continue;
		}
		if(diff!=1){
			current_longest = 1;
		}
		else{
			current_longest = current_longest+1;
		}
		global_longest = max(global_longest,current_longest);
	}
	return global_longest;
    }
};
