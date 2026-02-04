#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
    int n,m;
    cin >> n >> m;
    char tab[n][m];
    int mxr = 0, mxc = 0,r,c;
    for(int i = 0; i < n; i ++) for(int j = 0; j < m; j++) cin >> tab[i][j];
    for(int i = 0; i < n; i++){
        int sm = 0;
        for(int j = 0; j < m; j++) {
            if(tab[i][j] == '#') sm++;
        }
       // cout << sm << " ";
        if(sm > mxc){
            mxc = sm;
            c = i;
        }
    }
    for(int i = 0; i < m; i++){
        int sm = 0;
        for(int j = 0; j < n; j++) {
            if(tab[j][i] == '#') sm++;
        }
        if(sm > mxr){
            mxr = sm;
            r = i;
        }
    }
    cout << c+1 << " " << r+1 << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}