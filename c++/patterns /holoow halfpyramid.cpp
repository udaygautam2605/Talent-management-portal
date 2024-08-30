 #include<iostream>
using namespace std;


int main(){
    int n;
    int j;

    cout<<"enter n"<< endl;
    cin>> n;

    for(int i =0; i<n;i++){

        int totalColumn=i+1;
        for(j=0;j<totalColumn;j++){

        if(i==0||i==n-1||j==0||i== j){
            cout<< "*";

        }
        else{
            cout <<" ";
        }
        }
        cout<< endl;
    }
    
    
    }




    