#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(logn)
int binarySearch(vector<int> arr, int target, int low, int high) {
    int mid = (low + high)/2;
    if (high >= low) {
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target){
            return binarySearch(arr, target, low, mid-1);
        } else {
            return binarySearch(arr, target, mid+1, high);
        }
    }    
    return -1;
}

int main() {

    int target;
    int temp;
    int arr_size;
    vector<int> arr;

    cout << "Enter the size of the array: ";
    cin >> arr_size;

    for (int i = 0; i < arr_size; i++) {
        cout << "Enter element: ";
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Enter the target element: ";
    cin >> target;

    int index = binarySearch(arr, target, 0, arr_size);
    if (index == -1) {
        cout << "Target element not found." << endl;
    } else {
        printf("Target element found at index position %d.\n", index);
    }

    return 0;
}