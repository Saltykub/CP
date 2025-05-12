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
    int n,m;
    cin >> n >> m;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    while(m--){
        int q;
        cin >> q;
        auto it = s.upper_bound(q);
        if(it == s.begin()) cout << -1 << "\n";
        else {
            cout << *(--it) << "\n";
            s.erase(it);
        }
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