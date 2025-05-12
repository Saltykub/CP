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
    ll n,l,r;
    cin >> n >> l >> r;
    vector<ll> arr(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    priority_queue<ll,vector<ll>,greater<ll>> pql,pqr;
    vector<ll> lr;
    ll ans1 = 0, ans2 = 0;
    for(int i = 1; i < l; i++)pql.push(arr[i]);
    for(int i = l; i <= r; i++) lr.pb(arr[i]);
    for(int i = r+1; i <= n; i++) pqr.push(arr[i]);
    sort(lr.begin(),lr.end(),greater<int>());
    //cout << "PASS";
    for(int i = 0; i < lr.size(); i++){
        if(!pql.empty()){
            if(pql.top() < lr[i]){
                ans1+=pql.top();
                pql.pop();
            }
            else ans1+=lr[i];
        }
        else ans1+=lr[i];
    }
    for(int i = 0; i < lr.size(); i++){
        if(!pqr.empty()){
            if(pqr.top() < lr[i]){
                ans2+=pqr.top();
                pqr.pop();
            }
            else ans2+=lr[i];
        }
        else ans2+=lr[i];
    }
    cout << min(ans1,ans2) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}