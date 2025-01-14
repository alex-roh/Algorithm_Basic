#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c) (a >= 0 && b >= 0 && a < c && b < c)
#define bnd2(a, b, c, d) (a >= 0 && b >= 0 && a < c && b < d)

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
int walls[3];
int B[9][9];

int res = -1;

vi blanks;
vi viruses;

// �ʱ�ȭ �ʿ� 
int b[9][9];
bool visited[9][9];

int getIndex(int i, int j){
	return (i * M + j);
}

pii getXY(int index){
	return mp(index / M, index % M);
}

void BFS(){
	
	queue<pii> que;
	
	// ��ĭ �� ���� ������ ĥ�� 
	rep(i, 0, 3){
		pii wall = getXY(walls[i]);
		b[wall.fst][wall.scd] = 1;
	}
	
	// �Է� �迭�� ������� 
	rep(i, 0, N){
		rep(j, 0, M){ 
			if(b[i][j] != -1) continue;
			b[i][j] = B[i][j];
			// ���̷����� ť�� ������� 
			if(b[i][j] == 2){
				que.ps(mp(i, j));
				visited[i][j] = true;
			}
		}
	}
	
	while(!que.emt()){
		
		pii cur = que.frt(); que.pp();
		
		int x = cur.fst;
		int y = cur.scd;
		
		rep(i, 0, 4){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bnd2(nx, ny, N, M)) continue;
			if(visited[nx][ny]) continue;
			if(b[nx][ny] == 2 || b[nx][ny] == 1) continue;
			
			b[nx][ny] = 2;
			que.ps(mp(nx, ny));
			visited[nx][ny] = true;
			
		}
		
	}
	
	// �ִ밪 ����
	int cnt = 0; 
	rep(i, 0, N){
		rep(j, 0, M){
			if(b[i][j] == 0)
				cnt++;
		}
	}
	
	res = max(res, cnt);
	
}

// ��� ��ĭ���� 3���� ���� �ٸ� ��ĭ�� ���� 
void gen(int cnt, int level){
	
	if(cnt == 3){
		memset(visited, false, sizeof(visited[0][0]) * 9 * 9);
		memset(b, -1, sizeof(b[0][0]) * 9 * 9);
		BFS();
		return;
	}
	
	rep(i, level, blanks.size()){
		walls[cnt] = blanks[i];
		gen(cnt + 1, i + 1);
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	
	rep(i, 0, N){
		rep(j, 0, M){
			
			ci(B[i][j]);
			
			// ��ĭ�� ���Ϳ� ĳ�� 
			if(B[i][j] == 0){
				int index = getIndex(i, j);
				blanks.pb(index);
			}
			
		}
	}
	
	gen(0, 0);
	cos(res);
	
	return 0;
}
