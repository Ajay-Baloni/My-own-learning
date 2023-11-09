#include <iostream>
using namespace std;

int getPivot(int arr[], int n, int target)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;

        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{

    int arr[5] = {3, 4, 1, 2, 3};
    int target = 2;

    cout << "target element in index : " << getPivot(arr, 5, target) << endl;
}