#include <iostream>
#include<algorithm>
using namespace std;

void sort(int arr[],int size){
    int zero=0;
    int one = 0;

    for (int i =0 ;i<size;i++){
        if (arr[i]==0){
            zero++;
        }
        if (arr[i]==1){
            one++;
        }
    }
    // int i =0;
    // for (;i<zero;i++){
    //     arr[i]=0;
    // }
    // for(;i<one ;i++){
    //     arr[i]=1;
    // }
    fill(arr,arr+zero,0);
    fill(arr+zero,arr+size,1);
    


}
 
 int main(){
    int arr[]={0,1,1,0,0,0,1,1};
    int size=sizeof(arr)/sizeof(arr[0]);

    sort(arr, size);
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;



     
 }
 //sort fuction se bhi hojaega
 