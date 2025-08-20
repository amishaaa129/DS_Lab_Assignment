#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int up[n*(n+1)/2];
    cout << "Enter " << n*(n+1)/2 << " elements: ";
    for(int i=0;i<n*(n+1)/2;i++) cin >> up[i];

    cout << "Matrix:";
    int k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<=j) cout << up[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
