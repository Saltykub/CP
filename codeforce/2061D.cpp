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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    map<int,int> mp;
    vector<ll> b(m);
    ll sm1 = 0, sm2 = 0;
    for(int i = 0; i < n; i++) cin >> a[i], sm1+=a[i];
    for(int i = 0; i < m; i++) cin >> b[i], sm2+=b[i];
    for(auto u:a){
        mp[u]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto u:b){
        if(mp[u]) mp[u]--;
        else {
            pq.push(u);
        }
    }
    if(sm1 != sm2){
        cout << "No\n";
        return;
    }
    while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        if(mp[top]){
            mp[top]--;
        }
        else {
            if(top == 1) {
                cout << "No\n";
                return;
            }
            pq.push(top/2);
            pq.push((top+1)/2);
        }
    }
    cout << "Yes\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}