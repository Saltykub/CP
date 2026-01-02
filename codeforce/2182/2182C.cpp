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
    vll a(n), b(n), c(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    for(auto &u:c) cin >> u;
    set<int> s1,s2;
    for(int i = 0; i < n; i++) s1.insert(i),s2.insert(i);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int idx = (j-i+n)%n;
            if(a[i] >= b[j]) {
                if(s1.count(idx)){
                    s1.erase(idx);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int idx = (j-i+n)%n;
            if(b[i] >= c[j]) {
                if(s2.count(idx)){
                    s2.erase(idx);
                }
            }
        }
    }
    // cout << s1.size() << "\n";
    // cout << s2.size() << "\n";
    cout << n* s1.size() * s2.size() << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}