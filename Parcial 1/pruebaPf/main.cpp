/*#include <iostream>
#include <string>
#include <ctime>
#include "Menu.h"
#include "Login.h"

int main(int argc, char** argv)
{
//	Login login;
 	Menu mn;
 //	login.login();
 	mn.menuPrincipal(); 
 	

    
    return 0;

}*/

#define _CRT_NONSTDC_NO_DEPRECATE
#include <thread>
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include<dos.h>
#include <time.h>
//#include <windows>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <future>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
    nodo* atras;
}*primero, * ultimo;

void insertarCelular();
void imprimirCeluar();
void eliminarCelular();
void login();
void menu();
void generarArchivo();
void gotoxy(int, int);
int cursor(const char titulo[], const char* opciones[], int n);
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

void clrscr(void);
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;


void login() {
    vector <string> usuarios;
    vector <string> claves;
    // Se añaden usuarios al vector
    usuarios.push_back("admin");

    // Se añaden claves al vector
    claves.push_back("admin");

    string usuario, password;
    int contador = 0;
    bool ingreso = false;
    do {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);
        char caracter;
        cout << "\tPassword: ";
        caracter = getch();
        password = "";

        while (caracter != ENTER) {
            if (caracter != BACKSPACE) {
                password.push_back(caracter);
                cout << "*";
            }
            else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }

            }
            caracter = getch();
        }
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i] == usuario && claves[i] == password) {
                ingreso = true;
                break;
            }
        }

        if (!ingreso) {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }
    } while (ingreso == false && contador < INTENTOS);
    if (ingreso == false) {
        system("cls");
        cout << "\n\t------SE HAN AGOTADO LOS INTENTOS, PORFAVOR COMUNIQUESE CON EL ADMINISTRADOR------\n\n\t*POR TEMAS DE SEGURIDAD HEMOS HACKEADO SU ORDENADOR*\n\n\n\n" << endl;
    }
    else {
        system("cls");
        menu();
    }
}


// Marquesina
void marquesina() {

    int a, b, c, n = 0, letra = 39, pos = 1, cont = 39, aux, cont1 = 39, auxg;
    char t[50] = " ** PROYECTO ESTRUCTURA DE DATOS **** ", auxt[39] = " ";

    do {
        for (a = 0; a < 42; a++) {
            aux = pos;
            for (b = 39; b > cont; b--) {
                gotoxy(pos, 1);
                cout << t[b];
                pos--;
            }
            aux++;
            pos = aux;
            cont--;
            Sleep(75);
            if (a == 40) {
                break;
            }
        }
        for (a = 3; a < 70; a++) {
            gotoxy(a - 1, 1);
            cout << " ";
            gotoxy(a, 1);
            cout << t;
            Sleep(75);
        }

        pos = 70;
        auxg = 69;
        for (a = 0; a < 41; a++) {
            gotoxy(auxg, 1);
            cout << " ";
            aux = pos;
            for (b = 0; b <= cont1; b++) {
                gotoxy(pos, 1);
                cout << t[b];
                pos++;
            }
            cont1--;
            aux++;
            pos = aux;
            auxg++;
            Sleep(75);
        }
        cont1 = 39;
        letra = 39;
        pos = 1;
        cont = 39;
        c = 0;
    } while (c = 1);
}

void callback(const std::string& data)
{
    std::cout << "Callback called because: " << data << '\n';
}
void task(int time)
{

    marquesina();
    callback("async task done");
}


int main()
{
    //std::thread bt(task, 1);
    auto r = std::async(std::launch::async, marquesina);
    login();

    //bt.join();
   // std::this_thread::sleep_for(std::chrono::seconds(5));
    // std::cout << "main done\n";
    // bt.join();
}



void menu() {
   
}



// Funcion gotoxy
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
}

