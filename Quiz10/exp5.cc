#include <iostream>
#include <ctime>
using namespace std;

int main() {
	char x[10] = { 00,11,22,33,44,55,66,77,88,99 };
	x[9] = 'a';
	return x[0];
}
