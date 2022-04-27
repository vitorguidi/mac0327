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

vector<ll> w,v;

ll dp(int ind, int val, vector<vector<ll>> &memo) {

	if(ind==w.size()) {
		if(val==0)	return 0;
		return 2e18;
	}
	if(val < 0)
		return 2e18;
	
	ll &pdm = memo[ind][val];
	if(pdm!=-1)	return pdm;

	pdm = 2e18;	

	pdm = min( pdm, w[ind] + dp(ind+1, val - v[ind], memo) );
	pdm = min( pdm, dp(ind+1, val, memo) );

	return pdm;

}

int main(){

	fastio;

	int n, cap;
	cin >> n >> cap;

	fr(i,n) {
		int x,y;
		cin >> x >> y;
		w.push_back(x);
		v.push_back(y);
	}

	vector<vector<ll>> memo(110, vector<ll>(100100, -1));
	
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<100100;j++) {
			if(dp(i,j,memo) >= 0 && dp(i,j,memo)<=cap)
				ans = max(ans, j);
		}
	}

	cout << ans << endl;

}
