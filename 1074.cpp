#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	long long int x, i, z;
	cin>>x;
	for(i=0; i<x; i++){
		cin>>z;
		if(z==0){
			cout<<"NULL\n";
		}
		if(z%2==0){
			if (z>0){
				cout<<"EVEN POSITIVE\n";
			}else if (z<0){
				cout<<"EVEN NEGATIVE\n";
			}
		}else{
			if (z>0){
				cout<<"ODD POSITIVE\n";
			}else if (z<0){
				cout<<"ODD NEGATIVE\n";
			}
		}
	}
	return 0;

}