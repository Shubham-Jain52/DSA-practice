class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int length = arr.size();
	if(length ==0) return -1;
	int min = INT_MAX;
	int min_i =0;
	for(int i=0; i < length; i++){
		if(arr[i]<min){
			min = arr[i];
			min_i = i;
		}
	}
	int max = INT_MIN;
	for(int j = min_i; j<length; j++){
		if(arr[j]>max){
			max=arr[j];
		}
	}
	if(max) return max-min;
	return min;
    }
};

