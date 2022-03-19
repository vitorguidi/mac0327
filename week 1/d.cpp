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

	int n,m;
	cin >> n >> m;

	int best = 0;

	for(int i=0;i<=n+m;i++) {	
		//numero de times com 2 veetranos

		int required_noobs = i*2;
		int required_veterans = i;

		if (required_noobs > m || required_veterans > n)	continue;

		//numero de times com 2 veteranos

		int left_noobs = m - required_noobs;
		int left_veterans = n - required_veterans;

		int att = i + min(left_noobs, left_veterans/2);
		best = max(best, att);

	}

	cout << best << endl;

}
