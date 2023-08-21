// https://leetcode.com/problems/sliding-window-maximum/

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

void add2Queue(deque<ipair> &dq, int x, int ind) {
    while(dq.size()>0 && dq.front().first<x) {
        dq.pop_front();
    }
    dq.push_front(make_pair(x,ind));
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<ipair> dq;
    int n = nums.size();
    for(int i=0;i<k;i++) 
        add2Queue(dq,nums[i], i);
    vector<int> res;
    res.push_back(dq.back().first);
    for(int i=1;i+k<=n;i++) {
        if(dq.back().second < i) dq.pop_back();
        add2Queue(dq, nums[i+k-1], i+k-1);
        res.push_back(dq.back().first);
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
        int n,k;
        scanf("%d %d", &n, &k);
        vector<int> nums(n);
        for(int i=0;i<n;i++) scanf("%d", &nums[i]);

        vector<int> res = maxSlidingWindow(nums, k);
        for(int i=0;i<res.size();i++) printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}