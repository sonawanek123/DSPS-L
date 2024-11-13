#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool binarySearch(string students[], int size, string target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid] == target) {
            return true;
        } else if (students[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int size;
    cout << "Enter the number of students who attended the training program: ";
    cin >> size;

    string students[size];

    cout << "Enter the names of the students: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> students[i];
    }

    sort(students, students + size);

    string target;
    cout << "Enter the name of the student to search: ";
    cin >> target;

    if (binarySearch(students, size, target)) {
        cout << target << " attended the training program." << endl;
    } else {
        cout << target << " did not attend the training program." << endl;
    }

    return 0;
}
