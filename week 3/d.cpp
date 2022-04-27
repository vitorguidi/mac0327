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

ll get_acum(vector<vector<ll>> &acum, int i0, int j0, int i1, int j1) {
	return acum[i1][j1] - acum[i0-1][j1] - acum[i1][j0-1] + acum[i0-1][j0-1];
}

bool go(int n, int m) {


	vector<vector<ll>> grid(n+1, vector<ll>(n+1, 0));
	frr(i,n) {
		frr(j,n) {
			cin >> grid[n-i+1][j];
		}
	}
	frr(i,n) {
		frr(j,n) {
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
		}
	}

	vector<vector<ll>> ans(n-m+2, vector<ll>(n-m+2, 0));
	ll sum = 0;
	frr(i,n-m+1) {
		frr(j,n-m+1) {
			ans[i][j] = get_acum(grid, i,j, i+m-1, j+m-1);
		}
	}
	for(int i=n-m+1;i>=1;i--) {
		for(int j=1;j<=n-m+1;j++) {
			cout <<  ans[i][j] << endl;
			sum += ans[i][j];
		}
	}

	cout << sum;
	return true;
}


int main(){

	fastio;
	int n,m;
	cin >> n >> m;
	bool last = go(n,m);
	while(true){
		if(!(cin >> n >> m))	break;
		cout << endl << endl;
		go(n,m);
	}

	cout << endl;

}
