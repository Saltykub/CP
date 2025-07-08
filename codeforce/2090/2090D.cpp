#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e6+10;
bool CASE = true;
vector<int> prime(N);
vector<int> pr;
void init(){
    for(int i = 0; i < N; i++) prime[i] = 1;
    for(int i = 2; i < N; i++){
        if(prime[i]){
            pr.pb(i);
            for(int j = i+i; j < N; j+=i){
                prime[j] = 0;
            }
        }
    }
}
void solve (){
    int n;
    cin >> n;
    ll s = 1;
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    for(int i = 0; i < pr.size(); i++){
        if(pr[i] > n/3){
            s = pr[i];
            break;
        }
    }
    int go = 1;
    set<int> ss;
    for(int i = 1; i <= n; i++) ss.insert(i);
    for(int i = 0; i <= n; i++){
        if(i == 0) cout << s << " ",ss.erase(s);
        else if(i%2) cout << s-go << " ",ss.erase(s-go);
        else {
            cout << s+go << " ";
            ss.erase(s+go);
            go++;
        }
        if(s-go < 1 || s+go > n) break;
    }
    for(auto u:ss) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    init();
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}