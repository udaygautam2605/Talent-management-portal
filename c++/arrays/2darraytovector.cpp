 #include <iostream>
using namespace std;


    vector<vector<int> > arr(4,vector <int> (3,0));
    bool searc(vector<vector<int> > arr,taget){
    int m=arr.size();
    int n = arr.[0].size();

    for(int i=0;i<m;i++){
        for(int j=0;j<n:j++){
            if(arr[i][j]== target){
                return true;
            }
        }
    }
    return false;
}
int main(){
    
}