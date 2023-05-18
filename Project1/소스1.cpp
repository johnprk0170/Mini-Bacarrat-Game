#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));

	int card[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

	for (int i = 0; i < 13; i++) {
		card[i] = (rand() % 13) + 1;
		cout << i;
	}
}