// brute making each  part of the array as a subarray.
/*
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
       int end =  nums.size();
	if(end==0) return 0;
	int temp=0;
	int max_length=0;
	for(int i=0; i < end; i++){
		int max_sum=0;
		for(int j=i; j < end; j++){
			max_sum+=nums[j];
			if(max_sum==k){
				temp=j-i+1;
				if(temp>max_length){
					max_length=temp;
				}
			}
		}
	}
	return max_length;
    }
};  // time complexity  = O(n^2).
*/

// optimal


class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
	int end = nums.size();
	if(end==0) return 0;
	int prefix_sum=0;
	int max_length=0;
	int rem=0;
	unordered_map<int,int> prefix_hash_map;
	for(int i=0; i < end; i++){
		prefix_sum+=nums[i];
		if(prefix_sum==k){
			max_length = max(max_length, i+1);
			rem=prefix_sum-k;
			if(prefix_hash_map.find(prefix_sum)==prefix_hash_map.end()){
				prefix_hash_map[prefix_sum]=i;  // key : prefix_sum , value : index where we found the subarray to be equal to k.
			}
		}
	}
    }
};
