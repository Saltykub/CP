#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int main(){
   int n,m,k;
   cin >> n >> m >> k;
   ll a[n], b[m];
   for(int i = 0; i < n;i++) cin >> a[i];
   for(int i = 0; i < m;i++) cin >> b[i];
   sort(a,a+n);
   sort(b,b+m);
   int j = 0;
   int ans = 0; 
   for(int i = 0; i < n;i++){
        while(b[j] < a[i] - k){
            j++;
            if(j == m) break;
        }
        if(j == m) break;
        if(b[j] >= a[i]-k && b[j] <= a[i]+k){
            j++;
            ans++;
        }
        if(j == m) break;
   }
   cout << ans;
}