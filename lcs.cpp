#include <iostream>
using namespace std;

// Recursion
//int lcs(string a, string b, int m,int n) {
//    if( 0 == m || 0 == n) return 0;
//    if ( a[m-1] == b[n-1]) return 1 + lcs(a,b,m-1,n-1);
//    else return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
//}
// Dynamic Programming
int lcs(string a, string b, int m, int n) {
    int dp[100][100];
    for( int i=0 ; i <= m ; i++) {
        for( int j=0 ; j <= n ; j++) {
            if( 0 == j || 0 == i) dp[i][j] = 0;
            else if (a[i] == b[j]) dp[i][j] =  dp[i-1][j-1] + 1;
            else {
                dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string a,b;
    cin >> a >> b;
    cout << lcs(a,b,a.size(),b.size());
    return 0;
}
