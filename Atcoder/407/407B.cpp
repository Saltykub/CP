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
    int x,y;
    cin >> x >> y;
    set<pii> cnt;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            if(i+j >= x) cnt.insert({i,j});
            if(abs(i-j) >= y) cnt.insert({i,j});
        }
    }
    double ans = 1.0*cnt.size()/36;
    printf("%.10lf",ans);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}