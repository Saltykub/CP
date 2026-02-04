#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n,s1=0,f1=0;
    cin >> n;
    string s,f;
    cin >> s >> f;
    for(int i = 0; i < n; i++){
        if(f[i] == '1' && s[i] == '1') continue;
        if(s[i]=='1')s1++;
        if(f[i]=='1')f1++;
    }
    cout << abs(s1-f1) + min(f1,s1) <<"\n";
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