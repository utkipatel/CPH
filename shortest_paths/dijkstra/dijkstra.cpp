#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ipair;

// comparator to be used in priority_queue
class Compare {
public:
    bool operator()(ipair p1, ipair p2)
    { 
        return true;
    }
};

// comparator to be used in vectors
bool comp(ipair a, ipair b) {
    return true;
}


int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    priority_queue<ipair> pq;
    int inf = 1e9;
    vector<int> dist(n+1,inf);
    dist[k] = 0;
    pq.push(make_pair(0, k));

    vector<vector<ipair>> adjmat(n+1);
    for(int i=0;i<times.size();i++) 
        adjmat[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
    
    vector<bool> seen(n+1,false);
    while(pq.size()>0) {
        auto qtop = pq.top();
        int u = qtop.second;
        pq.pop();
        if(seen[u]) continue;
        seen[u] = true;
        for(auto vw: adjmat[u]) {
            if(dist[u]+vw.second < dist[vw.first]){
                dist[vw.first] = dist[u] + vw.second;
                pq.push(make_pair(-1*dist[vw.first], vw.first));
            }
        }
    }

    int res = 0;
    for(int i=1;i<=n;i++) res = max(dist[i], res);

    return res==inf?-1:res;
}

int main() {
    // use incase of dealing with file for input/output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t-- >0) {
        int n,m, k;
        scanf("%d %d %d", &n, &m, &k);
        vector<vector<int>> times(m, vector<int>(3));
        for(int i=0;i<m;i++) 
            scanf("%d %d %d", &times[i][0],&times[i][1],&times[i][2]);
        
        printf("%d\n", networkDelayTime(times,n,k));

    }
    return 0;
}