#include <iostream>
using namespace std;
void InsertSort(int a[], int len){
    if(a==nullptr || len < 0)
        return;
    int i,j,temp;
    for(i = 1;i<len;i++){
        temp = a[i];
        for (int k = i-1; k >= 0 ; --k) {
            if(a[k]>temp)
                a[k+1] = a[k];
            else
                break;

        }
        a[k+1] = temp;
    }
}

void QuickSort(int a[], int low, int high){
    if(low >= high)
        return;
    int i= low, j = high;
    int pivot = a[low];
    while (i<j){
        while (i<j && pivot < a[j])
            j--;
        if(i<j)
            a[i++]=a[j];
        while (i<j && pivot > a[i])
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i] = pivot;
    QuickSort(a, low,i-1);
    QuickSort(a,i+1, high);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}