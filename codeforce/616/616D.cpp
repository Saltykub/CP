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
    int n,k;
    cin >> n >> k;
    ll mx = 0, cur = 0;
    ll l = 1, r = 1;
    vector<int> v(n+1);
    multiset<int> s;
    for(int i = 1; i <= n; i++) cin >> v[i];
    int i = 1;
    for(int j = 1; j <= n; j++){
        if(s.find(v[j]) == s.end()){
            while(cur >= k){
                if(s.count(v[i]) == 1) cur--;
                s.erase(s.find(v[i]));
                i++;
            }
            cur++;
            s.insert(v[j]);
        }   
        else {
            s.insert(v[j]);
        }
        if(j-i+1 > mx){
            mx = j-i+1;
            l = i, r = j;
        }
    }
    cout << l << " " << r << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}