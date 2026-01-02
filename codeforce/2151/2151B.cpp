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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> a;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    int cur = 1;
    for(auto c:s){
        cur++;
        if(c == 'B'){
            while(a.count(cur)) cur++;
        }
        a.insert(cur);
        if(c == 'B'){
            while(a.count(cur)) cur++;
        }
    }
    cout << a.size();
    cout << "\n";
    for(auto u:a) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}