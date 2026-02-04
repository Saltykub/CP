#include<bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define pii pair<ll,ll>
#define pb push_back
using namespace std;
void solve()
{
    ll n,k;
    cin >> n >> k;
    if(k <= 4*n-4){
        cout << int(ceil(1.0*k/2));
    }
    else {
        cout << k-4*n+4+2*n-2;
    }
    cout << "\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}