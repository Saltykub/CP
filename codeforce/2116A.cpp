#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int a,b,c,d;
    cin >> a >> c >> b >> d;
    if(a >= c){
        if(b >= d || b >= c) {
            cout << "Gellyfish\n";
        }
        else {
            cout << "Flower\n";
        }
    }
    else {
        if(d > b || d > a){
            cout << "Flower\n";
        }
        else cout << "Gellyfish\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}