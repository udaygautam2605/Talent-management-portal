#include <iostream>
using namespace std;

// int rowSum(int arr[][4], int n, int m) {
    
//     int minvalue=INT_MAX;
//     for (int i = 0; i < n; i++) {
//         int sum=0;
//         for (int j = 0; j < m; j++) {
//            sum=sum+arr[i][j];
           
//             }
//             cout << sum << endl;
//         }

//}
// int colSum(int arr[][4], int n, int m) {
    
    
//     for (int i = 0; i < m; i++) {
//         int sum=0;
//         for (int j = 0; j < n; j++) {
//            sum=sum+arr[j][i];
           
//             }
//             cout << sum << endl;
//         }

// }

// int diaSum(int arr[][3], int n) {
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += arr[i][i]; // Sum the main diagonal elements
//     }
//     return sum;
// }

int diaSum(int arr[][3], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j == m - 1) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int arr[3][3] = {
        {10, 20, 6},
        {20, 40, 45},
        {40, 60, 6}
    };
    int n = 3; // row size
    int m = 3; // column size

    int sum = diaSum(arr, n, m);
    cout << "Sum of the opposite diagonal is: " << sum << endl;

    return 0;
}