#include <iostream>
using namespace std;
int a[8][8] = {0};
int x[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
//int x[] = {2,1,-1,-2,-2,-1,1,2};
//int y[] = {-1,-2,-2,-1,1,2,2,1};
int dem = 0;
int n;
int count = 1;
void xuat() {
	cout  << "Cach thu " << count++ << " la:" << endl;
	for(int i=0 ;i < n ;i++)
	{
		for(int j=0 ; j< n ;j ++)
			cout << a[i][j] << " ";
			cout << endl;
	}
	cout << endl;
}
void MaDiTuan(int cX, int cY) {
	++dem;
	a[cX][cY] = dem;
	for(int i=0 ; i< 8 ;i++) 
	{
		if (dem == n * n) {	
	        xuat();
	        return;
   		}
   		int u = cX + x[i];
   		int v = cY + y[i];
		if( a[u][v] ==0 && u >=0 && u <n && v >=0 && v <n ) {
			MaDiTuan(u,v);
		}
	}
	-- dem;
	a[cY][cY] =0;
}
int main () {
	int n;
	cin >> n ;
//	for(int i=0 ; i< n ; i++)
//		for(int j=0 ; j < n ; j++)
//			a[i][j] = 0;
	for(int i=0 ; i< n ; i++)
		for(int j=0 ; j < n ; j++)
			MaDiTuan(i,j);
	return 0;
}
