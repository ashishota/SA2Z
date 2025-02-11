#include <iostream>
#include <vector>

using namespace std;

class Optimal {
public:
    void rotateMatrix(vector<vector<int>> matrix) {  
        int n = matrix.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        int j=0;
        while(j<n/2) {
            for(int i=0;i<n;i++) {
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
            j++;
        }
        printMatrix(matrix);  
    }

    void printMatrix(const vector<vector<int>>& matrix) { 
        for (const auto& row : matrix) {
            for (int elem : row) cout << elem << " ";
            cout << endl;
        }
    }
};


int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    Optimal codeA;
    cout << "Output:\n";
    codeA.rotateMatrix(matrix);  
    

    return 0;
}
