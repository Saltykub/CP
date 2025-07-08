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
   priority_queue<int,vector<int>,greater<int>> pq;
   for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pq.push(x);
   }
   while(true){
      if(pq.size() == 1) break;
      int t1 = pq.top(), t2;
      pq.pop();
      t2 = pq.top();
      pq.pop();
      pq.push((t1+t2)/2);
   }
   cout << pq.top() << "\n";
   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}