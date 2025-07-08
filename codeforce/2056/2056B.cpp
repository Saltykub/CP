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
    int n;
    cin >> n;
    vector<string> s(n); 
    for(int i = 0; i < n; i++) cin >> s[i];   
    vector<int> ans(n);
    iota(ans.begin(),ans.end(),0);
    sort(ans.begin(),ans.end(),[&](int a,int b){
       if(s[a][b] == '1') return a < b;
       else return a > b;
    });
    for(auto u:ans) cout << u+1 << " ";
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