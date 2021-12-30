#include<bits/stdc++.h>
using namespace std;    
#define ll long long
const int maxn = 2e5 + 7;
bool seen[maxn];
vector<int>a[maxn];

int main(){
    ios::sync_with_stdio(false) ,cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1 ; i < n ; i++) {
        int x ,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue<int>qu;
    qu.push(1);
    while(!qu.empty()) {
        queue<int>q;
        while(!qu.empty()){
            int v = qu.front();
            cout << v << " ";
            seen[v] = true;
            qu.pop();
            for(auto i : a[v]){
                if(!seen[i]){
                    q.push(i);
                }
            }
        }
        qu = q;
    }
}

