  #include<iostream>
using namespace std;

void minpyramid(int n){

    for( int i=0 ; i<n ;i++){
        //stars

        for(int j=0;j< n -i;j++)
            cout << "*";
        
        for( int j=0;j< 2*i + 1; j++)
            cout<< " ";
        for(int j =0;j<n-i;j++)
        cout<< "*";
        cout << endl;
    }



    for( int i=0 ; i<n ;i++){
        //stars

        for(int j=0;j< i+1;j++)
            cout << "*";
        
        for( int j=0;j< 2 * (n-i)-1; j++)
            cout<< " ";
        for(int j =0;j<i+1;j++)
        cout<< "*";
        cout << endl;
    }
}





int main(){
    int n;
    
    

    cout<< "n"<< endl;
    cin >> n;
    minpyramid(n);
    return 0;
}






