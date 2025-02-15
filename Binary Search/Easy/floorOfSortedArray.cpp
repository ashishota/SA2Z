//{ Driver Code Starts
#include<iostream>
#include<vector>

using namespace std;


// } Driver Code Ends
class Solution {
    public:
        int findFloor(vector<int>& arr, int k) {
            int ans = -1;
            int low = 0, high = arr.size() - 1;
        
            while (low <= high) {
                int mid = low + (high - low) / 2;  // Move this inside the loop
                
                if (arr[mid] <= k) {
                    ans = mid;  // Update ans with mid
                    low = mid + 1;  // Search on the right
                } else {
                    high = mid - 1;  // Search on the left
                }
            }
            return ans;
        }
    
};


//{ Driver Code Starts.
int main() {
    vector<int> arr={1,2,8,10,11,12,19};
    int k=0;
    Solution code;
    int res=code.findFloor(arr,k);
    cout<<res<<endl;
    return 0;
}
// } Driver Code Ends