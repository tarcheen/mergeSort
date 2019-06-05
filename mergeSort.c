// Hamed Mirlohi
// implementation of merge sort in C
// n(log(n)) iteration hit - divide and conquer



#include <stdio.h>
#include <stdlib.h>



void Merge(int* a, int* L, int* R, int length)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int mL;
    int mR;
    
    mL = length/2;
    mR = length - mL;
    
    while (i < mL && j < mR)
    {
        if(L[i] < R[j])     // if left first element is smaller than right first element
        {
            a[k] = L[i];       // make first element of parent to first element of left
            ++i;               // element copied now point to the next element of left array
        }
        else
        {
            a[k] = R[j];       // right first element is smaller, now make first element of parent to first element of right array
            ++j;                // element copied now point to the next element of right array
        }
        ++k;                   // at this point the first element of parent is here, lets go to the next element
    }
    
    while (i <mL)              // we are here because either mL ran out of space or mR, in both while loops we are copying the remainder copies to the parent
    {
        a[k] = L[i];
        ++i;
        ++k;
    }
    
    while (j < mR)
    {
        a[k] = R[j];
        ++k;
        ++j;
    }
    
}



void MergeSort(int* a, int length)
{
    int mid=0;
    mid = length / 2;       // middle of the array
    int i;
    
    int* L;                 // left array
    int* R;                 // right array
    
    if(length < 2)          // if only one element remaining, exit the function
        return;
    
    else
    {
        L = (int*)malloc(sizeof(int) * mid);                // allocated memory to left and right array
        R = (int*)malloc(sizeof(int) * (length - mid));
        
        for (i = 0; i < mid; i++)                           // fill left and right array using the parrent array
        {
            L[i] = a[i];
        }
        
        for (i = mid; i < length; i++)
        {
            R[i-mid] = a[i];
        }
        
        // recursive calls
        MergeSort(L,mid);               // merge left array
        MergeSort(R, length-mid);       // merge right array
        Merge(a, L, R, length);         // merge sorted left and right array to the parent array
        
        
    }
    
}


int main()
{
    int a[7] = {99,36,55,2,1,27,3};        // My array to be sorted
    int i;
    
    
    MergeSort(a,7);                         // function to sort array passing on the array and the size of the array
    
    for (i = 0; i < 7; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n\n\n");
    return 0;
}
