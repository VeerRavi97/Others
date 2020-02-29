#include<bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define IOS ios::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef vector<ll>vi;
int main(){
	IOS;
	ll tc;
	// cout << "Enter tc";
	cin >> tc;
	while(tc--){
		ll n,k;
		// cout << "enter";
		cin >> n >> k;
		vi v(n,0);
		vi pre(n+2,0);
		vi post(n+2,0);
		pre[0]=0;
		post[0]=0;
		pre[n+1]=0;
		post[n+1]=0;
		ll postsum=0;
		for(int i=0;i<n;i++){
			ll in;
			cin >> in;
			v[i]=in;
			ll cal=in%k;
			pre[i+1]=cal;
			cal=k-cal;
			if(cal==k) cal=0;
			post[i+1]=cal;
			postsum+=cal;
		}
	
		ll ans=INT_MAX;
		// for(auto x:v) cout << x << " ";
		// cout << "\n";
		// for(auto x:pre) cout << x << " ";
		// cout << "\n";
		// for(auto x:post) cout << x << " ";
		// cout << "\n";
		 ll l=0,r=0;
		for(int i=0;i<=n;i++){
			l+=pre[i];
			r+=post[i];
			ll req=postsum-r;
			// cout << l << " " << req << "\n";
			if(l>=req)ans=min(ans,l-req);
		}
		cout << ans << "\n";
		
	}
	
}


/*
1
5 7
1 14 4 41 1

*/