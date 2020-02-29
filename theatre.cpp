#include<bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
typedef long long ll;
typedef vector<int>vi;
int main(){
	int tc;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	ll ans=0;
	while(tc--){
		int n;
		cin >> n;
		int mat[4][4];
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++){
			char movie;
			int time;
			cin >> movie >> time;
			int row,col;
			row=movie-'A';
			if(time==12) col=0;
			else if(time==3) col=1;
			else if(time==6) col=2;
			else col=3;
			mat[row][col]++;
		}
		// for(int i=0;i<4;i++){
		// 	for(int j=0;j<4;j++) cout << mat[i][j] << " ";
		// 	cout << "\n";
		// }
		// cout << "\n";
		int movies[4]={0};
		int times[4]={0};
		int factor=100;
		ll smallAns=0;
		ll maxm;
	    for(int l=0;l<4;l++){
			 maxm=LONG_MIN;
			int x,y;
		for(int i=0;i<4;i++){
			if(!movies[i]){
			for(int j=0;j<4;j++) {
				if(!times[j])
				{
					if(maxm<=mat[i][j]){
						maxm=mat[i][j];
						x=i;
						y=j;
					}
				}
			}
			}
		}
			movies[x]=1;
			times[y]=1;
			// cout << x << " " <<  y << " " << maxm << "\n";
			if(maxm>0) smallAns+=factor*maxm;
		   else smallAns-=100;
		
		factor-=25;
	
	
		}
			cout << smallAns << "\n";
	ans+=smallAns; 
	}
	cout << ans << "\n";
	
}