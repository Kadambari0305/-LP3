
#include <bits/stdc++.h>
using namespace std;

int partitionDet(vector<int>& a, int low, int high) {
    int pivot = a[high];  // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortDet(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionDet(a, low, high);

        quickSortDet(a, low, p - 1);
        quickSortDet(a, p + 1, high);
    }
}

// Randomized Quick Sort
int partitionRandom(vector<int>& a, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

       swap(a[randomIndex], a[high]);

    return partitionDet(a, low, high);
}

void quickSortRandom(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionRandom(a, low, high);

        quickSortRandom(a, low, p - 1);
        quickSortRandom(a, p + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b = a;

    srand(time(0));

    auto start1 = chrono::high_resolution_clock::now();

    quickSortDet(a, 0, n - 1);

    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    quickSortRandom(b, 0, n - 1);

    auto end2 = chrono::high_resolution_clock::now();

    double time1 = chrono::duration<double, milli>(
        end1 - start1).count();

    double time2 = chrono::duration<double, milli>(
        end2 - start2).count();

    cout << "\nSorted array using Deterministic Quick Sort:\n";
    for (int x : a)
        cout << x << " ";

    cout << "\n\nSorted array using Randomized Quick Sort:\n";
    for (int x : b)
        cout << x << " ";

    cout << fixed << setprecision(6);
    cout << "\n\nDeterministic Quick Sort time: "
         << time1 << " ms";

    cout << "\nRandomized Quick Sort time: "
         << time2 << " ms\n";

    return 0;
}
 
/*Input:
Enter number of elements: 5
Enter elements:
5 2 8 1 4

Output:

Sorted array using Deterministic Quick Sort:
1 2 4 5 8

Sorted array using Randomized Quick Sort:
1 2 4 5 8

Deterministic Quick Sort time: 0.001000 ms
Randomized Quick Sort time: 0.002000 ms*/

