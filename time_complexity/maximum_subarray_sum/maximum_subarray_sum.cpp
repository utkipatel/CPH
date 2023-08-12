#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ipair;

int main() {
    // This is Kadane Algorithm
    int t;
    cin>>t;
    while(t-- >0) {
        int n; 
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++) cin>>arr[i];

        int res = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
            sum = max(sum, 0);
            res = max(res, sum);
        }
        cout<<res<<endl;
    }
    return 0;
}