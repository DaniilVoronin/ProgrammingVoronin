#include<iostream>
#include "Pair.h"
using namespace std;

int main() {
	Pair p1, p2;
	cin >> p1 >> p2;
	cout << p1 << " & " << p2 << endl;
	cout << (p1 > p2) << (p1 < p2) << (p1 == p2) << (p1 != p2) << endl;
	Fraction f1, f2;
	cin >> f1 >> f2;
	cout << f1 << "; " << f2 << endl;
	cout << (f1 > f2) << (f1 < f2) << (f1 == f2) << (f1 != f2) << endl;
	return 0;
}