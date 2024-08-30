#include <iostream>
using namespace std;

pair<int,int> checktwosum(int arr[],int n,int target){
    pair<int,int> ans=make_pair(-1,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]+arr[j]==target){
                 ans.first= arr[i];
        ans.second=arr[j];
        return ans;

            

            }
        }
    }
}

int main(){
    int arr[]={10,20,30,40};
    int n= sizeof (arr)/ sizeof (arr[0]);
    pair<int,int> ans = checktwosum(arr,n,60);
    if(ans.first==-1 && ans.second == -1){
        cout<<"pairnot forund"<< endl;

    }
    else{
        cout<<"pair found "<<ans.first<<" , "<<ans.second<<endl;
    }
 

}