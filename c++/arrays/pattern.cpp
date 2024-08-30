#include <iostream>
using namespace std;

void printpair(int arr[],int size)
{
    for(int i =1;i<size ;i++){
        for(int j=0;j<i+1;j++){
            cout<<arr[i]<<" "<<arr[j]<<" ";
        }
    }
}   


int main(){
    int arr[]={10,20,30,40};
    int size= sizeof (arr)/ sizeof (arr[0]);
printpair(arr,size);
}