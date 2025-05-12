#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    vector<vector<char>> tab(q,vector<char>(70,'o'));
    while(q--){
        int p,q,r;
        cin >> p >> q >> r;
        p--;
        for(int i = q-1; i < min(q-1+r,70);i++) tab[p][i] = 'x';
    }
    for(auto row:tab){
        for(auto cell:row){
            cout << cell;
        }
        cout << endl;
    }
}