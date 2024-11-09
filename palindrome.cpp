#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& input) {
    int left = 0;
    int right = input.length() - 1;

    while (left < right) {
        if (input[left] != input[right]) {
            return false; // Not a palindrome if characters don't match
        }
        left++;
        right--;
    }
    return true; // All characters matched
}

int main() {
    string input;


    cout << "Enter the string: ";
    cin >> input;


    if (isPalindrome(input)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }

    return 0;
}
