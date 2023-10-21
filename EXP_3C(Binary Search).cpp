#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found at index mid
        }

        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int n, target;
    
   cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

 cout << "Enter the element to search for: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << std::endl;
    } else {
       cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
