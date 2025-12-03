// This program rotates the elements of an array to the left by a given number of places.

// brute
/*class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
	if(nums.size()<=1)return;
	else{
	    	for(int i = 1; i<=k; i++){
			int first = nums[0];
			int end = nums.size();
			for(int j = 0; j<end-1 ; j++){
				nums[j]=nums[j+1];
			}

			nums[end-1]=first;
		}
	  }
    }
};*/

// optimal
class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
	k=k%num.size();
	vector<int> arr(k);
	int end = nums.size();
	for(int i=0; i < k; i++){ // copy only the first k-1 terms.
		arr[i]=nums[i];
	}
	for(int j=k; j<end; j++){
		nums[j-k]=nums[j];
	}
	int temp=end-k;
	for(int z = 0;z<k;z++){
		nums[temp+z]=arr[z];
	}
	return;
    }
};
