#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;

int n,T[N];

void build(int a[]){

	for(int i=0;i<n;i++)
		T[i+n]=a[i];

	for(int i=n-1;i>0;i--)
		T[i]=min(T[i<<1],T[i<<1|1]);	
}

void modify(int p,int val){

	p+=n;
	T[p]=val;

	for(int i=p;i>0;i>>=1)
		T[i>>1]=min(T[i],T[i^1]);
}

int RMQ(int l,int r ){
    
    l--,r--; // for 1 based indexing
    
	int minm=INT_MAX;

	l+=n,r+=n;

	while(l<=r){

		if(l&1)
			minm=min(minm,T[l++]);
		
		if(!(r&1))
			minm=min(minm,T[r--]);

		l>>=1;
		r>>=1;
	}

	return minm;
}
int main(){

	cin>>n;

    int a[n];
    
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	build(a);
}