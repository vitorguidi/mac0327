#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int n,m,k;
int cnt, desired;


int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool valid(int x, int y, vector<vector<char>> &grid) {
	return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

void dump(vector<vector<char>> &grid) { 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &vis) {
	if(vis[x][y])	
		return;

	vis[x][y]=1;
	desired--;


	if(desired<0) {
		grid[x][y]='X';
	}

	for(int i=0;i<4;i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if(valid(new_x,new_y,grid)) {
			dfs(new_x, new_y,grid,vis);
		}
	}



}

int main(){

	fastio;

	cin >> n >> m >> k;

	int x = -1;
	int y = -1;
	cnt = 0;

	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<int>> vis(n, vector<int>(m));

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> grid[i][j];
			if(grid[i][j]=='.'){
				x=i;y=j;
				cnt++;
			}
		}
	}
	desired = cnt - k;

	dfs(x,y,grid,vis);

	dump(grid);

}
