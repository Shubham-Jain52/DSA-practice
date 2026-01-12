class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return [];
	vector<int> leftProducts;
	for(int i = 0; i < length; i++){
		if(i==0){
			leftProducts.push_back(1);
		}
		else{
			leftProducts.push_back(nums[i-1]*leftProducts[i-1]);
		}
	}
	vector<int> rightProducts;
	for(int i = length; i>0; i--){
		if(i==length){
			rightProducts.push_back(1);
		}
		else{
			rightProducts.push_back(nums[i+1]*rightProducts[i+1]);
		}
	}
    }
};
