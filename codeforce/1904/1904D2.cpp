#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+1;
int fw[N][3]; //fw[0] know that there is number greater or not 
//fw[1] find the lowest 
//fw[2] update array 
void add(int i,int val,int j){
    for(;i<N;i+=(i&-i)){
        fw[i][j]+=val;
    }
}
int query(int i,int j){
    int ret=0;
    for(;i>0;i-=(i&-i)){
        ret+=fw[i][j];
    }
    return ret;
}
void solve(){
    int n;
    cin>>n;
    pii a[n+1],b[n+1];
    for(int i=1;i<=n;i++){cin>>a[i].st;a[i].nd=i;}
    for(int i=1;i<=n;i++){cin>>b[i].st;b[i].nd=i;}
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)fw[i][1]=fw[i][2]=fw[i][0]=0;
    for(int i=1;i<=n;i++)add(i,1,0);
    vector<int> v,use;
    int i=1,j=1;
    while(true){
        if(a[i].st<b[j].st){
            add(a[i].nd,-1,0);
            i++;
        }
        else if(a[i].st==b[j].st){
            while(a[i].st==b[j].st){
                add(a[i].nd,-1,0);
                add(a[i].nd,1,1);
                v.pb(a[i].nd);
                i++;
                if(i==n+1)break;
            }
            while(b[j].st==a[i-1].st){
                int l=1,r=b[j].nd;
                int target=query(r,1);
                int debug=0;
                bool can1=true,can2=true;
                while(l<r){
                    if(target==0)break;
                    int mid=(l+r)/2;
                    if(query(mid,1)>=target)r=mid;
                    else l=mid+1;
                   
                }
              
                if(!target||query(b[j].nd,2)-query(l-1,2)!=0||query(b[j].nd,0)-query(l,0)!=0){
                   can1=false;
                }
                l=b[j].nd+1;r=n;
                if(query(r,1)-query(l-1,1)==0)target=0;
                else target=1;
                while(l<r){
                    if(target==0)break;
                    int mid=(l+r)/2;
                    if(query(mid,1)-query(b[j].nd-1,1)>=target)r=mid;
                    else l=mid+1;
                }
                if(!target||query(l,2)-query(b[j].nd,2)!=0||query(l-1,0)-query(b[j].nd,0)!=0){
                    can2=false;
                }
                if(can1==false&&can2==false){
                    cout<<"NO\n";return;
                }
                use.pb(b[j].nd);
                j++;
                if(j==n+1)break;
            }
            for(auto u:use)add(u,1,2);
            for(auto u:v)add(u,-1,1);
            v.clear();
            use.clear();
        }
        else {
            cout<<"NO\n";
            return ;
        }
        if(i==n+2||j==n+1)break;
    }
    if(i!=n+1||j!=n+1)cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}