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

	int n, k;
	cin >> n >> k;
	vector<int> v(n);

	fr(i,n) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	map<int,int> freq;
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += freq[v[i]-k];
		freq[v[i]]++;
	}

	cout << ans << endl;

}
