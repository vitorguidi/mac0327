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

string s;

bool validOne(string &s, int ind) {
	return ind < s.size() && s[ind]!='0';
}

bool validTwo(string &s, int ind) {
	if(s[ind]=='0' || ind+2 > s.size())	
		return false;
	int val = (s[ind]-'0')*10 + s[ind+1]-'0';
	return val <= 26;
}

ll dp(int i, vector<ll> &memo) {

	if(i==s.size())	return 1;
	
	ll &pdm = memo[i];
	if(pdm!=-1)	return pdm;

	pdm = 0;
	if (validOne(s, i)) {
		pdm += dp(i+1, memo);
	}
	if(validTwo(s, i)) {
		pdm += dp(i+2, memo);
	}

	return pdm;

}

int main(){

	fastio;

	while(true) {
		cin >> s;
		if(s=="0")	break;
		vector<ll> memo(s.size()+1, -1);
		cout << dp(0, memo) << endl;
	}

}
