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
void print(int a, int b, int c){
    cout << a << " " << b << " " << c;
}
void solve (){
    ll w,h,d;
    cin >> w >> h >> d;
    ll n; cin >> n;
    ll wc = -1, hc = -1, dc = -1;
    for(int i = 1; i <= sqrt(w); i++){
        if(w%i) continue;
        for(int j = 1; j <= sqrt(h); j++){
            if(h%j) continue;
            for(int k = 1; k <= sqrt(d); k++){
                if(d%k) continue;
                int i1 = i, i2 = w/i, j1 = j, j2 = h/j, k1 = k, k2 = d/k;
                if(i1*j1*k1 == n){
                    print(i1-1,j1-1,k1-1);
                    return;
                }
                if(i1*j1*k2 == n){
                    print(i1-1,j1-1,k2-1);
                    return;
                }
                if(i1*j2*k1 == n){
                    print(i1-1,j2-1,k1-1);
                    return;
                }
                if(i1*j2*k2 == n){
                    print(i1-1,j2-1,k2-1);
                    return;
                }
                 if(i2*j1*k1 == n){
                    print(i2-1,j1-1,k1-1);
                    return;
                }
                if(i2*j1*k2 == n){
                    print(i2-1,j1-1,k2-1);
                    return;
                }
                if(i2*j2*k1 == n){
                    print(i2-1,j2-1,k1-1);
                    return;
                }
                if(i2*j2*k2 == n){
                    print(i2-1,j2-1,k2-1);
                    return;
                }
            }
        }
    }
    cout << -1 << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}