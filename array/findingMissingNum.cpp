// brute
/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int size = nums.size();
       if(size==0) return 0;
	else{
		sort(nums.begin(), nums.end());
		for(int i=0; i<size; i++){
			if(nums[i]!=i) return i;
		}
		return nums[size-1]+1;
    	}
    }
}; // time complexity = O(nlogn)
*/

// optimal 

class Solution {
public:
    // NOTE: Function should be renamed to 'missingNumber'.
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
	if(size==0) return 0;
	else{
		// Calculate the sum of numbers present in the array.
		int sum=0;
		for(int i=0; i<size; i++){
			sum+=nums[i];
		}

		// Calculate the expected sum of all numbers from 0 to n (size).
		// The standard formula is: n * (n + 1) / 2
		int max_sum = size;   
		for(int j=0; j<size; j++){
			max_sum+=j;
		}

		// The difference between the expected and actual sum is the missing number.
		int diff = max_sum - sum;
		return diff;
	}
    }
};  // time complexity = O(N)
