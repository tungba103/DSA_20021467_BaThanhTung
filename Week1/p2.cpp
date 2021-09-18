#include <iostream>
#include <iomanip>
using namespace std;

class Point{
	public:
		double x;
		double y;
		Point(int _x=0, int _y=0) : x(_x), y(_y) {}
};
class Line{
	public:
		double a,b,c;  // He so cua phuong trinh duong thang ax+by=c
		Line(Point A, Point B){
			a = B.y-A.y;
			b = A.x-B.x;
			c = A.x*(B.y-A.y) + A.y*(A.x-B.x);
		}
};

void checkIntersection( Line l1, Line l2)
{
	// Xet dinh thuc cua he 2 phuong trinh 2 an
	double det = l1.a * l2.b - l1.b*l2.a;
	double det1 = l1.c*l2.b - l1.b*l2.c;
	double det2 = l1.a*l2.c - l1.c*l2.a;
	if( 0 != det) // dinh thuc khac khong => co nghiem
	{
		
		cout << fixed << setprecision(2) << det1/det << " "
			 << fixed << setprecision(2) << det2/det<< endl;
	}
	else if ( 0 == det1 && 0 == det2){ // 3 dinh thuc deu bang 0 => vo so nghiem
		 cout << "Many" << endl;
	}
	else{ // chi co det bang 0 => vo nghiem
		cout << "NO" << endl;
	}
}

// Ham khoi tao input
Line createLine(){
	double x,y,z,t;
	cin >> x >> y >> z >> t;
	Point A(x,y), B(z,t);
	Line res(A,B);
	return res;
}

int main()
{
	Line l1 = createLine();
	Line l2 = createLine();
	checkIntersection(l1,l2);
	return 0;
}
