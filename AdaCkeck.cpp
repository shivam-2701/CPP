#include <bits/stdc++.h>
#define ll long long int
const int MAXN=1e5+10;
using namespace std;
void solve(){
    int r,c,k;
    cin>>r>>c>>k;
    r--;c--;
    queue<pair<int,int>> q;
    q.push({r,c});
    vector<vector<bool>> seen(8,vector<bool>(8,false));
    seen[r][c]=true;
    int ans=1;
    while(!q.empty() && k){
        int n=q.size();
        k--;
        for(int i=0;i<n;i++){
            auto f=q.front();
            q.pop();
            int R=f.first;
            int C=f.second;
            int dx[]={1,-1,0,0,1,1,-1,-1};
            int dy[]={0,0,1,-1,-1,1,-1,1};
            for(int k=0;k<8;k++){
                int nR=R+dx[k],nC=C+dy[k];
                if(nR<0 || nR>=8 || nC<0 || nC>=8) continue;
                if(seen[nR][nC]) continue;
                q.push({nR,nC});
                seen[nR][nC]=true;
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	cin>>t;
	while(t--)
	{
	   solve();
	}
	return 0;
}
