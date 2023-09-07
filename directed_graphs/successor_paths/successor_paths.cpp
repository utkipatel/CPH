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

vector<vector<int>> parentDP(vector<int> &parent) {
    int n = parent.size();
    int M = log2(n)+1;
    vector<vector<int>> dp = vector<vector<int>> (n, vector<int> (M));

    for(int i=0;i<n;i++) dp[i][0] = parent[i];

    for(int p=1;p<M;p++) {
        for(int i=0;i<n;i++) {
            if(dp[i][p-1]==-1) dp[i][p] = -1;
            else dp[i][p] = dp[dp[i][p-1]][p-1];
        }
    }
    return dp;
}

int getKthAncestor(int node, int k, vector<vector<int>> &dp) {
    int curr = node;
    int M = dp[0].size();

    for(int i=M-1;i>=0;i--) {
        if(curr==-1) return -1;
        if(1<<i & k) {
            curr = dp[curr][i];
        }
    }
    return curr;
}

int main() {
    // use incase of dealing with file for input/output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<int> parents(n,0);
    for(int i=0;i<n;i++) scanf("%d", &parents[i]);
    vector<vector<int>> dp = parentDP(parents);
    int t;
    scanf("%d", &t);
    while(t-- >0) {
        int node, k;
        scanf("%d %d",&node, &k );
        printf("%d\n", getKthAncestor(node, k, dp));

    }


    return 0;
}