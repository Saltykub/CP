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
    int n;
    cin >> n;
    vll a(n), b(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    vector<int> sm(30,0), cnt(30,0);
    for(int i = 0; i < n; i++){
       for(int j = 0; j < 30; j++){
            int aa = ((1LL<<j)&a[i]);
            int bb = ((1LL<<j)&b[i]);
            sm[j]^=aa;
            sm[j]^=bb;
            if(aa != bb) cnt[j] = i;
       }
    }
    for(int i = 29; i >= 0; i--){
        if(sm[i]){
            if(cnt[i]%2){
                cout << "Mai\n";
            }
            else {
                cout << "Ajisai\n";
            }
            return;
        }
    }
    cout << "Tie\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}