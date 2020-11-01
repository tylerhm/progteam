#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int ls = arr[r];
    int i = l;
    int j = l;
    while (j < r) {
        if (arr[j] < ls) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int randomPart(int arr[], int l, int r)
{
    int n = r - l + 1;
    int p = rand() % n;
    swap(&arr[l + p], &arr[r]);
    return partition(arr, l, r);
}

void medianUtil(int arr[], int l, int r, int k, int& a, int& b)
{
    if (l <= r) {
        int partIndex = randomPart(arr, l, r);

        if (partIndex == k) {
            b = arr[partIndex];
            if (a != -1)
                return;
        }
        else if (partIndex == k - 1) {
            a = arr[partIndex];
            if (b != -1)
                return;
        }

        if (partIndex >= k)
            return medianUtil(arr, l, partIndex - 1, k, a, b);
        else
            return medianUtil(arr, partIndex + 1, r, k, a, b);
    }
    return;
}

int median(int arr[], int n)
{
    int ans;
    int a = -1;
    int b = -1;

    medianUtil(arr, 0, n - 1, n / 2, a, b);
    return (a + b) / 2;
}

int erries(int& n, vector<int>& arr)
{
    int ans = n;
    int start;
    int curMed;
    for (int i = 0; i < n - 1; i++)
    {
        start = arr[i];
        for (int j = i+2; j < n; j+=2)
        {
            int sub[j-i+1];
            for (int k = i; k <= j; k++) sub[k-i] = arr[k];
            for (int k = 0; k < j-i+1; k++) cout << sub[k] << " ";
            cout << "\n";
            cout << "Median = " << median(sub, j-i+1) << "\n";
            if (start == median(sub, j-i+1));
                ans++;
        }
    }
    return ans;
}


int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    //cout << erries(n, arr) << "\n";
    cout << median(arr, n);
    return 0;
}
