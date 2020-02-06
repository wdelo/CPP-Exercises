#define _CRT_SECURE_NO_WARNINGS
#include "Windows.h"
#include "stdlib.h"
#include "string"
using namespace std;

class NumberWordPair {
public:
	NumberWordPair(int _number, string _word) : number(_number), word(_word) {}
	int number;
	string word;
};

int main() {
	NumberWordPair nwps[]{
		NumberWordPair(3, "Fizz"),
		NumberWordPair(5, "Buzz"),
		NumberWordPair(7, "Pop")
	};

	for (int i = 1; i <= 1000; i++) {
		bool bFoundMatch = false;
		for (int j = 0; j < (sizeof(nwps) / sizeof(NumberWordPair)); j++) {
			if (i % nwps[j].number == 0) {
				printf(nwps[j].word.c_str());
				bFoundMatch = true;
			}
		}
		if (!(bFoundMatch)) {
			printf("%i", i);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}