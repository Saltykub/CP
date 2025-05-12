#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
void solve (){
    int n;
    cin >> n;
    vector<pair<int,int>> one,two;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i+j)%2)one.pb({i,j});
            else two.pb({i,j});
        }
    }
    ll nn = n*n;
    int o = 0, t = 0;
    while(nn--){
        int a; 
        cin >> a;
        if(a == 3){
            if(o!=one.size()){
                cout << 1 << " " << one[o].st << " " << one[o].nd << endl;
                o++;
            }
            else {
                cout << 2 << " " << two[t].st << " " << two[t].nd << endl;
                t++;
            }
        }
        else if(a == 2){
            if(o!=one.size()){
                cout << 1 << " " << one[o].st << " " << one[o].nd << endl;
                o++;
            }
            else {
                cout << 3 << " " << two[t].st << " " << two[t].nd << endl;
                t++;
            }
        }
        else if(a == 1){
            if(t!=two.size()){
                cout << 2 << " " << two[t].st << " " << two[t].nd << endl;
                t++;
            }
            else {
                cout << 3 << " " << one[o].st << " " << one[o].nd << endl;
                o++;
            }
        }
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {   
        solve();
    }

}