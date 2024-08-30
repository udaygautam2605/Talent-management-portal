#include<iostream>
using namespace std;


int main(){
    int length;
    int width;
    cout << "Enter length" << endl;
    cin >> length;

    cout<< "Enter width"<< endl;
    cin >> width;

    for(int i=0; i<length; i++){

        for(int j=0;j<=width;j++){
            if(i==0 || i ==length-1){
                cout<< "*";

               
            }

            else{
                if(j==0||j==width-1){
                    cout<<"*";




                }

                else{
                    cout<<" ";
                }
                
            }

            

        }

        cout << endl;
    }
    cout<<endl;




}