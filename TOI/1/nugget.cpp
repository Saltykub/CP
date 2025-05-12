#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nug(1000,0);
    nug[6] = 1; nug[9] = 1; nug[20] = 1;
    for(int i = 0; i < 100; i++){
        if(nug[i]) {
            nug[i+6] = 1;
            nug[i+9] = 1;
            nug[i+20] = 1;
        }
    }
    if(n < 6) cout << "no";
    for(int i = 0; i <= n; i++)if(nug[i]) cout << i << "\n";
}