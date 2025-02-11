#include <iostream>
#include <vector>

using namespace std;

class Brute {
public:
    void setMatrixToZeroes(vector<vector<int>> matrix) {  
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < cols; k++) matrix[i][k] = -1;
                    for (int k = 0; k < rows; k++) matrix[k][j] = -1;
                }
            }
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == -1) matrix[i][j] = 0;
        
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
    void setMatrixToZeroes(vector<vector<int>> matrix) {  
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
    void setMatrixToZeroes(vector<vector<int>> matrix) {  
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
    vector<vector<int>> matrix = {{0, 1, 2, 1}, {3, 4, 0, 2}, {1, 3, 1, 5}};

    Brute codeA;
    cout << "Brute Approach Output:\n";
    codeA.setMatrixToZeroes(matrix);  
    
    cout << "\nBetter Approach Output:\n";
    Better codeB;
    codeB.setMatrixToZeroes(matrix); 

    cout << "\nOptimal Approach Output:\n";
    Optimal codeC;
    codeC.setMatrixToZeroes(matrix);
    return 0;
}
