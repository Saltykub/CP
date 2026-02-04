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
    ll n,m,h;
    cin >> n >> m >> h;
    vll a(n);
    for(auto &u:a) cin >> u;
    queue<int> q;
    vll tmp = a;
    while(m--){
        ll b,c;
        cin >> b >> c;
        b--;
        if(tmp[b] + c > h){
            while(!q.empty()){
                int fr = q.front();
                q.pop();
                tmp[fr] = a[fr];
            }
        }
        else {
            tmp[b] += c;
            q.push(b);
        }
    }
    for(auto u:tmp) cout << u << " ";
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