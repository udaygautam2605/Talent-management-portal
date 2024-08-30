#include <iostream>
using namespace std;

void alltriplets(int arr[],int size)
{
    for(int i =1;i<size ;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
            cout<<arr[i]<<", "<<arr[j]<<" ,"<<arr[k]<<endl;
        }
    }
}   
}


int main(){
    int arr[]={10,20,30,40};
    int size= sizeof (arr)/ sizeof (arr[0]);
alltriplets(arr,size);
}