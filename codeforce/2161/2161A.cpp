#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll r,x,d,n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '2'){
            if(r >= x) continue;
            cnt++;
        }
        else {
            r-=d;
            cnt++;
        }
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