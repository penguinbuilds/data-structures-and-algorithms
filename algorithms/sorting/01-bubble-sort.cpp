#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            int temp;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }            
        }    
    }
}

int main() {

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

    bubbleSort(arr);

    cout << "The sorted array is: ";
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    cout << endl;

    return 0;
}