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
    ll n,m,q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    vector<ll> qsa(n+1), qsb(m+1);
    qsa[1] = a[0], qsb[1] = b[0];
    for(int i = 1; i < n; i++){
        qsa[i+1] += qsa[i] + a[i];
    }
    for(int i = 1; i < m; i++){
        qsb[i+1] += qsb[i] + b[i];
    }
    priority_queue<pii> pq;
    int cnt[n+m][2];
    for(int i = 0; i < n+m; i++) cnt[i][0] = cnt[i][1] = 0;
    for(auto x:a){
        pq.push({x,0});
    }
    for(auto x:b){
        pq.push({x,1});
    }
    int pt = 0;
    while(!pq.empty()){
        auto[val,idx] = pq.top();
        pq.pop();
        cnt[pt][idx]++;
        if(pt == 0){
            pt++;
            continue;
        }
        cnt[pt][0] += cnt[pt-1][0];
        cnt[pt][1] += cnt[pt-1][1];
        pt++;
    }
    while(q--){
        ll x,y,z;
        cin >> x >> y >> z;
        if(z == 0){
            cout << 0;
        }
        else if(x == 0 || y == 0){
            if(x == 0) cout << qsb[z];
            else cout << qsa[z];
        }
        else if(cnt[z-1][0] <= x && cnt[z-1][1] <= y){

            cout << qsa[cnt[z-1][0]] + qsb[cnt[z-1][1]];
        }
        else if(cnt[z-1][0] > x && cnt[z-1][1] <= y){
            cout << qsa[x] + qsb[z-x];
        }
        else {
            cout << qsa[z-y] + qsb[y];
        }
        cout << "\n";
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