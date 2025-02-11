#include <iostream>
#include <vector>

using namespace std;

class Brute {
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

class Better {
public:
    void rotateMatrix(vector<vector<int>> matrix) {  
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> rowFlag(rows, 1), colFlag(cols, 1);
        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0)
                    rowFlag[i] = colFlag[j] = 0;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (rowFlag[i] == 0 || colFlag[j] == 0)
                    matrix[i][j] = 0;

        printMatrix(matrix);  
    }

    void printMatrix(const vector<vector<int>>& matrix) { 
        for (const auto& row : matrix) {
            for (int elem : row) cout << elem << " ";
            cout << endl;
        }
    }
};

class Optimal {
public:
    void rotateMatrix(vector<vector<int>> matrix) {  
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int col0=0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }          
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0]==0) {
            for(int j=0;j<cols;j++) {
                matrix[0][j]=0;
            }
        }
        if(col0==0) {
            for(int i=0;i<rows;i++) {
                matrix[i][0]=0;
            }
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

    Brute codeA;
    cout << "Brute Approach Output:\n";
    codeA.rotateMatrix(matrix);  
    
    // cout << "\nBetter Approach Output:\n";
    // Better codeB;
    // codeB.rotateMatrix(matrix); 

    // cout << "\nOptimal Approach Output:\n";
    // Optimal codeC;
    // codeC.rotateMatrix(matrix);

    return 0;
}
