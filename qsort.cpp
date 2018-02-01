#include <iostream>
#include <vector>

using namespace std;

void qsort(int l, int r, vector<int>& arr) {
    if (l >= r)
        return;
    cout << l << "-" << r << endl;
    
    int piv = arr[r];
    int i = l;
    for (int j = l; j <= r; j++)
        if (arr[j] <= piv)
            swap(arr[i++], arr[j]);
    qsort(l, i - 1, arr);
    qsort(i, r, arr);
}

void QuickSort(vector<int>& arr) {
    qsort(0, arr.size() - 1, arr);
}

int main() {
    cout << "hello" << endl;
    vector<int> a{2,7,3,6,8,5,2,4,6};
    for (auto x : a)
        cout << x << " " << endl;
    QuickSort(a);
    for (auto x : a)
        cout << x << " " << endl;;
}
