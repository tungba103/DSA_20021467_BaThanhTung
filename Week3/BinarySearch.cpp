#include <iostream>
using namespace std;
int BinarySearch(int a[], int n, int x){
	int l = 0, r = n-1;
	while (l < r){
		int mid = (l+r)/2;
		if (a[mid] < x){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	if (a[l] == x){
		return l;
	}
	return -1;
}
int main()
{
    int n,x;
    cin >> n;
    int a[10001];
    for(int i=0 ;i < n; i++)
        cin >> a[i];
    cin >> x;
    int res = BinarySearch(a,n,x);
    cout << res << endl;
    
    return 0;
}
