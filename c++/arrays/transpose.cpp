#include <iostream>
using namespace std;

void transpose(int arr[][3], int n, int m) {
    int ans[100][100] = {0}; // Ensure the temporary array is large enough to handle larger matrices

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j][i] = arr[i][j]; // Transpose logic: row becomes column and vice versa
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < m; i++) { // Note the swapped dimensions for printing
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[3][3] = {
        {10, 20, 6},
        {20, 40, 45},
        {40, 60, 6}
    };
    int n = 3; // row size
    int m = 3; // column size

    cout << "Original matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transposed matrix:" << endl;
    transpose(arr, n, m);

    return 0;
}
