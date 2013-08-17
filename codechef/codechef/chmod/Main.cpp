#include <stdio.h>

using namespace std;

int elements;
int nums[100010];
int counter[111];
long long segmentProd;
int elementMap[100010][111];
int pow;
int powerRaise;

// initialize the counter for the elements.
void initialize() {
	
	for (int i=0;i<101;i++) {
		counter[i] = 0;
	}
	
	for (int i=0;i<elements;i++) {
		int idx = nums[i];
		counter[idx]++;
		
		for (int j=1;j<101;j++) {
			elementMap[i][j] = counter[j];
		}
	}
}

int power(int num, int pow, int mod) {
	long long power = 1;
	
	while(pow > 0) {
		if ((pow&1)==1) {
			power = (power * num) % mod;
		}
		
		num = ((long long)num * num) % mod;
		pow /= 2;
	}
	
	return (int)power;
}

// get the segment prod
int getSegmentProd(int left, int right, int mod) {
	segmentProd = 1;
	
	for (int i=2;i<101;i++) {
		pow = elementMap[right][i] - elementMap[left][i];
		powerRaise = power(i, pow, mod);
		segmentProd = (segmentProd * powerRaise) % mod;
		if (segmentProd == 0) {
			break;
		}
	}
	
	segmentProd = (segmentProd * nums[left]) % mod;
	
	return (int)segmentProd;
}

// brute to verify that it works.
int getSegProdBrute(int left, int right, int mod) {
	long long prod = 1;
	for (int i=left;i<=right;i++) {
		prod = (prod * nums[i]) % mod;
	}
	
	return (int) prod;
}


void solve() {
	
	
// read from file for local

#ifndef ONLINE_JUDGE
freopen("../../inp_out/input.txt", "r", stdin);
freopen("../../inp_out/output.txt", "w", stdout);
#endif

	scanf("%d", &elements);
	
//	printf("the number of elements are %d", elements);
//	printf("\n");
	
	for (int j=0;j<elements;j++) {
		scanf("%d", &nums[j]);
	}
	
	//intialize for this array;
	initialize();

	int queries;
	scanf("%d", &queries);
	
//	printf("the number of queries are %d", queries);
//	printf("\n");
	
	int left;
	int right;
	int mod;
	int product;
	
	for (int i=0;i<queries;i++) {
		scanf("%d", &left);
		scanf("%d", &right);
		scanf("%d", &mod);
		left--;
		right--;
		product = getSegmentProd(left, right, mod);
		printf("%d", product);
		printf("\n");
	}
	

}

int main() {
	solve();
	
	// test timing
	/*
	for (int i=0;i<100000;i++) {
		nums[i] = i%(100) + 1;
	}
	
	initialize();
	
	for (int i=1;i<=100000;i++) {
		int prod = getSegmentProd(2, 9999, 485747);
	}
	*/
	
	// test correctness
	/*
	int mod = 487587;
	elements = 1000;
	for (int i=0;i<elements;i++) {
		nums[i] = 89;
	}
	
	initialize();
	
	for (int i=0;i<elements;i++) {
		for (int j=i;j<elements;j++) {
			int prod1 = getSegmentProd(i,j,mod);
			int prod2 = getSegProdBrute(i,j,mod);
			
			if (prod1 != prod2) {
				printf("PROBLEM");
				printf("\n");
			}
		}
	}
	*/
	
	return 0;
}


