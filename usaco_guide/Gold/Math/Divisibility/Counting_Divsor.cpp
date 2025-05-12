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
    int x;
    cin >> x;
    int cnt = 0;
    for(int i = 1; i*i <= x; i++){
        if(x%i == 0) cnt += i * i == x ? 1 : 2;
    }
    cout << cnt << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}