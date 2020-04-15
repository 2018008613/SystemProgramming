#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int x = 1;

	if (time(NULL) == 42)
		x = 42;

	if (x == 0)
		cout << "x is zero\n";
	else
		cout << "x is non-zero\n";

	return 0;
}
