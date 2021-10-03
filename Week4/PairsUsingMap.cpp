#include <bits/stdc++.h>

using namespace std;

int n, k, a[100005];
map <int, int> m;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += m[a[i] + k];
    }
    cout << res;
}
