#include<iostream>
#include<vector>

using namespace std;

class Brute {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> vec;
            int i=0,j=0,k=0;
            int rows=matrix.size();
            int cols=matrix[0].size();

            int ub_row=0;
            int db_row=rows-1;
            int lb_col=0;
            int rb_col=cols-1;

            while(k!=(rows*cols)) {
                while(j<=rb_col && k!=(rows*cols)) {
                    vec.push_back(matrix[i][j]);
                    k++;
                    j++;
                }
                if(k==(rows*cols)) return vec;
                rb_col--;
                j--;
                i++;
                while(i<=db_row && k!=(rows*cols)) {
                    vec.push_back(matrix[i][j]);
                    k++;
                    i++;
                }
                if(k==(rows*cols)) return vec;
                db_row--;
                i--;
                j--;
                while(j>=lb_col && k!=(rows*cols)) {
                    vec.push_back(matrix[i][j]);
                    k++;
                    j--;
                }
                if(k==(rows*cols)) return vec;
                lb_col++;
                j++;
                i--;
                while(i>ub_row && k!=(rows*cols)) {
                    vec.push_back(matrix[i][j]);
                    k++;
                    i--;
                }
                if(k==(rows*cols)) return vec;
                ub_row++;
                i++;
                j++;
                
            }

            return vec; 
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

    Brute codeA;
    cout << "Brute Approach Output:\n";
    vector<int> res=codeA.spiralOrder(matrix);  
    codeA.print(res);
    
    // cout << "\nBetter Approach Output:\n";
    // Better codeB;
    // codeB.rotateMatrix(matrix); 

    // cout << "\nOptimal Approach Output:\n";
    // Optimal codeC;
    // codeC.rotateMatrix(matrix);

    return 0;
}
