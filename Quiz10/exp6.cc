#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char *greeting = new char[1024];
	strcpy(greeting, "Dear");
	cout << greeting << "Sir/Madam\n";
	delete[] greeting;
	return 0;
}
