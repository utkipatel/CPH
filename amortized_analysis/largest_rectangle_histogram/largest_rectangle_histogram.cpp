// https://leetcode.com/problems/largest-rectangle-in-histogram/description
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

vector<int> leftMinDistFun(vector<int>&heights) {
    int n = heights.size();
    vector<int> leftMinDist(n,0);
    stack<ipair> incSt;
    incSt.push(make_pair(-1,-1));
    for(int i=0;i<n;i++) {
        int curr = heights[i];
        while(curr<= incSt.top().first) 
            incSt.pop();
        int lstSmallInd = incSt.top().second;
        leftMinDist[i]= i-lstSmallInd-1;
        incSt.push(make_pair(curr, i));
    }

    return leftMinDist;
}

int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    int n = heights.size();
    vector<int> reverseHeights = heights;
    reverse(reverseHeights.begin(), reverseHeights.end());
    
    vector<int>leftMinDist = leftMinDistFun(heights);
    vector<int>rightMinDist = leftMinDistFun(reverseHeights);
    reverse(rightMinDist.begin(), rightMinDist.end());
    
    for(int i=0;i<n;i++) {
        int maxWithCurr = heights[i] * (leftMinDist[i]+rightMinDist[i]+1);
        res = max(res, maxWithCurr);
    }

    return res;
}

int main() {
    // use incase of dealing with file for input/output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t-- >0) {
        int n;
        scanf("%d", &n);
        vector<int> heights(n);
        for(int i=0;i<n;i++) scanf("%d", &heights[i]);

        printf("%d\n", largestRectangleArea(heights));
    }
    
    return 0;
}