// SEGMENT TREE- RANGE SUM QUERY WITHOUT RECURSION

#include<bits.stdc++.h>
using namespace std;

const int N=1e5+1;

int n,T[N];

void build(int a[]){

	for(int i=0;i<n;i++)
		T[i+n]=a[i];

	for(int i=n-1;i>0;i--)
		T[i]=T[i<<1]+T[i<<1|1];	
}

void modify(int p,int val){

	p+=n;
	T[p]=val;

	for(int i=p;i>0;i>>=1)
		T[i>>1]=T[i]+T[i^1];
}

int Sum(int l,int r ){

	int sum=0;

	l+=n,r+=n;

	while(l<=r){

		if(l&1)
			ans+=T[l++];
		
		if(!(r&1))
			ans+=T[r--];

		l>>=1;
		r>>=1;
	}

	return sum;
}
int main(){

	cin>>n;

	for(int i=0;i<n;i++)
	cin>>a[i];
	
	build(a);	
	modify(1,10);     // 0 indexed
	cout<<Sum(0,n-1); // inclusive 
}
