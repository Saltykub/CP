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
    vector<int> arr(n),pos(n+1,0),ch(n+1,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int l = (n+1)/2, r = (n+2)/2;
    while (l > 0 && (l == r || (pos[l] < pos[l + 1] && pos[r - 1] < pos[r]))) {
      --l;
      ++r;
    }
    cout << (n - r + l + 1) / 2 << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}