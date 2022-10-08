// C. Qpwoeirut And The City


#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll coolify(int i,vector<int> &h){
    return max(0,max(h[i-1],h[i+1]) + 1 - h[i]);
}

void solve(){
    int n;
    cin >> n;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++) cin >> h[i];
    //for odd case - 0101010
    //for even case - 01010100,01010010,01001010,00101010

    ll ans = 0;
    for(int i=2;i<n;i+=2){
        ans += coolify(i,h);
    }

    if(n&1){
        cout << ans <<endl;
        return;
    }

    ll tot = ans;
    for(int i=n-1;i>1;i-=2){
        tot += coolify(i,h);
        tot -= coolify(i-1,h);
        ans = min(ans,tot);
    }

    cout << ans << endl;
}

int main()
{
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

   int t;
   cin>>t;

   while(t--)
   {
      solve();
   }
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}