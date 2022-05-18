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

int turn;

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,-1,1,-1,1};

bool valid(int i, int j, int n, int m) {
	return i>=0 && i<n && j>=0 && j<m;
}

void go(int n, int m) {

	vector<pair<int,int>> as;

	vector<vector<int>> dist(n,vector<int>(m, INF));
	
	vector<vector<int>> grid(n,vector<int>(m));


	fr(i,n){
		fr(j,m) {
			char c; cin >> c; 
			grid[i][j] = c-'A';
			if(c=='A') {
				as.push_back(make_pair(i,j));
				dist[i][j]=1;
			}
		}
	}

	set<tuple<int,int,int>> s;
	for(auto x : as) {
		s.insert(make_tuple(1,x.first,x.second));
	}

	while(!s.empty()) {
		tuple<int,int,int> t = *s.begin();
		s.erase(s.begin());

		int d,vi,vj;
		tie(d,vi,vj) = t;

		fr(k,8) {

			int new_i = vi + dx[k];
			int new_j = vj + dy[k];
			
			if(valid(new_i,new_j,n,m) && grid[new_i][new_j] == 1 + grid[vi][vj]) {

				if(dist[new_i][new_j]!=INF)	continue;

				dist[new_i][new_j] = 1 + dist[vi][vj];
				s.insert(make_tuple(dist[new_i][new_j],new_i,new_j));
			
			}
		}

	}

	int best = 0;
	fr(i,n) {
		fr(j,m) {
			if(dist[i][j]==INF)	continue;
			best=max(best,dist[i][j]);
		}
	}

	cout << "Case " << turn << ": " << best << endl;
	turn++;

}

int main(){

	fastio;

	int n,m;
	turn = 1;
	while(cin >> n >> m){
		if(!n)	break;
		go(n,m);
	}
	

}
