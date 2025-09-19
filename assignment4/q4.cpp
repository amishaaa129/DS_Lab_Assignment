#include <iostream>
using namespace std;

void firstNonRepeatingArray(string s)
{
    int freq[26] = {0};
    char q[1000];
    int front = 0, rear = -1;

    for (char ch : s)
    {

        freq[ch - 'a']++;

        q[++rear] = ch;

        while (front <= rear && freq[q[front] - 'a'] > 1)
        {
            front++;
        }

        if (front <= rear)
            cout << q[front] << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}

int main()
{
    string s = "aabc";
    firstNonRepeatingArray(s);
    return 0;
}