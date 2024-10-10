//suffixSum[i + 1] -> suffix sum
//prefixSum[i - 1] -> prefix sum
vector<int> createSuffixSum(vector<int> arr, int n)
{
    // Create an array to store the suffix sum
    vector<int> suffixSum(n, 0);
 
    // Initialize the last element of
    // suffix sum array with last element
    // of original array
    suffixSum[n - 1] = arr[n - 1];
 
    // Traverse the array from n-2 to 0
    for (int i = n - 2; i >= 0; i--)
 
        // Adding current element
        // with previous element from back
        suffixSum[i] = suffixSum[i + 1] + arr[i];
 
    // Return the computed suffixSum array
    return suffixSum;
}
 