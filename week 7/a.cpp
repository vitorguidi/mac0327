#include "bits/stdc++.h"
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool valid(int x, int y, int n, int m, vector<vector<char>> &grid) {
	return x>=0 && x<n && y>=0 && y<m && grid[x][y]=='.';
}

vector<vector<int>> bfs(int x, int y, vector<vector<char>> &grid) {

	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> dist(n, vector<int>(m, 1e9));


	dist[x][y]=0;
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));

	while(!q.empty()) {
		pair<int,int> v = q.front();
		q.pop();

		for(int i=0;i<4;i++) {
			int new_x = v.first + dx[i];
			int new_y = v.second + dy[i];
			
			if(!valid(new_x, new_y, n,m,grid))	continue;
			if(dist[new_x][new_y] != 1e9)		continue;

			dist[new_x][new_y] = 1 + dist[v.first][v.second];
			q.push(make_pair(new_x, new_y));

		}

	}

	return dist;

}

void go() {

	int n,m; 
	scanf("%d %d\n",&m,&n);

	vector<vector<char>> grid(n, vector<char>(m,'.'));

	int x = -1;
	int y = -1;

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++){
			scanf("%c",&grid[i][j]);
			if(grid[i][j]!='#') {
				x=i;y=j;
			}
		}
		scanf("\n");
	}

	vector<vector<int>> dist = bfs(x,y,grid);

	int best = -1;

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			
			if(dist[i][j] != 1e9 && dist[i][j] > best){ 
				best = dist[i][j];
				x=i;
				y=j;
			}

		}
	}


	dist = bfs(x,y,grid);

	best = -1;

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			
			if(dist[i][j] != 1e9 && dist[i][j] > best){ 
				best = dist[i][j];
			}

		}
	}

	best=max(best,0);


	printf("Maximum rope length is %d.\n",best);

}

int main(){


	int q; scanf("%d\n", &q);
	while(q--) {
		go();
	}

}
