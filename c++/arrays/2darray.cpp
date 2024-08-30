#include <iostream>
using namespace std;

bool searcharray(int arr[][4], int n, int m, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[3][4] = {
        {10, 20, 6, 0},
        {20, 40, 45, 0},
        {40, 60, 6, 0}
    };
    int n = 3; // row size
    int m = 4; // column size
    int target = 45;

    bool ans = searcharray(arr, n, m, target);
    cout << (ans ? "Element found" : "Element not found") << endl;

    return 0;
}
