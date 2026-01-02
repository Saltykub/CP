#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
   int h,w,n;
   cin >> h >> w >> n;
   int arr[h][w];
   map<int,int> mp;
   for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> arr[i][j];
   for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
   }
   int mx = 0;
   for(int i = 0; i < h; i++){
    int cnt = 0;
    for(int j = 0; j < w; j++){
        if(mp[arr[i][j]]) cnt++;
    }
    mx = max(mx,cnt);
   }
   cout << mx;

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}