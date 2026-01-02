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
    ll n,k;
    cin >> n >> k;
    if(k%2){
        for(int i = 0; i < k; i++) cout << n << " ";
        cout << "\n";
    }
    else {
        vll a(k,0);
        for(ll i = 31; i >= 0; i--){
            if((1LL<<i)&n){
                a[0] += (1LL<<i);
                for(int j = 2; j < k; j+=2){
                    if(a[j] + (1LL<<i) <= n){
                        a[j-1] += (1LL<<i);
                        a[j] += (1LL<<i);
                    }
                }
            }
            else {
                for(int j = 1; j < k; j+=2){
                    if(a[j] + (1LL<<i) <= n){
                        a[j-1] += (1LL<<i);
                        a[j] += (1LL<<i);
                    }
                }
            }
            sort(all(a));
        }
        for(auto u:a) cout << u << " ";
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
      
    // for(int test = 1; test <= 30; test++){
    //     ll sm = 0;
    //     ll x = 0, y = 0;
    //     for(int i = 0; i <= test; i++){
    //     for(int j = 0; j <= test; j++){
    //         if((i^j) == test){
    //             if(i+j > sm){
    //                 sm = i+j;
    //                 x = i, y = j;
    //                 }
    //             }
    //         }
    //     }
    //     //cout << x << " " << y << " " << sm << "\n";
    //     cout << sm << "\n";
    // }
    
}
