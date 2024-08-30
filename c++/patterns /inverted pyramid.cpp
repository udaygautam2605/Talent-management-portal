 #include<iostream>
using namespace std;

void fullpyramid(int n){

    for( int i=0 ; i<n ;i++){

//sapces 
        for(int j=0;j< i;j++)
            cout << " ";
  //stars      
        for( int j=0;j< n-i; j++)
            cout<< "* ";
        
        cout << endl;
    }
}





int main(){
    int n;
    
    

    cout<< "n"<< endl;
    cin >> n;
    fullpyramid(n);
    return 0;
}






