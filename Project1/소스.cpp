#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	srand(time(NULL)); // rand()함수의 seed를 time()함수로 초기화

	double balance = 1000;
	int bet;
	int otherBet = rand() % 20000;
	double amount;
	int pCard[13] = {0, 0};
	int bCard[13] = {0, 0, 0};
	bool wildcard;
	int pTotal;
	int bTotal;


	do {
		std::cout << "\n\n********************** THE MINI BACCARAT **********************\n\n";

		std::cout << "CASH IN DEPOSIT : " << '$' << balance << "\n\n";

		std::cout << "Place your bet. (Please answer in numbers.)\n\n";

		std::cout << "1. PLAYER (X 2)" << "\t\t" << "2. BANKER (X 1.75)" << "\t\t" << "3. TIE ( X 8 )" << "\n\n";

		cin >> bet;
		cin.ignore();

		// 어떤 결과에 베팅을 할 것 인지 고르기

		std::cout << "\n\nHow much do you want to place : \n\n";

		cin >> amount;
		cin.ignore();
		balance -= amount;

		// 얼마 베팅 할 것인지 입력하기

		std::cout << "\nthe total bet on the table would be \n" << "$" << otherBet + amount << "\n";


		std::cout << "\n\n====================== PLAYER의 카드 ======================\n\n";

		for (int i = 0; i < 1; i++) {

			for (int i = 0; i < 2; i++) {
				pCard[i] = rand() % 13 + 1;

				if (pCard[1] == pCard[0]) {
					i--;
				} // 2번째 카드가 1번째 카드와 결과값이 중복될 때 중복값이 안 나올때까지 인덱스 반복
				else if (pCard[i] == 1) {
					std::cout << i + 1 << "번째 카드 : " << "A\n";
					pTotal = pCard[0] + pCard[1];
				}
				else if (pCard[i] == 11) {
					std::cout << i + 1 << "번째 카드 : " << "J\n";
					pTotal = pCard[0] + pCard[1];
				}
				else if (pCard[i] == 12) {
					std::cout << i + 1 << "번째 카드 : " << "Q\n";
					pTotal = pCard[0] + pCard[1];

				}
				else if (pCard[i] == 13) {
					std::cout << i + 1 << "번째 카드 : " << "K\n";
					pTotal = pCard[0] + pCard[1];

				}// 1, 11, 12, 13을 A, J, Q, K로 바꾸기

				else {
					std::cout << i + 1 << "번째 카드 : " << pCard[i] << "\n";
					pTotal = pCard[0] + pCard[1];

				}
			}
			std::cout << "\n두 카드의 합: " << pCard[0] + pCard[1] << "\n";
		}
		// PLAYER의 카드 생성

		std::cout << "\n\n====================== BANKER의 카드 ======================\n\n";

		for (int i = 0; i < 3; i++) {

			bCard[i] = rand() % 13 + 1;

			if (bCard[i] == bCard[i - 1]) {
				i--;
			}
			else if (bCard[0] + bCard[1] >= 15) {

				if (bCard[i] == 1) {
					std::cout << i + 1 << "번째 카드 : " << "A\n";
					bTotal = bCard[0] + bCard[1];

				}
				else if (bCard[i] == 11) {
					std::cout << i + 1 << "번째 카드 : " << "J\n";
					bTotal = bCard[0] + bCard[1];

				}
				else if (bCard[i] == 12) {
					std::cout << i + 1 << "번째 카드 : " << "Q\n";
					bTotal = bCard[0] + bCard[1];

				}
				else if (bCard[i] == 13) {
					std::cout << i + 1 << "번째 카드 : " << "K\n";
					bTotal = bCard[0] + bCard[1];

				}
				else {
					std::cout << i + 1 << "번째 카드 : " << bCard[i] << "\n";
					bTotal = bCard[0] + bCard[1];

				}
				break;
			}

			else {
				if (bCard[i] == 1) {
					std::cout << i + 1 << "번째 카드 : " << "A\n";
					bTotal = bCard[0] + bCard[1] + bCard[2];

				}
				else if (bCard[i] == 11) {
					std::cout << i + 1 << "번째 카드 : " << "J\n";
					bTotal = bCard[0] + bCard[1] + bCard[2];

				}
				else if (bCard[i] == 12) {
					std::cout << i + 1 << "번째 카드 : " << "Q\n";
					bTotal = bCard[0] + bCard[1] + bCard[2];

				}
				else if (bCard[i] == 13) {
					std::cout << i + 1 << "번째 카드 : " << "K\n";
					bTotal = bCard[0] + bCard[1] + bCard[2];

				}
				else {
					std::cout << i + 1 << "번째 카드 : " << bCard[i] << "\n";
					bTotal = bCard[0] + bCard[1] + bCard[2];

				}
			}
		}
		// BANKER의 카드 생성

		if (bCard[0] + bCard[1] <= 14) {
			wildcard = true;
		}
		else {
			wildcard = false;
		}
		wildcard ? std::cout << "\n세 카드의 합: " << bCard[0] + bCard[1] + bCard[2] << "\n" : std::cout << "\n두 카드의 합: " << bCard[0] + bCard[1] << "\n";
		// BANKER의 카드가 2장인지 3장인지에 따라 각 각 다른 문구 출력

		if (pTotal > bTotal && bet == 1) {
			std::cout << "\n\n********* YOU WON *********\n\n";
			balance += (otherBet + amount) * 2;
			std::cout << "Your balance is " << "$" << balance << "\n";
		}
		else if (bTotal > pTotal && bet == 2) {
			std::cout << "\n\n********* YOU WON *********\n\n";
			balance += (otherBet + amount) * 1.75f;
			std::cout << "Your balance is " << "$" << balance << "\n";

		}
		else if (pTotal == bTotal && bet == 3) {
			std::cout << "\n\n********* YOU WON *********\n\n";
			balance += (otherBet + amount) * 8;
			std::cout << "Your balance is " << "$" << balance << "\n";

		}
		else {
			std::cout << "\n\n********* YOU LOST *********\n\n";
			std::cout << "Your balance is " << "$" << balance << "\n";
		}

	}while (balance > 0);


}
