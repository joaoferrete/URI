#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	long long int x, i, z[61], y;
	cin>>x;
	z[0]=0;
	z[1]=1;
	for(i=2;i<61;i++){
		z[i]=z[i-1]+z[i-2];
	}
	while(x--){
		cin>>y;
		printf("Fib(%lld) = %lld\n", y, z[y]);
	}

	return 0;
}