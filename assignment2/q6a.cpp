#include <iostream>
using namespace std;

int main() {
    int rows, cols, terms;
    cout << "Enter rows, cols, and number of non-zero elements: "<<endl;
    cin >> rows >> cols >> terms;

    int sparse[terms][3];   
    cout << "Enter row, col, value  "<<endl;
    for (int i = 0; i < terms; i++) {
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
    }

    cout << "Transpose Matrix in triplet form:"<<endl;
    for (int i = 0; i < terms; i++) {
        cout << sparse[i][1] << " " << sparse[i][0] << " " << sparse[i][2] << endl;
    }
}


