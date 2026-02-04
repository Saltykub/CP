#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    ll a,b,r;
    cin >> a >> b >> r;
    bool one = false;
    char go = 'a';
    ll mx = 0,cur = 0,curr=0;
    for(int i = 62; i >= 0; i--){
        //cout << (1<<i) <<"\n";
        ll pw = pow(2,i);
        if((1ll<<i)&a && !((1ll<<i)&b)){
              if(!one) {
                one = true;
                mx = pw;
              }
              else {
              if(go == 'a'){
                cur += pw;
              }else {
                mx -= pw;
              }
              }
        }
        else if(!((1ll<<i)&a) && (1ll<<i)&b){
             if(!one) {
                one = true;
                go = 'b';
                mx = pw;
             }
             else {
             if(go == 'b'){
                cur += pw;
             }
             else {
                mx -= pw;
             }
             }
        }
        
    }
    //cout << mx << " " << cur << "\n ";
    for(int i = 62; i >= 0;i--){
        if((1ll<<i)&cur){
            ll pw = pow(2,i);
            if(curr + pw <= r){
                curr += pw;
            }
            else {
                mx += pw;
            }
        }
    }
    cout << abs(mx-curr) <<"\n";
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