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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        if(v[i]%2==v[n-1]%2) break;
        ans1++;
    }
    for(int j = n-1; j >= 0; j--){
        if(v[j]%2 == v[0]%2) break;
        ans2++;
    }
    ans1 = min(ans1,ans2);
    cout << ans1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}