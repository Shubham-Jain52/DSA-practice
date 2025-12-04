
// This class provides a solution for the "Move Zeroes" problem.
class Solution {
public:
    // This function moves all the zeros in a vector to the end, 
    // while maintaining the relative order of the non-zero elements.
    // This is an optimal two-pointer approach.
    // Time Complexity: O(n) - We iterate through the array at most twice.
    // Space Complexity: O(1) - We are modifying the array in-place.
    void moveZeroes(vector<int>& nums) {
	int end = nums.size();
	if(end<=1)return;
	
        // Find the index of the first zero. 'j' will act as our "write" pointer.
		int j=-1;
		for(int i = 0; i<end; i++){
			if(nums[i]==0){
				j=i; // 'j' now points to the first zero.
				break;
			}
		}

		// If no zeros are found (j remains -1), the array is already as required.
        if (j == -1) {
            return;
        }
		
        // 'i' will be our "read" pointer, starting from after the first zero.
        // It will look for non-zero elements to swap into the 'j' position.
		for(int i = j+1; i<end; i++){
            // If we find a non-zero element
			if(nums[i]!=0){
                // Swap the non-zero element (at i) with the zero (at j)
				int temp = nums[j];
				nums[j]=nums[i];
				nums[i]=temp;
                // Increment 'j' to point to the next position that needs a non-zero number.
				j++;
			}
		}
	}
};

