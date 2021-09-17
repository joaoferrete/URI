#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	long long int x, i, z, y=0;
	cin>>x>>z;
	if (x>z){
		for(i=z+1; i<x; i++){
			if(i%2==0){

			}else{
				y= y+i;
			}
		}
	}else{
		for(i=x+1; i<z; i++){
			if(i%2==0){

			}else{
				y= y+i;
			}
		}
	}
	cout<<y<<"\n";

	return 0;
}