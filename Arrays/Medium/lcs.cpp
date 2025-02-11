#include<iostream>
#include<vector>
#include<unordered_set>

int longest_consecutive_sequence(std::vector<int>& arr) {
    int n=arr.size();
    if(n==0) {
            return 0;
    }
    std::unordered_set<int> numSet(arr.begin(),arr.end());
    int longestStreak=0;
    for (int num:numSet) {
	    if(numSet.find(num-1) == numSet.end()) {
		    int currentNum = num;
		    int currentStreak = 1;

		    while(numSet.find(currentNum+1) != numSet.end()) {
			    currentNum++;
			    currentStreak++;
		    }

		    longestStreak = std::max(longestStreak,currentStreak);

	    }
    }
    return longestStreak;
}

int main() {
    std::vector<int> arr = {0,-1};
    int x=longest_consecutive_sequence(arr);
    std::cout<<x<<std::endl;
}
