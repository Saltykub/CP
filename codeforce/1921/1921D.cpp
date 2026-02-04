#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n, m;
    cin >> n >> m;
    int a[n], b[m], b2[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0; i < m; i++) {cin >> b[i];}
    sort(a,a+n);
    sort(b,b+m,greater<int>());
    sort(b2,b2+m);
    ll ans = 0;
    int bk = -1;
    for(int i=0;i<n;i++){
        if(abs(a[i]-b[i])<abs(a[i]-b[i+(m-n)])){
            bk=i;
            break;
        }
        ans += abs(a[i]-b[i]);
    }
    int j=m-1;
    if(bk!=-1){
        for(int i=n-1;i>=bk;i--){
            ans+=abs(a[i]-b[j]);
            j--;
        }
    }
    cout<<ans<<"\n";
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