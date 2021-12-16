

#include <iostream>
#include <vector>
using namespace std;

 //Recursion
int lis (int a[], int n) {
    if ( 1 == n) return 1;
    int res, maxLis =1;
    for (int i=1 ; i< n ; i++) {
        res = lis(a,i);
        maxLis = res;
        if( a[i-1] < a[n-1] && res + 1 > maxLis) maxLis = res + 1;
    }
    return maxLis;
}

// dynamic programming
int lis (int a[], int n) {
    vector<int> dp(a,a+n);
    int Max =0;
    for( int i=0 ; i< n ; i++) dp[i] = 1;
    for( int i=1 ; i< n ; i++) {
        for( int j=0 ; j< n ; j++) {
            if (a[i] > a[j] && dp[j]+1 > dp[i]) dp[i] = dp[j] +1;
        }
    }
    for (int i=0 ; i< n ; i++) {
        Max = (Max > dp[i]) ? Max : dp[i];
    }
    return Max;
}

int main() {
    // 9 10 22 9 33 21 50 41 60 80
    // 10 22 33 50 60 80 => 6
    int n, a[1001];
    cin >> n;
    for (int i=0 ; i < n ;i++)
        cin >> a[i];
    cout << lis(a,n);
    return 0;
}
