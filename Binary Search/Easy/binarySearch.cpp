#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int low = 0, high = n - 1;
    int ans = -1; 

    while (low <= high) {  // Corrected condition
        int mid = low + (high - low) / 2; // Move mid inside the loop

        if (arr[mid] == target) {
            ans = mid;
            break;  // Exit loop when target is found
        } 
        else if (arr[mid] > target) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }

    cout << ans << endl; // Output the index of the target
    return 0;
}
