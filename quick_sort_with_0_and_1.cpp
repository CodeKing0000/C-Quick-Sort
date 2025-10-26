#include <iostream>
#include <vector>
#include <algorithm>

void foo(std::vector<int>& a) {
    for(int i; i < a.size(); i++) {
        if(i % 2 == 1) {
            a[i] = 0;
        }
        else {
            a[i] = 1;
        }
    }
}
    

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
    std::vector<int> a = {4, 3, 2, 1};
    foo(a);
    quick_sort(a, 0, static_cast<int>(a.size()) - 1);
    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
