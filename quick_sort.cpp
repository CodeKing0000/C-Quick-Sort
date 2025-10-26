#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& a, int first, int last) {
    int pivot = a[(first + last) / 2];
    int left = first;
    int right = last;

    while (true) {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left >= right) break;
        std::swap(a[left++], a[right--]);
    }

    return right;
}

void quick_sort(std::vector<int>& a, int first, int last) {
    if (first >= last) return;
    int pivot = partition(a, first, last);
    quick_sort(a, first, pivot);
    quick_sort(a, pivot + 1, last);
}

int main() {
    std::vector<int> a = {1, 3, 2, 5, 4, 6, 8, 7, 9};
    quick_sort(a, 0, static_cast<int>(a.size()) - 1);
    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
