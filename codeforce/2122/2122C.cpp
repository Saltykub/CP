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
    vector<pair<pii,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].st.st >> v[i].st.nd;
        v[i].nd = i+1;
    }
    sort(v.begin(),v.end(),[&](pair<pii,int> a, pair<pii,int> b){
          if(a.st.st == b.st.st){
               return a.st.nd < b.st.nd;
          }
          return a.st.st < b.st.st;
    });
    map<int,int> mpx, mpy;
    for(int i = 0; i < n/2; i++){
        mpx[v[i].nd] = 1;
    }
    for(int i = n/2; i < n; i++){
        mpx[v[i].nd] = 2;
    }
     sort(v.begin(),v.end(),[&](pair<pii,int> a, pair<pii,int> b){
          if(a.st.nd == b.st.nd){
               return a.st.st < b.st.st;
          }
          return a.st.nd < b.st.nd;
    });
     for(int i = 0; i < n/2; i++){
        mpy[v[i].nd] = 1;
    }
    for(int i = n/2; i < n; i++){
        mpy[v[i].nd] = 2;
    }
    vector<int> ff,fs,sf,ss;
    for(int i = 0; i < n; i++){
        auto [a,b] = v[i];
        if(mpx[b] == 1 && mpy[b] == 1) ff.pb(b);
        if(mpx[b] == 1 && mpy[b] == 2) fs.pb(b);
        if(mpx[b] == 2 && mpy[b] == 1) sf.pb(b);
        if(mpx[b] == 2 && mpy[b] == 2) ss.pb(b);
    }
    for(int i = 0; i < ff.size(); i++) cout << ff[i] << " " << ss[i] << "\n";
    for(int i = 0; i < sf.size(); i++) cout << sf[i] << " " << fs[i] << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}