#include <iostream>
#include "ModelWindow.h"
using namespace std;
int main()
{
	ModelWindow m;
	cout << "Enter: title, x, y, width, height, color, show, border" << endl;
	cin >> m;
	cout << m << "Changing window size to 150x100px and move window 30px to right and 40px down" << endl;
	m.changeFormat(100, 150);
	m.moveVertical(40);
	m.moveHorisontal(30);
	cout << m;
	return 0;
}
