#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int mod = 1e9+7;
bool CASE = false;

ll bpow(ll a, ll b){
    if(b == 0) return 1;
    ll ret = bpow(a,b/2);
    if(b%2 ==  0){
        return (ret*ret) % mod;
    }
    return (ret*ret*a)%mod;
}
void solve (){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    priority_queue<ll> pq;
    vector<ll> temp;
    temp = arr;
    sort(temp.begin(),temp.end());
    ll ans = 0;
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j < temp.size(); j++){
            for(int k = j+1; k < temp.size(); k++){
                if(pq.size() < i) pq.push((temp[j]+temp[k]));
                else {
                    if(pq.top() > (temp[j]+temp[k])){
                        pq.pop();
                        pq.push((temp[j]+temp[k]));
                    }
                    else {
                        break;
                    }
                }
            }
        }
        temp.clear();
        while(!pq.empty()){
            temp.pb(pq.top());
            pq.pop();
        }
        sort(temp.begin(),temp.end());
        ll x = temp[0];
        ans += x*bpow(2,i-1)%mod;
        ans%=mod;
        for(int i = 0; i < temp.size(); i++) temp[i]-=x;
        //for(auto u:temp) cout << u << " ";
        //cout << "\n";
    }
    cout << ans%mod;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}