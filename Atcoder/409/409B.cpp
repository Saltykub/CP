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
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    vector<int> cnt(120,0);
    for(auto u:v){
        if(u <= 100) cnt[u]++;
        else cnt[100]++;
    }
    for(int i = 118; i >= 0; i--){
        cnt[i] += cnt[i+1];
        if(cnt[i] >= i){
            cout << i;
            return;
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