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

int dx[8] = {-1,-1,	-2,-2,	1,1,	2,2};
int dy[8] = { 2,-2,	 1,-1,  2,-2, 	1,-1};

int convert(string s) {

	int x = int(s[0]-'a');
	int y = int(s[1]-'1');
	return 8*x + y;

}

bool valid(int x, int y) {
	return x>=0 && x<8 && y>=0 && y<8;
}

int main(){

	fastio;

	int dist[64][64];
	ms(dist, INF);

	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			for(int k=0;k<8;k++) {
				int new_i = i + dx[k];
				int new_j = j + dy[k];
				if (valid(new_i,new_j)) {
					dist[8*i+j][8*new_i+new_j] = 1;
				}
			}
		}
	}

	for(int k=0;k<64;k++) {
		dist[k][k] = 0;
		for(int j=0;j<64;j++) {
			for(int i=0;i<64;i++) {

				int &desired_dist = dist[i][j];
				int &first_half = dist[i][k];
				int &second_half = dist[k][j];

				desired_dist = min(desired_dist, first_half + second_half);

			}

		}
	}

	int q; cin >> q;
	while(q--) {
		string x,y;
		cin >> x >> y;
		int from = convert(x);
		int to = convert(y);
		cout << dist[from][to] << endl;
	}


}
