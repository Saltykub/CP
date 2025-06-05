#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int r,x;
    cin >> r >> x;
    if(x == 1){
        if(r >= 1600 && r <= 2999) cout << "Yes";
        else cout << "No";
    }
    else {
        if(r >= 1200 && r <= 2399) cout << "Yes";
        else cout << "No";
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