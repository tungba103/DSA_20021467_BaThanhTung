#include<iostream>
//#include<stdio.h>
//#define MAX 8
using namespace std;
 
int A[8][8] = { 0 };//Kh?i t?o m?ng giá tr? 0
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;//S? bu?c di
int n;
int count=1;
 
void xuat() {
	cout << "Cach thu " << count++ << " la:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", A[i][j]);
        cout << endl;
    }
    cout << endl;
}
 
void diChuyen(int x, int y) {
    ++dem;//Tang giá tr? bu?c di
    A[x][y] = dem;//Ðánh d?u dã di
    for (int i = 0; i < 8; i++)    {
        //Ki?m tra xem mã dã di h?t bàn c? chua
        if (dem == n * n) {
            cout << "Cac buoc di la: \n";
            xuat();
            return;
        }
        int u = x + X[i];//t?o m?t v? trí x m?i
        int v = y + Y[i];//t?o m?t v?i trí y m?i
        if (u >= 0 && u < n &&v >= 0 && v < n && A[u][v] == 0)
            diChuyen(u, v);
    }
    --dem;
    A[x][y] = 0;
}
int main() {
    cout << "Nhap n: ";
    cin >> n;
    for(int i=0 ; i< n ; i++) 
    {
    	for(int j=0 ; j< n ; j++)
    		diChuyen(i,j);
	}
    cout << "Khong tim thay duong di.";
}
