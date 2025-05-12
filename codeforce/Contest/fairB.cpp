#include <bits/stdc++.h>
using namespace std;
#define ll int
const int N=55;
ll x[N],y[N];
 
int main(){
  int t;
  int i,j,w;
  ll m,n,k;
  ll sumx;
  ll minx,miny,maxx,maxy;
  cin >>t;
  while(t--){
    maxx=0;maxy=0;sumx=0;
    minx=1e9+100;
    miny=1e9+100;
    cin >>n >>m >>k;
    fill_n(x, n+3,0);
    fill_n(y, m+3,0);
    for(i=0;i<n;i++){
      cin >>x[i];
      if(minx>=x[i]){
        minx=x[i];
      }
      if(maxx<=x[i]){
        maxx=x[i];
      }
      if(i>0 && i<n-1){
        sumx+=x[i];
      }
      
    }
    for(j=0;j<m;j++){
      cin >>y[j];
      if(miny>=y[j]){
        miny=y[j];
      }
      if(maxy<=y[j]){
        maxy=y[j];
      }
    }
    // if(w==1){
    //   minx=maxy;
      
    // }
    // if(maxx>maxy){
    //   if(w%2==1 && minx<=maxy){
    //     minx=maxy;
    //   }
    //   else if(w%2==1 && minx>=maxy){
      
    //   }
    //   else if(w%2==0 && minx<=maxy){
    //     minx=miny;
    //     maxx=maxy;
    //   }
    //   else{
    //    maxx=miny;
    //   }
    // }
    // else{
    //   if(w%2==1 && minx<=miny){
    //     minx=maxy;
    //   }
    //   else if(w%2==1 && minx>=miny){
    //     minx=maxy;
    //   }
    //   else if(w%2==0 && minx>=miny){
    //     minx=miny;
        
    //   }
    //   else{
       
    //   }
    // }
    if(maxx>=maxy){
      if(minx>=miny){
        if(w%2==1){

        }
        else{
          maxx=maxy;
        }
      }
      else{
        if(w%2==1){
          minx=miny;
        }
        else{
          maxx=minx;
          minx=miny;
          
        }
      }
    }
    else if(maxx<miny){
      if(w%2==1){
        minx=maxy;
      }
      else{
 
      }
    }
    else if(maxx<=maxy){
      if(minx>=miny){
        if(w%2==1){
          minx=maxy;
        }
        else{
          maxx=miny;
        }
      }
      else{
        if(w%2==1){
          minx=maxy;
        }
      }
    }
    
    if(n==1){
      cout <<maxx <<"\n";
    }
    else{
      sumx=sumx+maxx+minx;
      cout <<sumx <<"\n";
    }
    
    
  }
}