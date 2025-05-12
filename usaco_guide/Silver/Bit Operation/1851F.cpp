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
    ll n,k;
    cin >> n >> k;
    vector<pair<int,int>> m(n);
    for(int i = 0; i < n; i++) {
        cin >> m[i].st;
        m[i].nd = i+1;
    }
    sort(m.begin(),m.end());
    ll mn = INT_MAX, a, b, va, vb;
    for(int i = 0; i < n-1; i++){
        //cout << (m[i].st^m[i+1].st) << "\n";
        if((m[i].st^m[i+1].st) < mn){
            mn = (m[i].st^m[i+1].st);
            a = m[i].nd;
            va = m[i].st;
            b = m[i+1].nd;
            vb = m[i+1].st;
        }
    }
    ll x = 0;
    for(int i = 0; i < k; i++){
        if(((1<<i)&va) == ((1<<i)&vb)){
             if(((1<<i)&va) == 0) x+=(1<<i);
        }
    }
    cout << a << " " << b << " "<< x << "\n";
    //cout << ((3^12)&(1^12));
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}