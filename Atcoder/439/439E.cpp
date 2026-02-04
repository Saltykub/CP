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
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    vector<pii> v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    sort(all(v),[&](pii a, pii b){
        if(max(a.st,a.nd) == max(b.st,b.nd)) return min(a.st,a.nd) < min(b.st,b.nd);
        return max(a.st,a.nd) < max(b.st,b.nd);
    });
    int cnt = 1;
    pii cur = v[0];
    for(int i = 1; i < n; i++){
        if(min(v[i].st,v[i].nd) > max(cur.st,cur.nd)) {
            cnt++;
            cur = v[i];
        }
    }
    cout << cnt;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}