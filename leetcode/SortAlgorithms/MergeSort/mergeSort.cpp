#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortCall(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2; 
    mergeSortCall(arr, left, mid);
    mergeSortCall(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int>& arr) {
    mergeSortCall(arr, 0, arr.size() - 1);
}

// Testing
int main() {
    vector<int> nums = {5, 2, 9, 1, 5, 6};
    
    cout << "Before sorting: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    mergeSort(nums);

    cout << "After sorting: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
