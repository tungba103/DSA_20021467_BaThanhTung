#include <iostream>
using namespace std;

// Recursion
string lcs(string a, string b, int m,int n) {
    if( 0 == m || 0 == n) return "";
    if ( a[m-1] == b[n-1]) {
        string x = lcs(a,b,m-1,n-1) + a[m-1];
        return x;
    }
    else {
        string x = lcs(a,b,m-1,n);
        string y = lcs(a,b,m,n-1);
        return (x.size() > y.size()) ? x : y;
    }
}

int lis(string a, int n) {
    if(1 == n) return 1;
    int res, maxLis = 1;
    for( int i=1 ; i < n; i++) {
        res = lis(a,i);
        maxLis = res;
        if(a[i-1] < a[n-1]) maxLis++;
    }
    return maxLis;
}

int main() {
    // 123456421 133459521
    // 123456789 1358789
//    string s;
//    cin >> s;
//    cout << lis(s,s.size());
    string a,b;
    cin >> a >> b;
    string x = lcs(a,b,a.size(),b.size());
    cout << lis(a,a.size()) << " " << lis(b,b.size()) << endl;
    cout << lis(x,x.size()) << endl;
    return 0;
}
