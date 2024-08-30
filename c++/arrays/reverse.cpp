#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = n - 1; i >= 0; i--) {
    //     cout << arr[i] << " ";
    // }
    // int reversed[n];

    // for(int i=0;i<n;i++){
    //      reversed[i]= arr[n-i-1];

    // }
    // for(int i=0;i<n;i++){
    //     cout<< reversed[i]<<" ";
    // }

    int l =0 , h= n-1;
    while (l<h){
        swap(l++,h--);

    }
    cout << l << h;

    return 0;
}
