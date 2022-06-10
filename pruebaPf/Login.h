#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
class Login
{
	private:
	public:
		void login();
};


void Login::login() {
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
        cout << "\t\t\tLOGIN DE USUARIO                  # intentos:"<< INTENTOS-contador<< endl;
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
            cout << "\n\n\tEl usuario y/o password son incorrectos " << endl;
            //cin.get();
            system("pause");
            contador++;
        }
        
        if(contador==3)
   		 {
	    	cout<<"Numero de intentos maximo, el programa se cerrara"<<endl;
	    	exit(0);
		}
    } while (ingreso == false && contador < INTENTOS); 
    
    
    system("cls");
        
}