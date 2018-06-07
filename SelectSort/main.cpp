#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

template <typename T>
void selectionSort(T a[],int n){
    for(int i = 0;i < n;i++){
        int minIndex = i;
        for(int j = i + 1;j < n;j++){
            if(a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[minIndex],a[i]);
    }
}

int main() {
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a,10);

    double arr[] = {1.1,1.2,1.3,1.4};

    string aa[4] = {"abc","qqw","bwer","asdf"};
    selectionSort(aa,4);

    Student d[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectionSort(d,4);


    for(int i = 0; i < 4 ;i++){
        cout<<d[i];
    }
    cout<<endl;
    return 0;
 }