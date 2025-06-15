#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    ll invCount = 0;

    invCount += mergeSort(arr, left, mid);
    invCount += mergeSort(arr, mid + 1, right);

    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            invCount += (mid - i + 1);
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];

    return invCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n);
    unordered_map<int, int> mapA;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mapA[A[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
        B[i] = mapA[B[i]];
    }

    for (int i = 0; i < n; i++) {
        cin >> C[i];
        C[i] = mapA[C[i]];
    }

    // Count inversions between A-B and A-C
    ll invAB = mergeSort(B, 0, n - 1);

    // Make a copy before reusing
    vector<int> C_copy = C;
    ll invAC = mergeSort(C_copy, 0, n - 1);

    // Map B back to index positions for B-C comparison
    unordered_map<int, int> mapB;
    for (int i = 0; i < n; i++) {
        mapB[B[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        C_copy[i] = mapB[C[i]];
    }

    ll invBC = mergeSort(C_copy, 0, n - 1);

    ll total_pairs = 1LL * n * (n - 1) / 2;
    ll bad_pairs = (invAB + invAC + invBC) / 2;
    ll good_pairs = total_pairs - bad_pairs;

    cout << good_pairs << endl;
    return 0;
}
