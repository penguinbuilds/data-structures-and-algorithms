#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
int linearSearch(vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
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
    
    int index = linearSearch(arr, target);
    if (index == -1) {
        cout << "Target element not found." << endl;
    } else {
        printf("Target element found at index position %d.\n", index);
    }

    return 0;
}