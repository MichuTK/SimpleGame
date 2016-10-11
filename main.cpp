#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void lvl1(){
    int answer;
    system("CLS");
    cout << "POZIOM 1" << endl << endl;
    cout << "Polecenie:" << endl;
    cout << "Rozwiaz rownanie 2+2*2" << endl;
    cout << "Odpowiedz: ";
    cin >> answer;
    cin.sync();
    cin.clear();
    while(answer != 6){
        cout << "Bledna odpowiedz! Sproboj ponownie" << endl;
        cout << "Odpowiedz: ";
        cin >> answer;
    }
    cout << "Dobra odpowiedz :D" << endl;
}

void load(){
    string line;
    int lvl, nLine = 1;
    fstream save;
    save.open("save.txt", ios::in);
    while(getline(save, line)){
        switch(nLine){
            case 1: lvl = atoi(line.c_str()); break;
            default: cout << "Error[600]" << endl; exit(600); break;
        }
    }
    switch(lvl){
        case 1: lvl1(); break;
        default: cout << "Error[700]" << endl; exit(700); break;
    }
    save.close();
}

int main()
{
    int choose;

    cout << "[1] Zacznij od poczatku" << endl;
    cout << "[2] Wczytaj ostatni zapis" << endl;
    cout << "Wybor: ";
    cin >> choose;

    switch(choose){
        case 1:
            lvl1();
                break;
        case 2:
            load();
                break;
    }
    return 0;
}
