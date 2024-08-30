#include<iostream>
using namespace std;
#include<algorithm>

int main(){
    //using method
    // int a =5, b=7;
    // swap(a,b);
    // cout << a << b << endl;
    // return 0;
//using temp
    // int a =5 ,b=7;
    // int temp = a;
    // a = b;
    // b = temp;

    // cout << a << b << endl;

//arithmatic method
    // int a =5 ,b=7;
    // a = a+b;
    // b = a-b; // b=7

    // a = a - b;

    // cout << a << b << endl;
    // return 0;
   

   int a =5 ,b=7;
   a = a ^ b;
   b = b ^ a;
   a = a^ b ;
   cout << a << b << endl;
     return 0;


}