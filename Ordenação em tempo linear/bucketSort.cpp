#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    std::vector<std::vector<float>> buckets(n);

    for (float num : arr) {
        int index = num * n;
        buckets[index].push_back(num);
    }

    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    int index = 0;
    for (auto& bucket : buckets) {
        for (float num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    std::vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucketSort(arr);

    for (float num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
