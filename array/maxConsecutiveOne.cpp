class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_streak = 0;    // Stores the maximum consecutive ones found
        int current_streak = 0; // Stores the current consecutive ones count
        
        // Iterate through each number in the array
        for (int num : nums) {
            if (num == 1) {
                current_streak++; // Increment current streak if it's a '1'
            } else {
                // If it's a '0', the streak is broken.
                // Update max_streak with the longest streak found so far.
                max_streak = max(max_streak, current_streak);
                current_streak = 0; // Reset current streak
            }
        }
        
        // Return the maximum of max_streak and current_streak
        // (important for cases where the array ends with ones)
        return max(max_streak, current_streak);
    }
};

