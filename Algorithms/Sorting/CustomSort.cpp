#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int linear_search(vector<int>& array, int num)
{
    int index = -1;
    int n = array.size();
    for(int i=0; i<n; i++)
    {
        if(num == array[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

int binary_search(vector<int>& array, int num)
{
    int index = -1;
    int n = array.size();
    int left = 0;
    int right = n-1;
    int mid = 0;
    while(left<=right)
    {
        mid = left + (right-left)/2;
        if(array[mid]==num)
        {
            index = mid;
            break;
        }
        if(array[mid]<num)
        {
            left = mid+1;
        }
        if(array[mid]>num)
        {
            right = mid-1;
        }
    }
    return index;
}

void selection_sort(vector<int>& array)
{
    int min = 0;
    int n = array.size();
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(array[j] < array[min])
                min = j;
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}

void insertion_sort(vector<int>& array)
{
    int n = array.size();
    for(int i=0; i<n; i++)
    {
        int j = i;
        while(j>0 && array[j-1]>array[j])
        {
            int temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;

            j--;
        }
    }

}

void bubble_sort(vector<int>& array)
{
    int n = array.size();
    for(int i=n-1; i>=0;i--)
    {
        for(int j=0; j<=i-1; j++){
            if(array[j] > array[j+1])
            {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    insertion_sort(arr);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    vector<int> revArr(n);
    
    for(int i=0; i<n; i++)
    {
        revArr[i] = arr[n-i-1];
    }
    
    for(int i = 0; i < n; i++)
        cout << revArr[i] << " ";
    cout << endl;

    return 0;
}