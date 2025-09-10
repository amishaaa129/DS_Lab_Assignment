#include <iostream>
using namespace std;

int main() {
    int a[100], n;

    cout << "Enter the size of the array "<<endl;
    cin >> n;

    cout << "Enter the elements of the array"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int uniqueIndex = 0; 

    for (int i = 0; i < n; i++) {
        bool alreadyExists = false; 

        for (int j = 0; j < uniqueIndex; j++) {
            if (a[i] == a[j]) {
                alreadyExists = true;
                break;
            }
        }

        if (alreadyExists == false) {
            a[uniqueIndex] = a[i]; 
            uniqueIndex++; 
        }
    }

    cout << " Array after removing duplicates:"<<endl;
    for (int i = 0; i < uniqueIndex; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
