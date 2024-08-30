#include <iostream>
using namespace std;

int findarray(int arr[][4], int n, int m) {
    
    int minvalue=INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            minvalue=min(minvalue,arr[i][j]);
           
            }
        }
        return minvalue;
}
    


int main() {
    int arr[3][4] = {
        {10, 20, 6, 0},
        {20, 40, 45, 0},
        {40, 60, 6, 0}
    };
    int n = 3; // row size
    int m = 4; // column size
    

   int minVlaue = findarray(arr,n,m);
   cout<< "Minimum value in the array is:"<<minVlaue<<endl;
    return 0;
}

//time complexity 
//rowsize*colsize
//space complexity 
// O(1)
