#include <iostream>
using namespace std;

int main() {
    int t1, t2;
    cout << "Enter number of non-zero terms in Matrix A: ";
    cin >> t1;
    int A[t1][3];
    cout << "Enter row col val for A:\n";
    for (int i = 0; i < t1; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter number of non-zero terms in Matrix B: ";
    cin >> t2;
    int B[t2][3];
    cout << "Enter row col val for B:\n";
    for (int i = 0; i < t2; i++) cin >> B[i][0] >> B[i][1] >> B[i][2];

    cout << "\nResult of Addition (triplet form):\n";
    int i = 0, j = 0;
    while (i < t1 && j < t2) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            cout << A[i][0] << " " << A[i][1] << " " << A[i][2] + B[j][2] << endl;
            i++; j++;
        }
        else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
            i++;
        }
        else {
            cout << B[j][0] << " " << B[j][1] << " " << B[j][2] << endl;
            j++;
        }
    }
    while (i < t1) { cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl; i++; }
    while (j < t2) { cout << B[j][0] << " " << B[j][1] << " " << B[j][2] << endl; j++; }
}