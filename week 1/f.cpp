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

int main(){

	fastio;

	int n,m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m,0));

	long long int ans = 0;

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> v[i][j];
		}
	}

	for(int i=0;i<n;i++) {
		int white = 0;
		int black = 0;
		for(int j=0;j<m;j++) {
			white += (v[i][j]==0);
			black += (v[i][j]==1);
		}
		ans+= (1ll<<(white)) -1;
		ans+= (1ll<<(black)) -1;
		
	}

	for(int j=0;j<m;j++) {
		int white = 0;
		int black = 0;
		for(int i=0;i<n;i++) {
			white += (v[i][j]==0);
			black += (v[i][j]==1);
		}
		ans+= (1ll<<(white)) -1;
		ans+= (1ll<<(black)) -1;
	}

	cout << ans - m*n << endl;

}
