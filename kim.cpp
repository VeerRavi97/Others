#include<bits/stdc++.h>
using namespace std;

int n,min_ans,x[100],y[100],visited[100],dx,dy;

int min(int a,int b){
	if(a<b) return a;
	return b;
}
int abs(int a){
	if(a<0) return -a;
	return a;
}
int absdiff(int sx,int sy,int dx,int dy) {
	int xd=abs(sx-dx);
	int yd=abs(sy-dy);
	return (xd+yd);
}
void fun(int k,int sx,int sy,int value) {
	if(k==n) {

		int temp=value+absdiff(sx,sy,dx,dy);
		min_ans=min(min_ans,temp);
        return;
	}
	for(int i=1;i<=n;i++) {
		if(visited[i]==0) {
			visited[i]=1;
			int tem=value+absdiff(sx,sy,x[i],y[i]);
			fun(k+1,x[i],y[i],tem);
			visited[i]=0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t,index=1;
	t=10;
	while(t--) {
		cin>>n;
		int sx,sy;
		cin>>sx>>sy >> dx >> dy;
		for(int i=1;i<=n;i++) {
			cin>>x[i]>>y[i];
			visited[i]=0;
		}
		min_ans=999999;
		fun(0,sx,sy,0);
		cout<<"#"<<index<<" "<<min_ans<<endl;
		index++;
	}
	
	return 0;
}
