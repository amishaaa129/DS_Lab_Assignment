#include<iostream>
using namespace std;

int main() {
    const int max = 100;
    int a[max];
    int n = 0; // current size of array
    int choice;

    while (true) {
        cout << "\nEnter the operation you wish to perform:" << endl;
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter size of the array: ";
                cin >> n;
                if (n > max) {
                    cout << "Size exceeds max limit!" << endl;
                    n = 0;
                    break;
                }
                cout << "Enter elements of the array:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> a[i];
                }
                cout << "Array created successfully!" << endl;
                break;
            }

            case 2: {
                if (n == 0) {
                    cout << "Array is empty. Please create it first." << endl;
                } else {
                    cout << "Displaying the array:" << endl;
                    for (int i = 0; i < n; i++) {
                        cout << a[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 3: {
                int pos, element;
                cout << "Enter the position where you wish to insert the element (0-based index): ";
                cin >> pos;
                cout << "Enter the element you wish to insert: ";
                cin >> element;

                if (pos < 0 || pos > n || n >= max) {
                    cout << "Invalid position or array full." << endl;
                } else {
                    for (int i = n; i > pos; i--) {
                        a[i] = a[i - 1];
                    }
                    a[pos] = element;
                    n++;
                    cout << "Element inserted successfully!" << endl;
                }
                break;
            }

            case 4: {
                int pos;
                cout << "Enter the position of the element you wish to delete (0-based index): ";
                cin >> pos;
                if (pos < 0 || pos >= n) {
                    cout << "Invalid position." << endl;
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        a[i] = a[i + 1];
                    }
                    n--;
                    cout << "Element deleted successfully!" << endl;
                }
                break;
            }

            case 5: {
                int element;
                cout << "Enter the element you wish to search: ";
                cin >> element;
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (a[i] == element) {
                        cout << "Element found at position: " << i << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Element not found in the array." << endl;
                }
                break;
            }

            case 6: {
                cout << "Exiting the program." << endl;
                return 0;
            }

            default:
                cout << "Invalid choice! Please select between 1 to 6." << endl;
        }
    }
}
