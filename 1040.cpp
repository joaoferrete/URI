#include <bits/stdc++.h>
using namespace std;

int main(){
    double n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    double media = (n1*2 + n2*3 + n3*4 + n4*1)/10;

    cout << fixed << setprecision(1) << "Media: " << media << endl;
    if(media >= 7){
        cout << "Aluno aprovado." << endl;
    }else if(media < 5){
        cout << "Aluno reprovado." << endl;
    }else{
        cout << "Aluno em exame." << endl;
        double exame;
        cin >> exame;
        cout << fixed << setprecision(1) << "Nota do exame: " << exame << endl;
        double media_final = (media + exame)/2;
        if(media_final >= 5){
            cout << "Aluno aprovado." << endl;
        }else{
            cout << "Aluno reprovado." << endl;
        }
        cout << fixed << setprecision(1) << "Media final: " << media_final << endl;
    }
}