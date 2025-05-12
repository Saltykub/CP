#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
int tab[1005][1005];
int fw[1005][1005];
void u(int i,int y,int val){
    for(;i<1005;i+=(i&-i)){
        for(int j=y ;j<1005 ;j+=(j&-j)){
            fw[i][j] += val;
        }
    }
}
int qr(int i,int y){
    int ret=0;
    for(;i >0;i-=(i&-i)){
        for(int j = y;j >0;j-=(j&-j)){
            ret += fw[i][j];
        }
    }
    return ret;
}
int main(){
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        char c;
        cin>>c;
        if(c=='*'){u(i,j,1);tab[i][j]=1;}
    }
  }
  while(q--){
    int o;
    cin >> o;
    if(o == 2){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      cout<<qr(c,d)+qr(a-1,b-1)-qr(a-1,d)-qr(c,b-1)<<"\n";
    }
    else {
        int x,y;
        cin >> x >> y;
        if(tab[x][y]){
            tab[x][y]=0;
            u(x,y,-1);
        }
        else {
            tab[x][y]=1;
            u(x,y,1);
        }
    }
  }

}