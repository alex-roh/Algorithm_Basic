#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt1(arr,N) cl; rep(i, 0, N){cos(arr[i]);} cl;
#define prt2(arr,N,M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,b,a) for(int i = b; i >= a; i--) /* caution! */
#define mp(a,b) make_pair(a, b)

#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

#define fco(a) out << a
#define fco(a) out << a
#define fcos(a) out << a << ' '
#define fcol(a) out << a << '\n' 
#define fcl out << '\n'

#define tp top
#define frt front
#define ps push
#define pp pop
#define emt empty
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fst first
#define scd second

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef stack<int> si;
typedef queue<int> qi;
typedef deque<int> di;
typedef priority_queue<int, vector<int>> pqi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

// ofstream out
const int MAX = 2000000000;

typedef struct _Tsk{
	int d, w;
} Tsk;

bool cmp(Tsk a, Tsk b){
	
	if(a.d == b.d)
		a.w > b.w;
	return a.d > b.d;
	
} 

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	int N; ci(N);
	vector<Tsk> tlist(N);
	
	int md = -1;
	
	rep(i, 0, N){
		int d, w; ci2(d, w);
		tlist[i] = { d, w };
		md = max(md, d);
	}
	
	sort(tlist.begin(), tlist.end(), cmp);
	pqi pq;
	
	int res = 0; int pos = 0;
	rrep(day, md, 1){
		
		// 오늘 할 수 있는 일을 다 집어넣음 
		while(pos < N && tlist[pos].d >= day){
			pq.ps(tlist[pos].w);
			pos++;
		}
		
		// 그 중 점수가 제일 높은 일을 함 
		if(!pq.emt()){
			res += pq.tp();
			pq.pp();
		}
	
	}
	
	col(res);
	
	// out.close();
	return 0;
}
