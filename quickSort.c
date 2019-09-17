int partition (unsigned char arr[][SHA256_LEN], int low, int high)
{
    unsigned char *pivot = arr[low];    // pivot 
    int i = low + 1, j;  // Index of smaller element 
    unsigned char temp[SHA256_LEN];

    for (j = low + 1; j <= high; j++)
    {
        //If current element is smaller than the pivot 
        if ((memcmp(arr[j], pivot, SHA256_LEN) < 0))
        {
            memcpy(temp, arr[i], SHA256_LEN);
            memcpy(arr[i], arr[j], SHA256_LEN);
            memcpy(arr[j], temp, SHA256_LEN);
            i++;
        }
    }
    memcpy(temp, arr[i-1], SHA256_LEN);
    memcpy(arr[i-1], arr[low], SHA256_LEN);
    memcpy(arr[low], temp, SHA256_LEN);
    return i-1;
}

void quickSort(unsigned char arr[][SHA256_LEN], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
            at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

