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

int minimumDifference(vector<int>& nums) {
        int target = 0, res=0;
        int n = nums.size()/2;
        target = accumulate(nums.begin(), nums.end(), 0);

        int tot = 1<<n;
        vector<vector<int>> m1(n+1), m2(n+1);
        for(int b=0;b<tot;b++) {
            int sz=0,tot1=0,tot2=0;
            for(int i=0;i<n;++i) {
                if(b&(1<<i)) {
                    sz++;
                    tot1+=nums[i];
                    tot2+=nums[n+i];
                }
            }
            m1[sz].push_back(tot1);
            m2[sz].push_back(tot2);

        }
        for(int i=0;i<=n;++i) {
            sort(m2[i].begin(), m2[i].end());
        }

        res = min(abs(target-2*m1[n][0]), abs(target-2*m2[n][0]));

        for(int i=1;i<n;++i){
            int sz2 = n-i;
            for(auto &sum1:m1[i]) {
                int sum2 = (target - 2*sum1)/2;
                auto &v2 = m2[sz2];
                auto it2 = lower_bound(v2.begin(), v2.end(), sum2);
                if(it2!=v2.end()) 
                    res = min(res, abs(target - 2*(sum1 + *it2)));
                if(it2!=v2.begin()){
                    --it2;
                    res = min(res, abs(target - 2*(sum1 + *it2)));
                }
            }
        }
        return res;
    }

int main() {
    // use incase of dealing with file for input/output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t-- >0) {
        int n;
        scanf("%d", &n);
        vector<int> nums(n);
        for(int i=0;i<n;i++) scanf("%d", &nums[i]);
        int res = minimumDifference(nums);
        printf("%d\n", res);
    }
    return 0;
}