#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
   int q;
   cin>>q;
   int mn=-1;
   int mx=-1;
   int anow;
   while(q--)
   {
    int cmd;
    cin>>cmd;
    if(cmd==1)
    {
        int a,b,t;
        cin>>a>>b>>t;
        t--;
        int mnnow=(a-b)*t,mxnow=(a-b)*t+a;

        if(mn==-1&&mx==-1)
        {
            mn=mnnow,mx=mxnow;
            anow=a;
        }
        if(mxnow<mn||mnnow>mx)cout<<0; //out of bound
        else if(a<anow)cout<<0;
        else 
        {
            cout<<1;
            mn=max(mnnow,mn);
            mx=min(mxnow,mx);
            anow=max(a,anow);
        }
        //cout<<"mx="<<mx<<" mn="<<mn;
        
    }   
    else 
    {
        int a,b;
        cin>>a>>b;
        int diff=a-b;
        double mxt=(mn*1.0/diff*1.0);
        int day=ceil(mxt);
        //cout<<day;
        
        if(mx-mn>a||mx==-1)cout<<-1;
        else if(a>=mx)cout<<1;
        else 
        {
            while(diff*(day-1)+a<mx)day++;
            cout<<day;
        }

    }
    cout<<" ";
   }
   cout<<"\n";
}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
}