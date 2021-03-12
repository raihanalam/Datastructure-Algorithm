#include<iostream>
using namespace std;
int right(int i){
    return 2*i+1;
}
int left(int i){
    return 2*i;
}
int parent(int i){
    return i/2;
}
void max_heapify(int heap[],int heap_size,int i){
    int l,r,largest=0,t=0;
    l=left(i);
    r=right(i);
    if(l<=heap_size && heap[l]>heap[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r <= heap_size && heap[r]>heap[largest]){
        largest=r;
    }
    if(largest!=i){
        t=heap[i];
        heap[i]=heap[largest];
        heap[largest]=t;

        max_heapify(heap,heap_size,largest);
    }

}
void heap_sort(int heap[],int heap_size){
    int i,temp,h_size=heap_size;
    for(i=heap_size;i>1;i--){
        temp=heap[1];
        heap[1]=heap[heap_size];
        heap[heap_size]=temp;

        heap_size--;
        max_heapify(heap,heap_size,1);
    }
    for(i=1;i<=h_size;i++){
        cout<<heap[i]<<endl;
    }
}
int main(){
    int heap[]={0,19,7,15,3,5,11,10,4,2};
    int heap_size=9;
    int i;
    ///Building a Max Heap
    for(i=heap_size/2;i>=1;i--){
        max_heapify(heap,heap_size,i);
    }
    ///Heap Sort
    heap_sort(heap,heap_size);
}
