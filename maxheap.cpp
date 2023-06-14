#include<bits/stdc++.h>
using namespace std;
void heapifyup(vector<int> &v,int k){
    if(k==0)
    return ;
    int j=(k-1)/2;
    if(v[k]>v[j]){
        swap(v[k],v[j]);
        heapifyup(v,j);
    }
}

void heapifydown(vector<int>&v,int k,int n){
    if(k>=n)
    return ;
    int largest=k;
    int l=2*k+1,r=2*k+2;
    if(l<n && v[l] > v[largest])
    largest=l;
    if(r<n && v[r] > v[largest])
    largest=r;
    if(largest!=k){
        swap(v[largest],v[k]);
        heapifydown(v,largest,n);
    }   
}

int main(){
    vector<int> v={4,1,33,7,92,17,25,6};
    int n=v.size();
    vector maxheap(n);
    for(int i=0;i<n;i++){
        maxheap[i]=v[i];
        heapifyup(v,k);
    }
    int k=3;
    vector<int> first_k_max_elements;
    while(k--){
        first_k_max_elements.push_back(v[0]);
        v[0]=v[n-1];
        n--;
        heapifydown(v,0,n);
    }
    for(auto i : first_k_max_elements)
    cout<<i<<" ";
}