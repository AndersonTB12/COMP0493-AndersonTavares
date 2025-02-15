#include <iostream>
#include <vector>

int mergeAndCount(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    std::vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left, swaps = 0;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            swaps += (n1 - i);
        }
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    return swaps;
}

int countInversions(std::vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = countInversions(arr, left, mid) + countInversions(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

int main() {
    std::vector<int> arr = {2, 4, 1, 3, 5};
    std::cout << "Número de inversões: " << countInversions(arr, 0, arr.size() - 1) << std::endl;
    return 0;
}
