// https://leetcode.com/problems/coin-change/description/

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

int minNumOfCoins(vector<int>&coins, int amount) {
    vector<int> dp(amount+1,1e9);
    dp[0]=0;
    for(int i=1;i<=amount;i++) {
        for(int c:coins){
            if(c<=i)
                dp[i] = min(dp[i], dp[i-c] + 1);
        }
    }

    return (dp[amount]==1e9)?-1:dp[amount];
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
        
        printf("%d\n", minNumOfCoins(coins, amount));
    }

    return 0;
}