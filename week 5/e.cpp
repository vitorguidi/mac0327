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

int n;
vector<int> v;

ll memo[3030][3030][2];

ll pd(int i, int j, int turn) {

	if(i>j)	return 0;

	ll &pdm = memo[i][j][turn];
	if(pdm!=-1)	return pdm;

	if(turn == 0) {
		return pdm = max(v[i] + pd(i+1,j,1), v[j] + pd(i,j-1,1));
	}
	else {
		return pdm = min(pd(i+1,j,0), pd(i,j-1,0));
	}


}

int main(){

	fastio;

	cin >> n;
	ll sum = 0;

	fr(i,n) {
		int x;
		cin >> x;
		v.push_back(x);
		sum += x;
	}

	ms(memo,-1);

	ll ans = pd(0,n-1,0);

	cout << ans - (sum-ans) << endl;

}
