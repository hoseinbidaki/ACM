#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using namespace std;
typedef long long ll;
char r[500][500];
int ans[500][500];
int vis[500][500];
int main()
{
	//ios :: sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	int sx,sy, ex, ey;
	vector<int> a;
	vector<int> b;

	bool fl = false;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans[i][j] = 0;
			vis[i][j] = 0;

			cin >> r[i][j];
			if (r[i][j] == 'S') {
				sx=i;
				sy=j;
			}
			if (r[i][j] == 'E') {
				ex=i;
				ey=j;
			}
			if (r[i][j] == '*') {
				a.push_back(i);
				b.push_back(j);
				fl = true;
			}
		}
	}
	int sia = (int) a.size();
	int sib = (int) b.size();

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	//cout << "fgsgfsg";
	stack<pair<int, int>> ST;
	ST.push({sx, sy});
	int xx, yy;
	pair<int, int> ttt;
	bool resf = false;
	int fans = 0;
	//cout << "gfdhd";
	
	while (!ST.empty()) {
		//cout << "gfg";
		ttt = ST.top();
		xx = ttt.first;
		yy = ttt.second;
		ST.pop();
		
		vis[xx][yy] = 1;
	//	int mx = a.front();
		//max(abs(b[0]-yy), abs(b[sib - 1]-yy))
		//ans[xx][yy] = max(, );
		//max(max(abs(a[0]-xx), abs(a[sia - 1]-xx)), max(abs(b[0]-yy), abs(b[sib - 1]-yy)));
		//fans = max(ans[xx][yy],fans);
		/*
		if (xx == ex && yy == ey) {
			resf = true;
		}
		
		if (xx + 1 < n && vis[xx+1][yy]==false) {
			ST.push({xx + 1, yy});
			vis[xx+1][yy] = 1;
		}
		if (xx - 1 >= 0 && vis[xx-1][yy]==false) {
			ST.push({xx - 1, yy});
			vis[xx-1][yy] = 1;	
		}
		if (yy + 1 < m && vis[xx][yy+1]==false) {
			ST.push({xx, yy + 1});
			vis[xx][yy+1] = 1;
		}
		if (yy - 1>= 0 && vis[xx][yy-1]==false) {
			ST.push({xx, yy-1});
			vis[xx][yy-1] = 1;
		}*/
	}// end


	if (resf == false) {
		cout << "-1";
	}
	else {
		if (fl == false) {
			cout << "safe";
			return 0;
		}
		cout << fans;
	}

}