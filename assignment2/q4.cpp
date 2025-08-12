#include <iostream>
using namespace std;

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
void concatenate(char str1[], char str2[]) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    for (int i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + len2] = '\0';
}
void reverseString(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
bool isVowel(char ch) {
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
void deleteVowels(char str[]) {
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}
void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}
int main() {
    char str1[100], str2[50];
    
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 50);
    concatenate(str1, str2);
    cout << "Concatenated String: " << str1 << endl;

    reverseString(str1);
    cout << "Reversed String: " << str1 << endl;

    deleteVowels(str1);
    cout << "Without Vowels: " << str1 << endl;

    char str3[50];
    cout << "Enter string to convert to lowercase: ";
    cin.getline(str3, 50);
    toLowercase(str3);
    cout << "Lowercase String: " << str3 << endl;
}