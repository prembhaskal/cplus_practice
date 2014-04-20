#include <stdio.h>
#include <string>

using namespace std;

int bits [1025][1025];
int nums [1025][1025];
int N;

// this finally got accepted :)
void update1D(int idxOfBit, int idx, int val) {
	idx++;
	
	while ( idx <= N) {
		bits[idxOfBit][idx] += val;
		idx += (idx & -idx);
	}
	
}

int sumTill1D(int idxOfBit, int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += bits[idxOfBit][idx];
		idx -= (idx & -idx);
	}
	
	return sum;
}

int sum1D(int idxOfBit, int low, int high) {
	low++;
	high++;
	
	int sum = sumTill1D(idxOfBit, high);
	sum -= sumTill1D(idxOfBit, low - 1);
	return sum;
}

void update2D(int x, int y, int val) {
	y++;
	while (y <= N) {
		update1D(y, x, val);
		y += (y & -y);
	}
}

int sumTill2D(int y, int x1, int x2) {
	int sum = 0;
	while (y > 0) {
		sum += sum1D(y, x1, x2);
		y -= (y & -y);
	}
	return sum;
}

int sum2D(int y1, int y2, int x1, int x2) {
	y1++;
	y2++;
	int sum = sumTill2D(y2, x1, x2);
	sum -= sumTill2D(y1 - 1, x1, x2);
	return sum;
}

 void solve() {
 	#ifndef ONLINE_JUDGE
 		freopen("../input.txt", "r", stdin);
 		freopen("../output.txt", "w", stdout);
 	#endif
 	
 	int tests;
 	scanf("%d", &tests);
 	
 	for (int i = 0; i < tests; i++) {
	 	scanf("%d", &N);
	 	char operation[4];
	 	int x1, y1, x2, y2, val, sum, diff;
	 	
	 	// initialize to 0;
	 	for (int j = 0; j < 1025; j++) {
	 		for (int k = 0; k < 1025; k++) {
	 			nums[j][k] = 0;
	 			bits[j][k] = 0;
	 		}
	 	}
	 	
	 	while (true) {
	 		scanf("%s", operation);
	 		if (operation[1] == 'E') {
	 			scanf("%d", &x1);
	 			scanf("%d", &y1);
	 			scanf("%d", &val);
	 			
	 			diff = val - nums[x1][y1];
	 			nums[x1][y1] = val;
	 			update2D(x1, y1, diff);
	 		}
	 		else if (operation[1] == 'U') {
	 			scanf("%d", &x1);
	 			scanf("%d", &y1);
	 			scanf("%d", &x2);
	 			scanf("%d", &y2);
	 			sum = sum2D(y1, y2, x1, x2);
	 			printf("%d", sum);
	 			printf("\n");
	 		}
	 		else {
	 			break;
	 		}
	 	}
 	}
 	
 }
 
 int main() {
 	solve();
 	return 0;
 }
