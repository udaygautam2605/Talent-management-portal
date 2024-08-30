#include <iostream>
using namespace std;
#include <limits.h>



int findMax(int arr[],int size){
    int maxans= INT_MIN;
    for(int i =0;i<size; i++){
        maxans=max(maxans,arr[i]);
    }
    return maxans;

}
void  zerosandones(int arr[],int size){
    int zero=0;
    int one=0;
    for(int i =0;i<size;i++){
        int current = arr[i];
        if (current==0){
            zero++;
        }

        if (current==1){
            one++;
        }
    }
    cout << "total zeros" << zero<<endl;
    cout << "total one" << one <<endl;
}

// void extremeprinting(int arr[];int size)
// {
//     int i =0;
//     int j= n-1;
//     while(i<=j){
//         if(i==j){
//             cout << arr[i]<< " ";
//             break;

//         }
//         else{
//         cout<<arr[i];
//         i++;
//         cout<< arr[j];
//         j--;

//     }

// }

int main()
{
    int arr[100];
    int size;
    cout<< "Enter the size of array"<< endl;
    cin >> size;

    for(int i =0;i<size;i++){
        cout << " enter the elment of index" << i << endl;
        cin>>arr[i];



    }
    // int target;
    // cout<<"enter the value of target"<< endl;
    // cin >> target;
    
    
    cout << "max no is" << findMax(arr,size)<< endl;
   zerosandones(arr,size);

   //extremeprinting(arr[],size);
    






}

