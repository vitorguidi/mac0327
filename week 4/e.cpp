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
	ll isprime[210];
	
	ll ans[220];
int main(){

	fastio;

	vector<ll> primes;
	map<int,int> combos;

	for(int i=2;i<=200;i++) {
		if(isprime[i])	continue;
		primes.push_back(i);
		for(int j=i;j<=200;j+=i)	isprime[j]=1;
	}

	for(auto x : primes) {
		for(auto y : primes) {
			if(!combos[x*y] && x*y<=200 && x!=y)	combos[x*y]=1;
			
		}
	}

	for(int i=0;i<=200;i++) {
		for(int j=0;j<=i;j++) {
			if(combos[i-j] && combos[j] && !ans[i]){
				ans[i]=1;
				// cout << i << endl;
			}
		}
	}

	int q; cin >> q;
	while(q--) {
		int x; cin >> x;
		cout << (ans[x] == 1 ? "YES" : "NO") << endl;
	}

}
