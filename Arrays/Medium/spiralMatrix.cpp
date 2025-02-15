#include<iostream>
#include<vector>

using namespace std;

class Optimal {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;  // Handle empty matrix case
    
        int rows = matrix.size();
        int cols = matrix[0].size();
    
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
    
        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;  // Move boundary down
    
            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;  // Move boundary left
    
            // Check if there are still rows left
            if (top <= bottom) {
                // Traverse from right to left
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;  // Move boundary up
            }
    
            // Check if there are still columns left
            if (left <= right) {
                // Traverse from bottom to top
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;  // Move boundary right
            }
        }
    
        return result;
    }
    
        void print(const vector<int>& vec) { 
            for (auto row : vec) {
                cout << row << " ";
            }
            cout << endl;
        }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    Optimal codeA;
    cout << "Optimal Approach Output:\n";
    vector<int> res=codeA.spiralOrder(matrix);  
    codeA.print(res);
    

    return 0;
}
