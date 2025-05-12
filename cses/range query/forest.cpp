#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
int tab[1005][1005];
int main(){
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        char c;
        cin>>c;
        if(c=='*')tab[i][j]=1;
        else tab[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        tab[i][j]+=tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1];
    }
  }
  while(q--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<tab[c][d]+tab[a-1][b-1]-tab[a-1][d]-tab[c][b-1]<<"\n";
  }

}