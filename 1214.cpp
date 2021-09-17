#include<iostream>
#include <cmath>
using namespace std;

int main (){
    long long c, n, i, j, k=0, a[1000], s=0;
    double m;
    cin>>c;
    for(i=0; i<c; i++){
        k=0;
        s=0;
        cin>>n;
        for(j=0;j<n;j++){
            cin>>a[j];
            s+=a[j];
        }
        m=(double)s/n;
        for(j=0;j<n;j++){
            if(a[j]>m){
                k++;
            }
        }
        printf("%.3lf%%\n",((double)k/n)*100);
    }


    return 0;
}