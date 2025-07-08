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
    set<int> s;
    multiset<int> ms;
    int j = 0;
    vector<int> v(n);
    ll ans = 0;
    for(auto &x:v) cin >> x;
    for(int i = 0; i < n; i++){
        if(s.count(v[i])){
            ms.insert(v[i]);
            ans += i-j+1;
        }
        else {
            if(s.size() < k){
                s.insert(v[i]);
                ms.insert(v[i]);
                ans += i-j+1;
            }
            else {
                while(s.size() != k-1){
                    if(ms.count(v[j]) != 1){
                        ms.erase(ms.find(v[j]));
                    }
                    else {
                        s.erase(v[j]);
                        ms.erase(v[j]);
                    }
                    j++;
                }
                s.insert(v[i]);
                ms.insert(v[i]);
                ans += i-j+1;
            }
        }
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}