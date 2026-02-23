#include <iostream>
#include <algorithm>
using namespace std;

void print(int a[], int n) {
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void bubble(int a[], int n) {
    int c=1;
    for(int i=0;i<n-1;i++) {
        cout<<"\nPASS "<<i+1<<endl;
        for(int j=0;j<n-i-1;j++) {
            if(a[j]>a[j+1]) {
                swap(a[j],a[j+1]);
                cout<<"Change "<<c++<<" : ";
                print(a,n);
            }
        }
    }
}

void selection(int a[], int n) {
    int c=1;
    for(int i=0;i<n-1;i++) {
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;

        swap(a[i],a[min]);
        cout<<"Step "<<c++<<" : ";
        print(a,n);
    }
}

void insertion(int a[], int n) {
    int c=1;
    for(int i=1;i<n;i++) {
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        cout<<"Step "<<c++<<" : ";
        print(a,n);
    }
}

void merge(int a[], int l, int m, int r, int n) {
    int i=l,j=m+1,k=0;
    int t[100];

    while(i<=m && j<=r)
        t[k++]=(a[i]<a[j])?a[i++]:a[j++];

    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=t[k];

    print(a,n);
}

void mergeSort(int a[], int l, int r, int n) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(a,l,m,n);
        mergeSort(a,m+1,r,n);
        merge(a,l,m,r,n);
    }
}

int part(int a[], int low, int high) {
    int p=a[high],i=low-1;
    for(int j=low;j<high;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[high]);
    return i+1;
}


int main() {
    int n,ch;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[100];
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) cin>>a[i];

    do {
        cout<<"\nMENU\n";
        cout<<"1 Bubble Sort\n";
        cout<<"2 Selection Sort\n";
        cout<<"3 Insertion Sort\n";
        cout<<"4 Merge Sort\n";
        cout<<"0 Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch) {
            case 1: bubble(a,n); break;
            case 2: selection(a,n); break;
            case 3: insertion(a,n); break;
            case 4: mergeSort(a,0,n-1,n); break;
        }

        if(ch!=0) {
            cout<<"\nFinal Sorted Array: ";
            print(a,n);
        }

    } while(ch!=0);

    return 0;
}
