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
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    bool can = false;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i] && a[i] == 'o') can = true;
    }
    if(can) cout << "Yes";
    else cout << "No";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}