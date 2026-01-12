#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        // Edge Case: Handle empty or null array gracefully.
        if (len == 0) {
            return 0; // Or handle as an error, depending on requirements.
        }

        // AHA MOMENT #1: Correct Initialization
        // Initialize max values AND the corresponding subarrays with the first element.
        // This ensures the logic works correctly even if the max subarray is just the first element
        // or if the loop doesn't run at all (for single-element arrays).
        int current_max = nums[0];
        int global_max = nums[0];
        vector<int> currSubarr = {nums[0]};
        vector<int> globalSubarr = {nums[0]};

        for (int i = 1; i < len; i++) {
            // AHA MOMENT #2: The core of Kadane's Algorithm.
            // At each step, we decide: is it better to extend the current subarray with the new
            // element (current_max + nums[i]), or to start a fresh subarray beginning
            // with just the new element (nums[i])?
            int temp_current_max = current_max;
            current_max = max(nums[i], current_max + nums[i]);

            // Now, we update our "working copy" subarray based on that choice.
            if (current_max == nums[i]) {
                // We started a fresh subarray, so clear the old one and start new.
                currSubarr.clear();
                currSubarr.push_back(nums[i]);
            } else {
                // We extended the subarray, so just add the new element.
                currSubarr.push_back(nums[i]);
            }

            // AHA MOMENT #3: Saving the "Final Version"
            // If the current_max has produced a new global_max, we must save a COPY
            // of our "working" currSubarr into our "final version" globalSubarr.
            // This prevents our final answer from being overwritten later in the loop.
            if (current_max > global_max) {
                global_max = current_max;
                globalSubarr = currSubarr;
            }
        }

        printf("The maximum subarray is: ");
        for (int i = 0; i < globalSubarr.size(); i++) {
            printf("%d ", globalSubarr[i]); // Added space for readability
        }
        printf("\n");

        // Finally, return the integer value as required by the function signature.
        return global_max;
    }
};
