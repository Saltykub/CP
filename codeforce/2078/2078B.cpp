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
    ll n,k;
    cin >> n >> k;
    if(k%2){
        for(int i = 0; i < n-2; i++) cout << n << " ";
        cout << n << " " << n-1 << "\n";
    }
    else {
        for(int i = 0; i < n-2; i++) cout << n-1 << " ";
        cout << n << " " << n-1 << "\n";
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