#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int find(ll a,ll b){
    ll cnt = 0;
    while(true){
        if(b >= a) break;
        cnt ++;
        b*=b;
    }
    return cnt;
}
void solve (){
    int n;
    cin >> n;
    ll arr[n],start = -1,ans = 0;
    vector<int> p(n,0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] != 1){
            start = i;
            break;
        }
    }
    if(start == -1){
        cout << 0 << "\n";
        return;
    }
    for(int i = start+1; i < n; i++){
        if(arr[i] == 1) {
            cout << -1 << "\n"; 
            return;
        }
        if(arr[i] < arr[i-1]){
            p[i] = p[i-1] + find(arr[i-1],arr[i]);
            ans += p[i];
        }
        else if(arr[i] == arr[i-1]){
            ans += p[i-1];
            p[i] = p[i-1];
        }
        else {
             int ch = find(arr[i],arr[i-1]);
             if(p[i-1] >= ch){
                p[i] = p[i-1] - ch;
                if(pow(arr[i-1],pow(2,ch)) > arr[i]) p[i]++;
                ans += p[i];
             }
         }
        // cout << ans  << " ";
    }
    cout << ans << "\n";
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