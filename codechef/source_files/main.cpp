#include <stdio.h>

using namespace std;

int num[10001];
long long maxFwd[10001];
long long maxRev[10001];
long long minFwd[10001];
long long minRev[10001];

void createMaxMinFwdRev(int size) {
	
		// create maxFwd
		long long max_till_here = num[0];
		long long max_so_far = num[0];
		maxFwd[0] = max_so_far;
		for (int i=1;i<size;i++) {
			if (max_till_here < 0) {
				max_till_here = num[i];
			} else {
				max_till_here += num[i];
			}

			if (max_till_here >= max_so_far) {
				max_so_far = max_till_here;
			}

			maxFwd[i] = max_so_far;
		}

		// create maxRev
		max_till_here = num[size-1];
		max_so_far = num[size-1];
		maxRev[size-1] = max_so_far;

		for (int i=size-2;i >=0;i--) {
			if (max_till_here < 0) {
				max_till_here = num[i];
			} else {
				max_till_here += num[i];
			}

			if (max_till_here >= max_so_far) {
				max_so_far = max_till_here;
			}

			maxRev[i] = max_so_far;
		}

		// create minFwd
		long long min_till_here = num[0];
		long long min_so_far = num[0];
		minFwd[0] = min_so_far;

		for (int i=1;i<size;i++) {
			if (min_till_here > 0) {
				min_till_here = num[i];
			} else {
				min_till_here += num[i];
			}

			if (min_till_here <= min_so_far) {
				min_so_far = min_till_here;
			}
			minFwd[i] = min_so_far;
		}

		// create minRev
		min_till_here = num[size-1];
		min_so_far = num[size-1];
		minRev[size-1] = min_so_far;

		for (int i=size-2;i>=0;i--) {
			if (min_till_here > 0) {
				min_till_here = num[i];
			} else {
				min_till_here += num[i];
			}

			if (min_till_here <= min_so_far) {
				min_so_far = min_till_here;
			}
			minRev[i] = min_so_far;
		}

}

long long getMaxSubArrayDifference(int size) {
	
		createMaxMinFwdRev(size);

		long long bestDiff = -1e18;

		// test for max on left side and min on right side
		for (int i = 0; i < size-1; i++) {
			long long diff = maxFwd[i] - minRev[i+1];
			diff = diff > 0 ? diff : (-1) * diff;
			bestDiff = diff > bestDiff ? diff : bestDiff;//Math.max(diff, bestDiff);
		}

		// test for min on left side and max on right side
		for (int i=0;i<size-1;i++) {
			long long diff = minFwd[i] - maxRev[i+1];
			diff = diff > 0 ? diff : (-1) * diff;
			bestDiff = diff > bestDiff ? diff : bestDiff;
		}

		return bestDiff;

}

void solve() {
	
	
// read from file for local

#ifndef ONLINE_JUDGE
freopen("../inp_out/input.txt", "r", stdin);
freopen("../inp_out/output.txt", "w", stdout);
#endif

	int tests;

	scanf("%d", &tests);

	for (int i=0;i<tests;i++) {
		int size;
		scanf("%d", &size);

		for (int j=0;j<size;j++) {
			scanf("%d", &num[j]);
		}

		// get the max sub array difference
		long long maxDiff = getMaxSubArrayDifference(size);

		printf("%lld", maxDiff);
		printf("\n");
	}

}

int main() {
	solve();
	return 0;
}


