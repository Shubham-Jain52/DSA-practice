// This program finds the second smallest and second largest elements in an array.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX and INT_MIN

// A function to find both second smallest and second largest elements
void getSecondOrderElements(const std::vector<int>& arr, int n, int& sSmallest, int& sLargest) {
    if (n < 2) {
        // Not enough elements to find second order elements, indicate failure
        sSmallest = -1;
        sLargest = -1;
        return;
    }

    int smallest = INT_MAX;
    sSmallest = INT_MAX;
    int largest = INT_MIN;
    sLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Logic for smallest and second smallest
        if (arr[i] < smallest) {
            sSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < sSmallest && arr[i] != smallest) {
            sSmallest = arr[i];
        }

        // Logic for largest and second largest
        if (arr[i] > largest) {
            sLargest = largest;
            largest = arr[i];
        } else if (arr[i] > sLargest && arr[i] != largest) {
            sLargest = arr[i];
        }
    }
}

int main() {
    std::vector<int> arr = {12, 35, 1, 10, 34, 1};
    int n = arr.size();

    int secondSmallestResult;
    int secondLargestResult;

    getSecondOrderElements(arr, n, secondSmallestResult, secondLargestResult);

    std::cout << "Original Array: ";
    for(int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Check if a valid second smallest was found
    if (secondSmallestResult != INT_MAX && secondSmallestResult != -1) {
        std::cout << "Second Smallest Element: " << secondSmallestResult << std::endl;
    } else {
        std::cout << "No second smallest element found (array might have < 2 elements or all elements are the same)." << std::endl;
    }

    // Check if a valid second largest was found
    if (secondLargestResult != INT_MIN && secondLargestResult != -1) {
        std::cout << "Second Largest Element: " << secondLargestResult << std::endl;
    } else {
        std::cout << "No second largest element found (array might have < 2 elements or all elements are the same)." << std::endl;
    }

    return 0;
}