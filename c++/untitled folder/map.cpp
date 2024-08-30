#include<iostream>
#include<map>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int ,int> map ;
    map[1]=23;
    map[2]=34;
    map[3]=45;
    map[4]=56;

    unordered_map<int ,int > :: iterator it;

    for( it= map.begin();it != map.end(); it++ ){
   
        int key = it ->  first;
        int value = it -> second;
        cout << "key" << key <<" " << "value" << value << endl;

    }
    // if( map.find(2) == map.end()){
    //     int value = map[2];
    //     cout << value;
    // }
    // else{
    //     cout << "not found ";
    // }
    if (map.find(4) != map.end()) {
        int value = map[4];
        cout << "Value for key 4: " << value << endl;
    } else {
        cout << "Key 34 not found" << endl;
    }

    // Check if the key 56 is present in the map
    if (map.find(2) != map.end()) {
        int value = map[2];
        cout << "Value for key 2: " << value << endl;
    } else {
        cout << "Key 56 not found" << endl;
    }
    map.erase(2); // delte hogyi key 2;


     if (map.find(2) != map.end()) {
        int value = map[2];
        cout << "Value for key 2: " << value << endl;
    } else {
        cout << "Key 2 not found" << endl;
    }

    
}