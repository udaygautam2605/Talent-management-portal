#include <iostream>
using namespace std;

void findfirstoccurance(int arr[], int n, int target, int &ansIndex) {
    int s = 0;
    int e = n - 1;
    ansIndex = -1;  // Initialize ansIndex to -1 to indicate target not found
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            ansIndex = mid; // value store krli for store and compute
            e = mid - 1; // Move to the left half to find the first occurrence
        } else if (target > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
}
void findlastoccurance(int arr[], int n, int target, int &ansIndex) {
    int s = 0;
    int e = n - 1;
    ansIndex = -1;  // Initialize ansIndex to -1 to indicate target not found
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            ansIndex = mid; // value store krli for store and compute
            s = mid + 1; // Move to the right half to find the first occurrence
        } else if (target > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
}

int main() {
    int arr[] = {10, 20, 20,20,20, 40, 40, 50, 50, 60, 70};
    int n = 9; // Size of the array
    int target = 20;
    int ansIndex;

    findlastoccurance(arr, n, target, ansIndex);
    if (ansIndex != -1) {
        cout << "First occurrence index: " << ansIndex << endl;
    } else {
        cout << "Target not found in the array" << endl;
    }
    return 0;
}
