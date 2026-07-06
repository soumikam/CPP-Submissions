#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(const vector<int>& arr)
{
    cout << "[";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << (i + 1 < arr.size() ? "," : "");
    cout << "]" << endl;
}

// ── BUBBLE SORT ───────────────────────────────────────────────────────────────
// Repeatedly swaps adjacent elements if they are in wrong order
// Time: O(n²)  Space: O(1)  Stable: Yes
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// ── SELECTION SORT ────────────────────────────────────────────────────────────
// Finds the minimum element and places it at the front each pass
// Time: O(n²)  Space: O(1)  Stable: No
void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 0; i < n-1; i++)
    {
        int minIdx = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// ── INSERTION SORT ────────────────────────────────────────────────────────────
// Builds sorted array one element at a time by inserting into correct position
// Time: O(n²)  Space: O(1)  Stable: Yes
void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ── MERGE SORT ────────────────────────────────────────────────────────────────
// Divides array in half, sorts each half, then merges them
// Time: O(n log n)  Space: O(n)  Stable: Yes
void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while(i < L.size() && j < R.size())
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while(i < L.size()) arr[k++] = L[i++];
    while(j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// ── QUICK SORT ────────────────────────────────────────────────────────────────
// Picks a pivot, partitions array around it, recursively sorts each side
// Time: O(n log n) avg, O(n²) worst  Space: O(log n)  Stable: No
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
        if(arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low >= high) return;
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

// ── HEAP SORT ─────────────────────────────────────────────────────────────────
// Builds a max heap, repeatedly extracts the max to sort
// Time: O(n log n)  Space: O(1)  Stable: No
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
    if(left  < n && arr[left]  > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--)  // build max heap
        heapify(arr, n, i);
    for(int i = n-1; i > 0; i--)       // extract elements one by one
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ── COUNTING SORT ─────────────────────────────────────────────────────────────
// Counts occurrences of each value, works only for non-negative integers
// Time: O(n + k)  Space: O(k)  Stable: Yes
void countingSort(vector<int>& arr)
{
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for(int x : arr) count[x]++;
    int idx = 0;
    for(int i = 0; i <= maxVal; i++)
        while(count[i]-- > 0)
            arr[idx++] = i;
}

// ── SHELL SORT ────────────────────────────────────────────────────────────────
// Generalisation of insertion sort — sorts elements far apart first
// Time: O(n log n) ~ O(n²) depending on gap  Space: O(1)  Stable: No
void shellSort(vector<int>& arr)
{
    int n = arr.size();
    for(int gap = n/2; gap > 0; gap /= 2)
        for(int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while(j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
}

int main()
{
    vector<int> base = {64, 34, 25, 12, 22, 11, 90};

    vector<int> arr = base;
    bubbleSort(arr);
    cout << "Bubble Sort:    "; printArray(arr);

    arr = base;
    selectionSort(arr);
    cout << "Selection Sort: "; printArray(arr);

    arr = base;
    insertionSort(arr);
    cout << "Insertion Sort: "; printArray(arr);

    arr = base;
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Merge Sort:     "; printArray(arr);

    arr = base;
    quickSort(arr, 0, arr.size() - 1);
    cout << "Quick Sort:     "; printArray(arr);

    arr = base;
    heapSort(arr);
    cout << "Heap Sort:      "; printArray(arr);

    arr = base;
    countingSort(arr);
    cout << "Counting Sort:  "; printArray(arr);

    arr = base;
    shellSort(arr);
    cout << "Shell Sort:     "; printArray(arr);

    return 0;
}
