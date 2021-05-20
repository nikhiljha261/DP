ll kadane(vi &temp, int &start, int &end) {

	ll sum = 0;

	ll maxSum = INT_MIN;

	end = -1;

	int n = temp.size();

	int tempStart = 0;

	loop(i, 0, n-1) {

		sum += temp[i];

		if(sum < 0) {

			sum = 0;

			tempStart = i+1;

		} else if(sum > maxSum) {

			maxSum = sum;

			start = tempStart;

			end = i;

		}

	}

 
	if(end != -1) return maxSum;

 
	maxSum = temp[0];

	start = end = 0;

	loop(i, 1, n-1) {

		if(maxSum < temp[i]) {

			maxSum = temp[i];

			start = end = i;

		}

	}

	return maxSum;

}

 
vi maxSumRect(vector<vector<ll> > &arr) {

	int n = arr.size();

	int m = arr[0].size();

	ll result = INT_MIN;

	vi temp(n, 0);

	int start, end, tlc, tlr, brc, brr;

	for(int leftCol = 0; leftCol < m; leftCol++) {

		temp.assign(n, 0);

		for(int rightCol = leftCol; rightCol < m; rightCol++) {

			for(int i = 0; i < n; i++) {

				temp[i] += arr[i][rightCol];

			}

			int sum = kadane(temp, start, end);

			//log(sum, leftCol, rightCol);

			if(sum > result) {

				result = sum;

				tlc = leftCol;

				brc = rightCol;

				tlr = start;

				brr = end;

			}

		}

	}

	return {result, tlr, tlc, brr, brc};

}
