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
    freopen("rental.in","r",stdin);
    ll n,m,r;
    cin >> n >> m >> r;
    vector<ll> cow(n),rent(r),preff(n,0),prefb(n,0);
    vector<pii> buy(m);
    for(int i = 0; i < n; i++) cin >> cow[i];
    for(int i = 0; i < m; i++) cin >> buy[i].nd >> buy[i].st;
    for(int i = 0; i < r; i++) cin >> rent[i];
    sort(cow.begin(),cow.end());
    sort(rent.begin(),rent.end(),greater<ll>());
    sort(buy.begin(),buy.end(),greater<pii>());
    ll mx = 0;
    for(int i = 0; i < min(n,r); i++){
        preff[i] = rent[i];
    }
    for(int i = 1; i < n; i++) preff[i] += preff[i-1];
    int j = 0;
    for(int i = n-1; i >= 0; i--){
        if(j < m){
            while(j < m){
                if(buy[j].nd <= cow[i]){
                    prefb[i]+=buy[j].nd*buy[j].st;
                    cow[i]-=buy[j].nd;
                    j++;
                }
                else {
                    prefb[i] += cow[i]*buy[j].st;
                    buy[j].nd -= cow[i];
                    break;
                }
            }
        }
        else break;
    }
    //cout << "PASS";
    //for(int i = 0; i < n; i++) cout << prefb[i] << "\n";
    for(int i = n-2; i >= 0; i--){
        prefb[i] += prefb[i+1];
    }
    for(int i = 0; i < n-1; i++){
        // cout << prefb[i] << "\n";
        mx = max(mx,preff[i]+prefb[i+1]);
    }
    mx = max({mx,preff[n-1], prefb[0]});
    freopen("rental.out", "w", stdout);
    cout << mx;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
