
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool possibleSol(vector<int> cookranks, int np, int mid) {
    int currentp = 0;
    
    for(int i = 0; i < cookranks.size(); i++) {
        int j = 1;
        int timetaken = 0;
        int R = cookranks[i];
        
        while(true) {
            if(timetaken + j * R <= mid) {
                currentp++;
                timetaken += j * R;
                j++;
            }
            else {
                break;
            }
        }
        if(currentp >= np) {
            return true;
        }
    }
    return false;
}

int minTime(vector<int> cookranks, int np) {
    int s = 0;
    int highestrank = *max_element(cookranks.begin(), cookranks.end());
    int e = highestrank * np * (np + 1) / 2;
    int ans = -1; 

    while(s <= e) {
        int mid = s + (e-s) / 2;
        if(possibleSol(cookranks, np, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1; 
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int np, nc;
        cin >> np >> nc;
        vector<int> cookranks;
        for(int i = 0; i < nc; i++) {
            int R;
            cin >> R;
            cookranks.push_back(R);
        }
        cout << minTime(cookranks, np) << endl;
    }
    return 0;
}