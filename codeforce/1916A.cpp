#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int n,k;
    cin >> n >> k;
    long long mul = 1;
    while(n--){
        int x;
        cin >> x;
        mul*=x;
    }
    if(mul>2023 || 2023%mul != 0)cout<<"NO";
    else {
        cout <<"YES" <<"\n";
        cout << 2023/mul << " ";
        for(int i = 1; i < k; i++)cout << 1 <<" ";
    }
    cout << "\n";
}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        
        solve();
    }
}