class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      	// Aha Moments for Leaders Problem:
	// 1. Initial thought was to compare 'nums[i]' with 'nums[i+1]', but a leader must be
	//    strictly greater than *all* elements to its right.
	// 2. The most efficient approach is to iterate from right to left (end of array to start).
	// 3. While iterating from right-to-left, maintain a 'global_max' which stores the maximum
	//    element encountered *so far* from the right.
	// 4. An element 'nums[i]' is a leader if it is strictly greater ('>') than the 'global_max'
	//    of elements to its right. Using '>=' would be incorrect.
	// 5. The rightmost element is *always* a leader. It should be the first element added
	//    to the result and used to initialize 'global_max'.
	// 6. The loop bounds are crucial: Ensure the loop processes 'nums[0]' by using 'i >= 0'.
      	int len = nums.size();
	if(len==0) return {};
	vector<int> leaders;
	if(len==1) {
		leaders.push_back(nums[0]);
		return leaders;
	}
	int global_max=nums[len-1];
	leaders.push_back(nums[len-1]);
	for(int i = len-2; i >= 0; i--){
		if(nums[i]>global_max){
			leaders.push_back(nums[i]);
		}
		global_max = max(global_max,nums[i]);
	}
	reverse(leaders.begin(),leaders.end());
	return leaders;
    }
};
