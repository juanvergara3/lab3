#include <iostream>
#include "encription.h"
#include "atm.h"
using namespace std;

int main()
{
    bool running = true, sub_menu = true, validation;
    string user, password, amount;
    short main_menu, user_menu;
    int retiro;

    while(running){

        cout<<"\nIngrese 1 para iniciar sesion, 2 para acceder al modo administrador, o -1 para salir: "; cin>>main_menu;

        while(cin.fail()) { //validacion de entrada
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Opcion no valida"<<endl;
            cout<<"\nIngrese 1 para iniciar sesion, 2 para acceder al modo administrador, o -1 para salir: "; cin>>main_menu;
        }

        switch (main_menu) {

        case 1:{

            cout<<"- - - - - - - - - - - -"<<endl;

            while(true){
                cout<<"Ingrese su cedula (-1 para salir)  y clave: "<<endl;

                cout<<"Cedula: "; cin>>user;

                if(user == "-1") break;

                cout<<"Contrasena: "; cin>>password;

                validation = validate_user(user, password);

                password.clear();

                if(validation){

                    sub_menu = true;

                    while(sub_menu){

                        cout<<"Bienvenido. Ingrese 1 para consultar saldo, 2 para retirar o -1 para salir: "; cin>>user_menu;

                        while(cin.fail()) { //validacion de entrada
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "Opcion no valida"<<endl;
                            cout<<"Ingrese 1 para consultar saldo, 2 para retirar o -1 para salir: "; cin>>user_menu;
                        }

                        switch(user_menu){

                        case 1:{ //consultar saldo

                            withdraw(user, 1000);

                            check_balance(user);

                            break;
                        }
                        case 2:{ //retirar

                            while(true){
                                cout<<"Ingrese la cantidad a retirar: "; cin>>retiro;

                                while(cin.fail()) { //validacion de entrada
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout << "Cantidad no valida"<<endl;
                                    cout<<"Ingrese la cantidad a retirar: "; cin>>user_menu;
                                }

                                if(retiro>0){

                                    withdraw(user, retiro);

                                    break;
                                }
                                else cout<<"Cantidad no valida"<<endl;
                            }

                            retiro = 0;
                            user.clear();

                            break;
                        }
                        case -1:{
                            sub_menu = false;
                            break;
                        }
                        default:{
                            cout<<"Opcion no valida"<<endl;
                            break;
                        }

                        } // final switch
                    } // final while interno
                } // final if

                else cout<<"cedula o clave incorrectos"<<endl;

            } // final while externo

            cout<<"- - - - - - - - - - - -"<<endl;

            break;
        }

        case 2:{

            cout<<"- - - - - - - - - - - -"<<endl;

            while(true){

                cout<<"Ingrese la contrasena de administrador (-1 para salir):"<<endl;

                cout<<"Contrasena: "; cin>>password;

                if(password == "-1") break;

                validation = validate_user("admin", password);

                password.clear();

                if(validation){

                    sub_menu = true;

                    while(sub_menu){

                        cout<<"Bienvenido Admin. Ingrese 1 para agregar un usuario o -1 para salir: "; cin>>user_menu;

                        while(cin.fail()) { //validacion de entrada
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "Opcion no valida"<<endl;
                            cout<<"Ingrese 1 para agregar un usuario o -1 para salir: "; cin>>user_menu;
                        }

                        switch(user_menu){

                        case 1:{ // añadir usuario

                            while(true){

                                cout<<"Ingrese los datos del nuevo usuario:"<<endl;

                                cout<<"Cedula: "; cin>>user;
                                cout<<"Clave: "; cin>>password;
                                cout<<"Saldo: "; cin>>amount;
                                cout<<"Ingrese 0 para cancelar o 1 para confirmar: "; cin>>validation; // keep an eye on this ******

                                while(cin.fail()) { //validacion de entrada
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout << "Opcion no valida"<<endl;
                                    cout<<"Ingrese 0 para cancelar o 1 para confirmar: "; cin>>validation;
                                }

                                if(validation){
                                   register_user(user, password, amount);
                                   break;
                                }
                            }

                            password.clear();
                            amount.clear();
                            user.clear();

                            break;
                        }
                        case -1:{
                            sub_menu = false;
                            break;
                        }
                        default:{
                            cout<<"Opcion no valida"<<endl;
                            break;
                        }
                        } // final switch

                    } // final while interno

                } // final if

                else cout<<"Contrasena incorrecta"<<endl;

            } //final while externo

            cout<<"- - - - - - - - - - - -"<<endl;

            break;
        }

        case -1:{
            running = false;
            break;
        }

        default:{
            cout<<"Opcion no valida"<<endl;
            break;
        }

        }//final switch principal
    }//final del while principal

    return 0;
}
