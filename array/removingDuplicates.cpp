// This program removes duplicate elements from a sorted array in-place.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<int> arr = {1,1,2,2,2,3,3,3,4,5};
	if(arr.size() <=1) return arr;
	else{
	int j = 1; // pointer of last unique number
	for (int i =1; i < arr.size(); i++){
		if(arr[i] != arr[i-1]){ // moving pointer
			arr[j]=arr[i];
			j++;
		}
	   }
	}
	return 0;
}
