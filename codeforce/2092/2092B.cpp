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
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    bool can = true;
    int one = 0, zero = 0;
    for(int i = 0; i < n; i+=2) if(a[i] == '1') one++;
    for(int i = 1; i < n; i+=2) if(b[i] == '0') zero++;
    if(zero < one) can = false;
    one = 0;
    zero = 0;
    for(int i = 1; i < n; i+=2) if(a[i] == '1') one++;
    for(int i = 0; i < n; i+=2) if(b[i] == '0') zero++;
    if(zero < one) can = false;
    cout << ((can) ? "YES\n" : "NO\n");
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}