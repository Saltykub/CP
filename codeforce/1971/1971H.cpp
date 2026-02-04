#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void add_edge(int n1, bool b1, int n2, bool b2, vector<pair<pii,pii>> &edge){
  edge.pb({{abs(n1),b1 ? 1 : 0},{abs(n2), b2 ? 1 : 0}});
}
void dfs1 (int node){
   
}
void solve (){
  int n;
  cin >> n;
  // pair of node and status
  vector<pair<pii,pii>> edge;
  int arr[3][n];
  for(int i = 0; i < 3; i++){
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
    }
  }
  // convert to com
  for(int i = 0; i < n; i++){
     add_edge(arr[0][i], arr[0][i] > 0, arr[1][i], arr[1][i] > 0,edge);
     add_edge(arr[0][i], arr[0][i] > 0, arr[2][i], arr[2][i] > 0,edge);
     add_edge(arr[1][i], arr[1][i] > 0, arr[2][i], arr[2][i] > 0,edge);
  }
  // do SCC
    
  

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
