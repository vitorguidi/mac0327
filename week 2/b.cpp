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

int n,h;

int main(){

	fastio;

	cin >> n >> h;

	vector<int> ini(n+1), end(n+1), delta(n+1);

	for(int i=1;i<=n;i++) {
		cin >> ini[i] >> end[i];
	}

	int r = -1;
	int slack = 0;
	int best = 0;

	for(int i=1;i<=n;i++) {

		while(r+1<=n && h+slack+end[r+1]-ini[r+1]>end[r+1]-ini[i]) {
			r++;
			slack+=end[r]-ini[r];
		}		
		best=max(best, h+ slack);
		slack-=end[i]-ini[i];

	}

	cout << best<< endl;

}
