 #include<iostream>
using namespace std;

void fullpyramid(int n){

    for( int i=0 ; i<n ;i++){

        for(int j=0;j< 2*i+1;j++)
            if(j%2==0)
            cout << i+1;
            else
            cout<<"*";
       
        
       cout<< endl;
    }



    for( int i=0 ; i<n ;i++){

        for(int j=0;j< 2*(n-i)-1;j++)
            if(j%2==0)
            cout << n-i; //for printing at even places
            else
            cout<<"*";
       
        
       cout<< endl;
    }
    
}





int main(){
    int n;
    
    

    cout<< "n"<< endl;
    cin >> n;
    fullpyramid(n);
    return 0;
}






