 #include<iostream>
using namespace std;

void fullpyramid(int n){

    for( int i=0 ; i<n ;i++){

        for(int j=0;j< n -i-1;j++)
            cout << " ";
        
        for( int j=0;j< i +1; j++)
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






