#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

int main() {
    int n, target;
    
    cout << "Enter the number of elements in the array: ";
   cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
   cin >> target;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
