#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    ll ans;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if(x1 == x2) {
        ans = abs(x1-x3);
    }
    else ans = abs(x1-x2);
    if(y1 == y2){
        ans *= abs(y1-y3);
    }
    else ans *= abs(y1-y2);
    cout<< ans <<"\n";
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