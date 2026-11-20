#include <stdio.h>

static int arr[] = {38, 27, 43, 3, 9, 82, 10};
static int n = sizeof(arr) / sizeof(arr[0]);

static void merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

static void mergeSortHelper(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortHelper(left, mid);
        mergeSortHelper(mid + 1, right);

        merge(left, mid, right);
    }
}

static void sort(void)
{
    mergeSortHelper(0, n - 1);
}

int main()
{
    printf("Înainte de sortare: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort();

    printf("După sortare: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}