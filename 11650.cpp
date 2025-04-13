#include <iostream>
using namespace std;

typedef struct {
    int x, y;
} Dimension;

int compare(Dimension a, Dimension b) {
    if (a.x != b.x) return a.x - b.x;
    return a.y - b.y;
}

void swap(Dimension &a, Dimension &b) {
    Dimension temp = a;
    a = b;
    b = temp;
}

int partition(Dimension arr[], int left, int right) {
    Dimension pivot = arr[(left + right) / 2];
    while (left <= right) {
        while (compare(arr[left], pivot) < 0) left++;
        while (compare(arr[right], pivot) > 0) right--;
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(Dimension arr[], int left, int right) {
    if (left >= right) return;
    int index = partition(arr, left, right);
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}

int main() {
    int size;
    cin >> size;
    Dimension c[100000];

    for (int i = 0; i < size; i++) {
        cin >> c[i].x >> c[i].y;
    }

    quicksort(c, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << c[i].x << " " << c[i].y << "\n";
    }

    return 0;
}
