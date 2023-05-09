#include <iostream>
#include <iomanip>
using namespace std;
struct Point
{
    public:
    Point(double x_,double y_) {x=x_;y=y_;}
    void print()
    {
        cout << x << " " << y << endl;
    }
    double x,y;
};
void TruyenThamTri(Point x)
{
    cout << &x << endl;
}
void TruyenThamChieu(Point &x)
{
    cout << &x << endl;
}
Point mid_point(const Point a,const Point b)
{
    Point c = Point((a.x+b.x)/2.0,(a.y+b.y)/2.0);
    return c;
}
int main()
{
    cout << fixed << setprecision(2);
    Point A = Point(2,1);
    Point B = Point(2,2);
    A.print();
    B.print();
    cout << &A << " ";
    TruyenThamTri(A);
    cout << &A << " ";
    TruyenThamChieu(A);
    Point C = mid_point(A,B);
    C.print();
    cout << &A << " " << &(A.x) << " " << &(A.y) << endl;
    cout << "Bien x khai bao truoc nen trung voi dia chi cua bien Point, bien y khai bao sau nen co dia chi cach dia chi cua bien Point 8bit= luong luu tru cua 1 double\n";
    return 0;
}
