#include <iostream>
using namespace std;
// MergeSort
int a[1000];
void merge( int l,int mid, int r)
{
    int i,j,k;
    int _a = mid- l+1;
    int _b = r-mid;
    int* L = new int[_a];
    int* R = new int[_b];
    for( int i=0 ; i< _a ; i++)
        L[i] = a[l+i];
    for(int i=0 ; i< _b ;i++)
        R[i] = a[mid+i+1];
    i=0;
    j=0;
    k=l;
    while ( i < _a && j < _b)
    {
        if( L[i] <= R[j])
            {
                a[k] = L[i];
                i++;
            }
        else
            {
                a[k] = R[j];
                j++;
            }
        k++;
    }
    while (i < _a){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < _b){
        a[k] = R[j];
        j++;
        k++;
    }
    delete[]L;
    delete[]R;
    return;
}

void sort( int l, int r )
{
    if( l < r)
    {
    int mid = (l+r)/2;
    sort(l,mid);
    sort(mid+1,r);
    merge(l,mid,r);
    }
}

int main()
{
	int n;
	cin >> n;
	for(int i=0 ; i < n ; i++)
		cin >> a[i];
	sort(0,n-1);
	for(int i=0 ; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
