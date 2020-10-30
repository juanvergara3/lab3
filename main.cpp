#include <cstdlib>
#include <ctime>
#include "atm.h"

using namespace std;

int main()
{
    bool running = true, sub_menu = true, validation;
    string user, password;
    short main_menu, user_menu, method, old_method;
    int retiro, seed, old_seed;

    old_method = short(stoi(read_file("M.dat"))); //lee el metodo y la semilla que se uso en la anterior ejecucion
    old_seed  = stoi((read_file("S.dat")));

    srand((unsigned) time(0)); //genera un nuevo metodo y se semilla (entre 1 y 20) aleatorios
    method = rand() % 2 + 1;
    seed = rand() % 20 + 1;

    write_file("M.dat", to_string(method)); //guarda estos nuevos metodos y semillas para usarse en la siguiente ejecucion
    write_file("S.dat", to_string(seed));

    user = decrypt("users", old_method, old_seed); //desencripta con la semilla y metodo viejos
    encrypt("users", user, method, seed); //encripta con la semilla y metodo nuevos
    user.clear();

    password  = decrypt("sudo", old_method, old_seed); //desencripta con la semilla y metodo viejos
    encrypt("sudo", password, method, seed); //encripta con la semilla y metodo nuevos
    password.clear();

    while(running){ //ciclo principal

        cout<<"\nIngrese 1 para iniciar sesion, 2 para acceder al modo administrador, o -1 para salir: "; cin>>main_menu;

        while(cin.fail()) { //validacion de entrada
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Opcion no valida"<<endl;
            cout<<"\nIngrese 1 para iniciar sesion, 2 para acceder al modo administrador, o -1 para salir: "; cin>>main_menu;
        }

        switch (main_menu) {

        case 1:{ //usuario

            cout<<"- - - - - - - - - - - -"<<endl;

            while(true){
                cout<<"Ingrese su cedula (-1 para salir)  y clave: "<<endl;

                cout<<"Cedula: "; cin>>user;

                if(user == "-1") break;

                cout<<"Contrasena: "; cin>>password;

                validation = validate_user(user, password, method, seed);

                password.clear();

                if(validation){

                    cout<<"Bienvenido. ";

                    withdraw(user, 1000, method, seed);

                    sub_menu = true;

                    while(sub_menu){ // menu de usuario

                        cout<<"Ingrese 1 para consultar saldo, 2 para retirar o -1 para salir: "; cin>>user_menu;

                        while(cin.fail()) { //validacion de entrada
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "Opcion no valida"<<endl;
                            cout<<"Ingrese 1 para consultar saldo, 2 para retirar o -1 para salir: "; cin>>user_menu;
                        }

                        switch(user_menu){

                        case 1:{ //consultar saldo

                             check_balance(user, method, seed);

                            break;
                        }
                        case 2:{ //retirar

                            while(true){
                                cout<<"Ingrese la cantidad a retirar (0 para cancelar): "; cin>>retiro;

                                while(cin.fail()) { //validacion de entrada
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout << "Cantidad no valida"<<endl;
                                    cout<<"Ingrese la cantidad a retirar: "; cin>>retiro;
                                }

                                if(retiro>0){

                                    withdraw(user, retiro, method, seed);

                                    cout<<"Retiro exitoso por valor de: "<<retiro<<endl;
                                    cout<<"Saldo restante: ";
                                    check_balance(user, method, seed);
                                    retiro = 0;
                                    break;
                                }

                                else if(retiro == 0) break;

                                else cout<<"Cantidad no valida"<<endl;
                            }
                            break;
                        }

                        case -1:{ //salir
                            sub_menu = false;
                            cout<<"- - - - - - - - - - - -"<<endl;
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

        case 2:{ //administrador

            cout<<"- - - - - - - - - - - -"<<endl;

            while(true){

                cout<<"Ingrese la contrasena de administrador (-1 para salir):"<<endl;

                cout<<"Contrasena: "; cin>>password;

                if(password == "-1") break;

                validation = validate_user("admin", password,method, seed);

                password.clear();

                if(validation){

                    cout<<"- - - - - - - - - - - -"<<endl;

                    cout<<"Bienvenido Admin. ";

                    sub_menu = true;

                    while(sub_menu){

                        cout<<"Ingrese 1 para agregar un usuario, 2 para ver todos los usuarios, 3 para cambiar la contrasena o -1 para salir: "; cin>>user_menu;

                        while(cin.fail()) { //validacion de entrada
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "Opcion no valida"<<endl;
                            cout<<"Ingrese 1 para agregar un usuario, 2 para ver todos los usuarios, 3 para cambiar la contrasena o -1 para salir: "; cin>>user_menu;
                        }

                        switch(user_menu){

                        case 1:{ // añadir usuario

                            while(true){

                                cout<<"- - - - - - - - - - - -"<<endl;

                                cout<<"Ingrese los datos del nuevo usuario:"<<endl;

                                while(true){ //verifica que el usuario no contenga comas y que sea un numero
                                    cout<<"Cedula: "; cin>>user;

                                    size_t *found = new size_t;
                                    *found = user.find(',');

                                    if (*found != std::string::npos)
                                        cout << "La cedula no puede contener ','"<<endl;
                                    else{
                                        if(is_number(user) == true){
                                            delete found;
                                            break;
                                        }
                                        else cout<<"La cedula debe ser un numero"<<endl;
                                    }
                                }

                                while(true){ //verifica que la clave no contenga comas y que no sea solo numeros
                                    cout<<"Clave: "; cin>>password;

                                    size_t *found = new size_t;
                                    *found = password.find(',');

                                    if (*found != std::string::npos)
                                        cout << "La clave no puede contener ','"<<endl;
                                    else{
                                        if(is_number(password) == true)
                                            cout<<"La clave debe tener numeros y letras"<<endl;
                                        else {
                                            delete found;
                                            break;
                                        }
                                    }
                                }

                                cout<<"Saldo: "; cin>>retiro;
                                while(cin.fail()) { //validacion de entrada
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout << "saldo invalido"<<endl;
                                    cout<<"Saldo: "; cin>>retiro;
                                }

                                cout<<"Ingrese 0 para cancelar o 1 para confirmar: "; cin>>validation;
                                while(cin.fail()) { //validacion de entrada
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout << "Opcion no valida"<<endl;
                                    cout<<"Ingrese 0 para cancelar o 1 para confirmar: "; cin>>validation;
                                }

                                if(validation){

                                   register_user(user, password, retiro, method, seed);

                                   cout<<"- - - - - - - - - - - -"<<endl;

                                   break;
                                }
                            }

                            password.clear();
                            retiro = 0;
                            user.clear();

                            break;
                        } // final del registro de usuario

                        case 2:{ // ver todos los usuarios
                            display_users(method, seed);
                            break;
                        }

                        case 3:{

                                cout<<"Nueva contrasena: "; cin>>password;
                                cout<<"Confirmar contrasena: ";cin>>user;

                                if(password == user) new_admin_password(password, method, seed);
                                else cout<<"La contrasenas no coinciden"<<endl;

                            break;
                        }

                        case -1:{
                            sub_menu = false;
                            cout<<"- - - - - - - - - - - -"<<endl;
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
