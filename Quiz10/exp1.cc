#include <iostream>
using namespace std;

int main() {
	char *x = new char[100];
	if (x == NULL)
		cout << "This won't occur--new throws an error on failure!\n";
	delete[] x;
	return 0;
}
