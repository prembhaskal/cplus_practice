#include <stdio.h>

using namespace std;

int pow(long long num, long long pow) {
	long long power = 1;
	while(pow > 0) {
		if ((pow & 1) == 1) {
			power = (power * num) % 10;
		}
		
		pow /= 2;
		num = (num * num) % 10;
	}
	
	return (int)power;
}

void solve() {
	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
	
	int tests;
	scanf("%d", &tests);
	
	for (int i = 0; i < tests; i++) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		
		int lastDigit = pow(a, b);
		printf("%d", lastDigit);
		printf("\n");
	}
	
}

int main() {
	solve();
	return 0;
}
