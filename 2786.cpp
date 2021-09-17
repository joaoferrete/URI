#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	long long l, c, t1, t2;
	cin>>l>>c;
	t2=((c-1)*2)+((l-1)*2);
	t1=l*c+((c-1)*(l-1));



	cout<<t1<<"\n"<<t2<<"\n";


	return 0;
}