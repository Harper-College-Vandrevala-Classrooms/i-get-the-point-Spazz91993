#include<iostream>
#include<cmath>
using namespace std;

class Point
{
public:
	Point(double x, double y) {
		this->xCoord = x;
		this->yCoord = y;
	}
	void pp() {
		cout << "(" << this->xCoord << ", " << this->yCoord << ")";
	}
	double operator-(Point const& point2) {
		double dx = this->xCoord - point2.xCoord;
		double dy = this->yCoord - point2.yCoord;
		return sqrt(dx * dx + dy * dy);
	}
	bool operator==(Point const& point2) {
		if (this->xCoord == point2.xCoord && this->yCoord == point2.yCoord) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator!=(Point const& point2) {
		if (this->xCoord != point2.xCoord || this->yCoord != point2.yCoord) {
			return 1;
		}
		else {
			return 0;
		}
	}
	Point operator/(Point const& point2) {
		double mx = (this->xCoord + point2.xCoord) / 2;
		double my = (this->yCoord + point2.yCoord) / 2;
		return Point(mx, my);
	}
private:
	double xCoord = 0;
	double yCoord = 0;
};

int main() {
	Point p1(4, 5);
	Point p2(4, 6);
	cout << "The distance between ";
	p1.pp();
	cout << " and ";
	p2.pp();
	cout << " is " << p1 - p2 << endl;
	Point midpoint = p1 / p2;
	cout << "The midpoint between ";
	p1.pp();
	cout << " and ";
	p2.pp();
	cout << " is ";
	midpoint.pp();
	if (p1 == p2) {
		cout << "\nThe points are the same coordinate!" << endl;
	}
	if (p1 != p2) {
		cout << "\nThe points are not the same." << endl;
	}
	return 0;
}