#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ipair;


vector<int> merge(vector<int> &arr, int l1, int r1, int l2, int r2) {
    int sz = r1-l1 + 1 + r2-l2 + 1;
    vector<int> res(sz,0);
    int ind=0;
    while(l1<=r1 && l2<=r2) {
        if(arr[l1]<arr[l2]) 
            res[ind++] = arr[l1++];
        else 
            res[ind++] = arr[l2++];
    }
    while(l1<=r1) res[ind++] = arr[l1++];
    while(l2<=r2) res[ind++] = arr[l2++];

    return res;
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l==r) return;

    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    vector<int> mergedArr = merge(arr, l, mid, mid+1, r);
    copy(mergedArr.begin(), mergedArr.end(), arr.begin()+l);
    return;
}

int main() {
    int t;
    cin>>t;
    while(t-- >0) {
        int n;
        cin>>n;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++) cin>>arr[i];
        mergeSort(arr, 0, n-1);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}