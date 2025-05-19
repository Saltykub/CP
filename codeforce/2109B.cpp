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
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    ll n1 = n, m1 = b;
    ll ans1 = 1,ans2 = 1;
    while(true){
        if(n1 == 1 && m1 == 1)break;
        if(n1 > m1){
            n1 = (n1+1)/2;
        }
        else {
            m1 = (m1+1)/2;
        }
        ans1++;
    }
    n1 = a, m1 = m;
    while(true){
        if(n1 == 1 && m1 == 1)break;
        if(n1 > m1){
            n1 = (n1+1)/2;
        }
        else {
            m1 = (m1+1)/2;
        }
        ans2++;
    }
    n1 = n, m1 = m-b+1;
    ans1 = min(ans1,ans2);
    ans2 = 1;
    while(true){
        if(m1 == 0){
            ans2 = INT_MAX;
            break;
        } 
        if(n1 == 1 && m1 == 1)break;
        if(n1 > m1){
            n1 = (n1+1)/2;
        }
        else {
            m1 = (m1+1)/2;
        }
        ans2++;
    }
    n1 = n-a+1, m1 = m;
    ans1 = min(ans1,ans2);
    ans2 = 1;
    while(true){
        if(n1 == 0){
            ans2 = INT_MAX;
            break;
        } 
        if(n1 == 1 && m1 == 1)break;
        if(n1 > m1){
            n1 = (n1+1)/2;
        }
        else {
            m1 = (m1+1)/2;
        }
        ans2++;
    }
   // cout << ans1 << " " << ans2 << " ";
    cout << min(ans1,ans2) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}