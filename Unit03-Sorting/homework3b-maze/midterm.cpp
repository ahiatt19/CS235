

bool binarySearch(int *L, int min, int max, int n) {
    int middle = (max + min)/2;

    if (max <= min)
        return false;

    if  (L[middle] == n ) {
        return true;
    }

    if (n > L[middle]) {
        return binarySearch(L, middle+1, max, n);
    }
    else {
        return binarySearch(L, min, middle-1, n);
    }
}
