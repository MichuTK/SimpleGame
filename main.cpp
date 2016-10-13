#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int totalPoints = 0;

void lvl2(){
    int answer, goodAnswer = 50;
    int pkt = 5;
    system("CLS");
    cout << "POZIOM 2" << endl;
    cout << "Ilosc punktow: " << totalPoints << endl;
    cout << "Ilosc punktow ktore dostaniesz za rozwiazanie: " << pkt << endl;
    cout << "__________________________________________________" << endl;

    cout << "Polecenie:" << endl;
    cout << "Rozwiaz rownanie 7-7/7+7*7-7" << endl << endl;
    cout << "Odpowiedz: ";
    cin >> answer;
    cin.sync();
    cin.clear();
    while(answer != goodAnswer){
        cout << "Bledna odpowiedz! Sproboj ponownie" << endl;
        cout << "Odpowiedz: ";
        cin >> answer;
    }
    totalPoints += pkt;
    cout << "Dobra odpowiedz :D" << endl;
    cout << "Aby przejsc do kolejnego poziumu wcisnij ENTER" << endl;
    getche();
}

void lvl1(){
    int answer, goodAnswer = 6;
    int pkt = 5;
    system("CLS");
    cout << "POZIOM 1" << endl;
    cout << "Ilosc punktow: " << totalPoints << endl;
    cout << "Ilosc punktow ktore dostaniesz za rozwiazanie: " << pkt << endl;
    cout << "__________________________________________________" << endl;

    cout << "Polecenie:" << endl;
    cout << "Rozwiaz rownanie 2+2*2" << endl << endl;
    cout << "Odpowiedz: ";
    cin >> answer;
    cin.sync();
    cin.clear();
    while(answer != goodAnswer){
        cout << "Bledna odpowiedz! Sproboj ponownie" << endl;
        cout << "Odpowiedz: ";
        cin >> answer;
    }
    totalPoints += pkt;
    cout << "Dobra odpowiedz :D" << endl;
    cout << "Aby przejsc do kolejnego poziumu wcisnij ENTER" << endl;
    getche();
    lvl2();
}

void zasady(){
    system("CLS");
    cout << "ZASADY GRY" << endl;
    cout << "Gra polega na rozwiazywaniu zagadek \n za dobrze rozwiazana zagadke otrzymujesz okreslona liczbe punktow, \n je¿eli twoja odpowiedz jest bledna za poprawna odpowiedz otrzymasz 1 pkt mniej." << endl;
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
    cout << "[3] Zasady gry" << endl;
    cout << "Wybor: ";
    cin >> choose;

    switch(choose){
        case 1:
            lvl1();
                break;
        case 2:
            load();
                break;
        case 3:
            zasady();
                break;
    }
    return 0;
}
