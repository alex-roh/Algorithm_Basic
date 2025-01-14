#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = b - 1; i >= a; i--)
#define mp(a,b) make_pair(a, b)

#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

// ofstream out
#define fco(a) out << a
#define fco(a) out << a
#define fcos(a) out << a << ' '
#define fcol(a) out << a << '\n' 
#define fcl out << '\n'

#define frt front
#define ps push
#define pp pop
#define emt empty
#define pb push_back
#define fst first
#define scd second

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef stack<int> si;
typedef queue<int> qi;
typedef deque<int> di;
typedef priority_queue<int> pqi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int N, M;
int B[1001][1001];
int Z[1001][1001];
vi zerosForBlock(1); // 인덱스 1부터 시작해야 
int idx = 1;

// 제로 블록을 모음 
void BFS(int sx, int sy){
	
	queue<pii> que;
	que.ps(mp(sx, sy));
	zerosForBlock.pb(0);
	Z[sx][sy] = idx;
	zerosForBlock[idx]++;
	
	while(!que.emt()){
		
		pii zero = que.frt(); que.pp();
		int x = zero.fst;
		int y = zero.scd;
		
		rep(i, 0, 4){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bnd(nx, ny, N, M)) continue; 
			if(B[nx][ny] == 1 || Z[nx][ny] > 0) continue;
			
			Z[nx][ny] = idx;
			zerosForBlock[idx]++;
			que.ps(mp(nx, ny));
			
		}
		
	}
	
	idx++;
	
}

// 벽마다 이동할 수 있는 제로 블록을 찾아서 캐싱 
void count(){

	rep(i, 0, N){
		rep(j, 0, M){
		
			if(B[i][j] == 1){
				
				set<int> nearZeros;
				
				// 상하좌우에 있는 제로 블록을 탐색 
				rep(k, 0, 4){
					
					int ni = i + dx[k];
					int nj = j + dy[k];
					
					if(!bnd(ni, nj, N, M)) continue;
					if(B[ni][nj] == 0) 
						nearZeros.insert(Z[ni][nj]);
					
				}
				
				// 블록별로 개수를 더함 
				for(auto &x : nearZeros){
					B[i][j] += zerosForBlock[x];
				}
				
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	cig(99999);
	
	// 입력 
	rep(i, 0, N){
		
		string row;
		gtl(row);
		
		rep(j, 0, M){
				
			B[i][j] = row[j] - '0';
		}
	}
	
	// BFS 호출 
	rep(i, 0, N){
		rep(j, 0, M){
			if(B[i][j] == 0 && Z[i][j] == 0)
				BFS(i, j);
		}
	}
	
	count();
	
	// 결과를 출력 
	rep(i, 0, N){
		rep(j, 0, M){
			co(B[i][j] % 10);
		}
		cl;
	}
	
	return 0;
}
