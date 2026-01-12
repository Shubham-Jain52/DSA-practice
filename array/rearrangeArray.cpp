class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int Global_len = nums.size();
	if(Global_len == 0) return{};
	vector<int> NegSubArr;
	vector<int> PosSubArr;
	for(int i = 0; i < Global_len; i++){
		if(nums[i]<0){
			NegSubArr.push_back(nums[i]);
		}
		else{
			PosSubArr.push_back(nums[i]);
		}
	}
	int k = 0;
	vector<int> FinalArr;
	while(k < Global_len/2){
		FinalArr.push_back(PosSubArr[k]);
		FinalArr.push_back(NegSubArr[k]);
		k++;
	}
	return FinalArr;
    }
};
