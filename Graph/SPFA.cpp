/**
 * Shortest Path Faster Algorithm (BFS version)
 * better than Bellman Ford algo
 *  T = O(kE)
 *
 * Variations:
 *------------------------------------------------
 * V1: Queue can be replaced by stack (DFS version)
 * V2: More efficient by using priority_queue or deque to speed up
 */

struct Node {
	int v, dis;
};

vector<Node> Adj[MAXV];
int n, d[MAXV], num[MAXV];
bool inq[MAXV];

bool SPFA(int s)
{
	memset(inq, false, sizeof(inq));
	memset(num, 0, sizeof(num));
	fill(d, d+MAXV, INF);
	queue<int> Q;
	
	Q.push(s);
	inq[s] = true;
	num[s]++;
	d[s] = 0;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for (int j = 0; j < (int)Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				if (!inq[v]) {
					Q.push(v);
					inq[v] = true;
					num[v]++;
					if (num[v] >= n) return false;
				}
			}
		}
	}
	return true;
}

