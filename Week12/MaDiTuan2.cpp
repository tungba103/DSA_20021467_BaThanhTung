#include <iostream>
using namespace std;
int a[10001];
int x[] = {2,1,-1,-2,-2,-1,1,2};
int y[] = {-1,-2,-2,-1,1,2,2,1};
int dem = 0;
int n;
int count = 1;
void ThuNuocDiTiep(int x, int y) {
	++ dem;
	
	
	if ( a[cX] == n*n) {
		cout << "cach thu " << count++ < "la: " << endl;
		for(int i=0 ; i< n*n ;i++) {
			cout << a[i];
			if( (i+1) % 8 == 0) cout << endl;
		}
	}
	if ( a[cX] < n*n) {
		int coordinate =0;
		for(int i=0 ; i< n ; i++)
		if(a[cX + x[i]] == 0 && (cX + i) >=0 && (cX + i) <=7 && (a[cX + i] >=0)  && (a[cX + i] <=7)) {
			success = true;
			a[cX + x[i]] == a[cX] + 1;
			ThuNuocDiTiep(cX+i,n,success);
		}
		if (!success) {
//			a[cX] = 0;
			return;
		}	
	}

}

int main() {
	int n;
	cin >> n;
	for(int i=0 ; i< n*n; i) a[i] = 0;
	for(int i=0 ; i< n*n; i++) {
		ThuNuocDiTiep(i,n,false);
	}
	return 0;
}
