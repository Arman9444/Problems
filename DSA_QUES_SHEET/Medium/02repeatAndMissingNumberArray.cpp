vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size(); // Size of the array
    long long S = n * (n + 1) / 2; // Sum of the first n natural numbers
    long long S2 = n * (n + 1) * (2 * n + 1) / 6; // Sum of squares of the first n natural numbers

    long long sum = 0, sum2 = 0;

    // Calculate the actual sum and sum of squares from the array
    for (int num : A) {
        sum += num;
        sum2 += (long long)num * num;
    }

    // A - B = diff
    long long diff = sum - S;

    // A^2 - B^2 = sumDiff
    long long sumDiff = sum2 - S2;

    // Solve for A and B
    long long sumAB = sumDiff / diff; // A + B

    int A_val = (diff + sumAB) / 2; // Repeated number
    int B_val = sumAB - A_val; // Missing number

    return {A_val, B_val};
}