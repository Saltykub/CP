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
    int n,x;
    cin >> n >> x;
    for(int i = 0; i <= x-1; i++){
        cout << i << " ";
    }
    for(int i = x+1; i <n; i++) cout << i << " ";
    if( x < n) cout << x;
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}