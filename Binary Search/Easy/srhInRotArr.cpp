#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Update mid inside the loop

            if (arr[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (arr[mid] >= arr[low]) {
                if (target >= arr[low] && target < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (target > arr[mid] && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example input: rotated sorted array
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 6;

    int result = sol.search(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
