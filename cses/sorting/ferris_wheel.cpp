#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int main(){
   int n,x;
   cin >> n >> x;
   int a[n];
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a,a+n);
   deque<int> dq;
   int ans = 0;
   for(int i = 0; i < n; i++) dq.push_front(a[i]);
   
   while(!dq.empty()){
      int sm = 0;
      sm += dq.front();
      dq.pop_front();
      if(!dq.empty() && sm + dq.back() <= x){
            sm += dq.back();
            dq.pop_back();
      }
      ans++;
      sm = 0;
   }
   cout << ans;
}