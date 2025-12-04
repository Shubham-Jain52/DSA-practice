#include <vector>

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
	int size1 = nums1.size();
	int size2 = nums2.size();
	if(size1 == 0 && size2 == 0)return {};

	vector<int> arr; // Initialize as empty

	int i=0,j=0; 

	while(i < size1 && j < size2){
		if(nums1[i]==nums2[j]){
            if (arr.empty() || arr.back() != nums1[i]) {
			    arr.push_back(nums1[i]);
            }
			i++;
			j++;
		}
		else if(nums1[i]<nums2[j]){
            if (arr.empty() || arr.back() != nums1[i]) {
			    arr.push_back(nums1[i]);
            }
			i++;
		}
		else{ 
            if (arr.empty() || arr.back() != nums2[j]) {
			    arr.push_back(nums2[j]);
            }
			j++;
		}
	}

	while(i<size1){
        if (arr.empty() || arr.back() != nums1[i]) {
		    arr.push_back(nums1[i]);
        }
		i++;
	}

	while(j<size2){
        if (arr.empty() || arr.back() != nums2[j]) {
		    arr.push_back(nums2[j]);
        }
		j++;
	}
	return arr; 
    }
};
