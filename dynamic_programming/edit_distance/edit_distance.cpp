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

int editDistance(string &word1, string &word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));
    dp[0][0] = 0;

    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            int mini = 1e9;
            if(i>0 && j>0) dp[i][j] = dp[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0:1);
            if(i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            if(j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
        }
    }

    return dp[m][n];
}

int main() {
    // use incase of dealing with file for input/output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t-- >0) {
        string word1, word2;
        cin>>word1>>word2;
        int res = editDistance(word1, word2);
        cout<<res<<endl;
    }
    return 0;
}