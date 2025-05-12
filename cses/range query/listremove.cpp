#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
int fw[N],h[N];
void add(int pos,int val){
    for(;pos<N;pos+=(pos&-pos)){
        fw[pos]+=val;
    }
}
int qs(int pos){
    int ret=0;
    for(;pos>0;pos-=(pos&-pos)){
        ret+=fw[pos];
    }
    return ret;
}
int main(){
    int n;
    cin>>n;
    int q=n;
    for(int i=1;i<=n;i++){cin>>h[i];add(i,1);}
    while(q--){
        int x;
        cin>>x;
        int l=1,r=n;
        while(l<r){
            int mid=(l+r+1)/2;
            //cout<<l<<" "<<r<<" "<<qs(mid)<<"\n";
            if(qs(mid)>x)r=mid-1;
            else if(qs(mid)==x&&h[mid]==0)r=mid-1;
            else l=mid;
        }
        cout<<h[l]<<" ";
        h[l]=0;
        add(l,-1);
    }
    
}