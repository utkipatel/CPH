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


int main() {
    // use incase of dealing with file for input/output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    int tot = 1<<n;
    for(int b=0;b<tot;b++) {
        vector<int> subset;
        for(int i=0;i<n;i++) 
            if(b&(1<<i)) subset.push_back(arr[i]);
        for(int el:subset)
            printf("%d ", el);
        printf("\n");
    }

    return 0;
}