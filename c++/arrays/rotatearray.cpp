#include <iostream>
using namespace std;

void rotate(int arr[],int size,int shift)
{
    int finalshift = shift%size;
    //no elemeents to shift
    if(finalshift==0){
        return;

    }
    // last n elemnets ko storre krna htemp m
    int temp[1000];
    int index=0;
    for(int i=size-finalshift;i<size;i++){
        temp[index]=arr[i];
        index++;

    }
    //step2:shift aray elemt by final shift palaces
    for(int i =size-1;i>=0;i--){
        arr[i]=arr[i-finalshift];

    }
    //step3: copy temp elemnets into original array
    for(int i =0; i<finalshift;i++){
        arr[i]=temp[i];
    }



}   


int main(){
    int arr[]={10,20,30,40,50,60};
    int size=6;
    int shift=2;

    cout<< "BEfore"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;


    }
    cout<<endl;
    rotate(arr,size,shift);
    cout<<"after"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;


    }
    
}