#include<bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
typedef long long ll;
int main(){
	int tc;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>a;
		vector<int>b;
		for(int i=0;i<n;i++){
			int in;
			cin >> in;
			a.push_back(in);
		}
		for(int i=0;i<n;i++){
			int in;
			cin >> in;
			b.push_back(in);
		}
		sort(all(a));
		sort(all(b));
		 ll ans=0;
		for(int i=0;i<n;i++){
			ans+=min(a[i],b[i]);
		}
		cout << ans << "\n";
		
	}
	
	
}