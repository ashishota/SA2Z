#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Brute {
 public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++) {
            int sum=0;
            for(int j=i;j<nums.size();j++) {
                sum+=nums[j];
                if(sum==k) {
                    count++;
                }
            }
        }
        return count;
    }
};

class Optimal {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> mpp;
            mpp[0] = 1;
            int n = nums.size();
            int count = 0;
            int preSum = 0;
            for(int i=0;i<n;i++) {
                preSum += nums[i];
                int remove = preSum - k;
                count += mpp[remove];
                mpp[preSum] += 1;
            }
            return count;
        }

};

int main() {
    vector<int> vec;
    vec={0,0,0,0,0,0,0,0,0,0};
    int k=0;
    // Brute code;
    // int res = code.subarraySum(vec,k);
    // cout<<res<<endl;
    Optimal code;
    int res = code.subarraySum(vec,k);
    cout<<res<<endl;

}