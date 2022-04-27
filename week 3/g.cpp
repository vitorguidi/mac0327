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

int best(int ini, int n, int letter, vector<int> &acum_other, int k) {

	int st = 1;
	int fi = n-ini+1;
	while(st<=fi) {
		int mid = (st+fi)/2;
		int outros = acum_other[ini+mid-1]-acum_other[ini-1];
		if(outros > k) {
			fi=mid-1;
		}
		else {
			st = mid+1;
		}
	}
	
	return fi;

}

int main(){

	fastio;

	int n,k;
	cin >> n >> k;

	string s; cin >> s;
	vector<int> acum_a(n+1);
	vector<int> acum_b(n+1);

	for(int i=1;i<=n;i++) {
		char c = s[i-1];
		if(c=='a')	acum_a[i]++;
		else		acum_b[i]++;
		acum_a[i]+=acum_a[i-1];
		acum_b[i]+=acum_b[i-1];
	}

	int ans = 0;
	for(int i=1;i<=n;i++) {
		ans = max(ans, best(i,n,0,acum_b, k));
		ans = max(ans, best(i,n,1,acum_a, k));
	}

	cout << ans << endl;

}
