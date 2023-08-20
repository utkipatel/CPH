// https://leetcode.com/problems/coin-change-ii/description/

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

int numCombinations(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp2D(n+1,vector<int>(amount+1));

        vector<int> dp1D(amount+1);
        dp1D[0] = 1 ;
        // dp2D[0][0] = 1;
        for(int i=1;i<=n;i++) {
            int cval = coins[i-1];
            for(int j=0;j<=amount;j++){
                // dp2D[i][j] = dp2D[i-1][j] + ((cval<=j)? dp2D[i][j-cval]:0);
                dp1D[j] = dp1D[j] + ((cval<=j)? dp1D[j-cval]:0);
            }
        }
        // return dp2D[n][amount];
        return dp1D[amount];
    }

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t-- >0) {
        int n, amount;
        scanf("%d %d", &n, &amount);
        vector<int> coins(n);
        for(int i=0;i<n;i++) scanf("%d", &coins[i]);
        
        printf("%d\n", numCombinations(amount, coins));
    }

    return 0;
}