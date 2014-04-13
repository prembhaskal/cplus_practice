#include <stdio.h>

using namespace std;

int nums[1000001];
int lookUpIdx[1000001];
int highValue = 10000000;


int getMinTimeRequired(int size, int reqdSum) {
	// fill with a high number initially
	for (int i = 0; i < 1000001; i++)
		lookUpIdx[i] = highValue;
	
	// fill the look idx now 
	// front to middle
	for (int i = 0; i <= size / 2; i++) {
		int type = nums[i];
		lookUpIdx[type] = (lookUpIdx[type] < i ? lookUpIdx[type] : i);
	}
	
	// now back to middle
	for (int i = size - 1; i >= size / 2; i--) {
		int type = nums[i];
		lookUpIdx[type] = (lookUpIdx[type] < size - 1 - i ? lookUpIdx[type] : size - 1 - i);
	}
	
	// now find the required sum
	int minTimeReqd = highValue;
	for (int a = 1; a < reqdSum; a++) {
		int b = reqdSum - a;
		if (a == b) {
			continue;
		}
		
		int timeReqd = (lookUpIdx[a] > lookUpIdx[b] ? lookUpIdx[a] : lookUpIdx[b]);
		minTimeReqd = (minTimeReqd < timeReqd ? minTimeReqd : timeReqd);
		
	}
		
		if (minTimeReqd > 1000000)
			return -1;
			
		return minTimeReqd + 1;
	}
	


void solve() {
	
	
	// read from file for local
	
	#ifndef ONLINE_JUDGE
	freopen("../inp_out/input.txt", "r", stdin);
	freopen("../inp_out/output.txt", "w", stdout);
	#endif
	
	int size;
	scanf("%d", &size);
	
	int reqdSum;
	scanf("%d", &reqdSum);
	
	for (int i = 0; i < size; i++)
		scanf("%d", &nums[i]);
	
	int minTime = getMinTimeRequired(size, reqdSum);
	
	printf("%d", minTime);
	printf("\n");
}

int main() {
	solve();
	return 0;
}


