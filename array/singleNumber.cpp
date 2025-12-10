class Solution{
public:
    int singleNumber(vector<int>& nums){ // Finds the single element that appears only once.
        int end = nums.size();
	if(end==0) return {};
	else{
		 		unordered_map<int, int> freq_map; // Stores frequency of each number
		for(int i:nums){ // Populate the map with frequencies of each number
			freq_map[i]++;
		}
		for(auto const& pair : freq_map){ // Iterate through the map to find the number with a frequency of 1
			if(pair.second==1) {// the  value of the key
				return pair.first;
			}
		}
	}
    }
};
