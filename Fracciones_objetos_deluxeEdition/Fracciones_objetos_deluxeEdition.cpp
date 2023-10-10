//LOPEZ LOPEZ BRANDON ADAIR
//22100190

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;
    //solo considero los inputs, en este caso el usuario solo puede introducir numerador y denominador

public: //metodos
    Fraccion(int, int);//constructor
    void suma(Fraccion);
    void resta(Fraccion);
    void multiplicacion(Fraccion);
    void division(Fraccion);
};

Fraccion::Fraccion(int num, int dem) : numerador(num), denominador(dem) {} //constructor

int simplificar(int mcd, int top, int entero) {//Arreglar la simplificacion sobrecargada

    int a{}, b{}, i{};

    int o{};
    //for (o; o < 3; o++) {

    if (entero >= 1) {
        cout << "El resultado es: " << entero << " ";
    }
    if (top == 0) {
        cout << " El resultado es 0";
    }

    if (entero > 0) {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << a << "/" << b << "\n";
    }
    else {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << endl << "El resultado es: " << a << "/" << b << endl;
        //}
    }
    return a, b;
}

int simplificar_neg(int mcd, int top, int entero) {//Arreglar la simplificacion sobrecargada

    int a{}, b{}, i{};

    int o{};
    //for (o; o < 3; o++) {

    if (entero >= 1) {
        cout << "El resultado es: -" << entero << " ";
    }
    if (top == 0) {
        cout << " El resultado es 0";
    }

    if (entero > 0) {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << a << "/" << b << "\n";
    }
    else {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << endl << "El resultado es: " << a << "/" << b << endl;
        //}
    }
    return a, b;
}

void Fraccion::suma(Fraccion fraccion2) {

    int mcd = denominador * fraccion2.denominador; // el mcd sale de la multiplicacion de ambos denominadores
    int p1 = numerador * fraccion2.denominador; // multiplicas cruzado numerador de la primera fraccion por el denominador de la segunda
    int p2 = fraccion2.numerador * denominador; //Igual aqui el numerador de la segunda fraccion por el denominador de la primera

    int top = p1 + p2; //los resultados de las multiplicaciones cruzadas se suma
    int entero = top / mcd; // sacamos el entero de esta fraccion y se pasa como parametro para la simplificacion
    simplificar(mcd, top, entero);

}

void Fraccion::resta(Fraccion fraccion2) {

    int mcd = denominador * fraccion2.denominador; // el mcd sale de la multiplicacion de ambos denominadores
    int p1 = numerador * fraccion2.denominador; // multiplicas cruzado numerador de la primera fraccion por el denominador de la segunda
    int p2 = fraccion2.numerador * denominador; //Igual aqui el numerador de la segunda fraccion por el denominador de la primera


    int top = p1 - p2; //los resultados de las multiplicaciones cruzadas se resta

    if (top < 0) { // si hay numeros negativos es un caso especial
        top = top * -1;
        int entero = top / mcd; // sacamos el entero de esta fraccion y se pasa como parametro para la simplificacion
        simplificar_neg(mcd, top, entero);
    }
    else {
        int entero = top / mcd; // sacamos el entero de esta fraccion y se pasa como parametro para la simplificacion
        simplificar(mcd, top, entero);
    }

}

void Fraccion::multiplicacion(Fraccion fraccion2) {

    int p1{}, p2{}; // se inicializan en 0 pq en estas operaciones se multiplica directo

    int top = numerador * fraccion2.numerador; // directo numerador por el otro numerador
    int mcd = fraccion2.denominador * denominador; // y el denominador por el otro
    int entero = top / mcd; //sacamos entero y para la funcion

    simplificar(mcd, top, entero);

}

void Fraccion::division(Fraccion fraccion2) {

    int p1{}, p2{}; // se inicializan en 0 pq en estas operaciones se multiplica directo

    int top = numerador * fraccion2.denominador;  // numerador por denominador de la segunda te da el numerador del resultado
    int mcd = denominador * fraccion2.numerador; // y el denominador por el numerador de la segunda da el denominador del resultado
    int entero = top / mcd; //enterito y como parametro

    simplificar(mcd, top, entero);

}

bool validarInput(string fraccion, int& numerador, int& denominador) {
    int posicionSlash = fraccion.find('/'); //esta funcion en que posicion del string se encuentra un /
    if (posicionSlash == 0 || posicionSlash == fraccion.length() - 1) { // el / no puede estar en la posicion 0, ni puede estar al final
        cout << "Introduce una fraccion correcta" << endl;
        return false;
    }

    numerador = stoi(fraccion.substr(0, posicionSlash)); //separa el string en formator fraccion, aqui obtiene el numerador (desde la posicion 0 hasta el /)
    denominador = stoi(fraccion.substr(posicionSlash + 1)); //y aqui separa desde la posicion del slash lo que haya despues
    if (denominador == 0) {
        cout << "Math Error" << endl; // si en cualquier momento el denominador es 0 dale cuello
        return false;
    }
    return true;
}

int main() {

    cout << "FRACCIONES CON OBJETOS" << endl << endl;
    cout << "Seleccione una operacion" << endl;
    cout << "1. Suma" << endl << "2. Resta" << endl << "3. Multiplicacion" << endl << "4. Division" << endl;

    int tipoOperacion;
    cin >> tipoOperacion; //input para los cases

    int numerador1{}, denominador1{}, numerador2{}, denominador2{};
    string primeraFraccion;

    switch (tipoOperacion) {
    case 1:
        cout << endl << "Suma" << endl;
        cout << "Ingrese la primera fraccion (por ejemplo: 7/2): ";
        cin >> primeraFraccion; //input de la fraccion
        if (validarInput(primeraFraccion, numerador1, denominador1)) { //pero solo si validarInput devuelve un true:
            cout << "Ingrese la segunda fraccion: ";
            string segundaFraccion;
            cin >> segundaFraccion;
            if (validarInput(segundaFraccion, numerador2, denominador2)) {//valida otra vez con la segunda fraccion
                Fraccion fraccion1(numerador1, denominador1);//creamos un objeto fraccion1
                Fraccion fraccion2(numerador2, denominador2);//y fraccion2 con sus atributos (num y dem)
                fraccion1.suma(fraccion2); // y nos vamos a hacer la operacion, lo mismo con todos los cases en las diferentes operaciones
            }
        }
        break;

    case 2:
        cout << endl << "Resta" << endl;

        cout << "Ingrese la primera fraccion (por ejemplo: 7/2): ";
        cin >> primeraFraccion;
        if (validarInput(primeraFraccion, numerador1, denominador1)) {
            cout << "Ingrese la segunda fraccion: ";
            string segundaFraccion;
            cin >> segundaFraccion;
            if (validarInput(segundaFraccion, numerador2, denominador2)) {
                Fraccion fraccion1(numerador1, denominador1);
                Fraccion fraccion2(numerador2, denominador2);
                fraccion1.resta(fraccion2);
            }
        }
        break;

    case 3:
        cout << endl << "Multiplicacion" << endl;

        cout << "Ingrese la primera fraccion (por ejemplo: 7/2): ";
        cin >> primeraFraccion;
        if (validarInput(primeraFraccion, numerador1, denominador1)) {
            cout << "Ingrese la segunda fraccion: ";
            string segundaFraccion;
            cin >> segundaFraccion;
            if (validarInput(segundaFraccion, numerador2, denominador2)) {
                Fraccion fraccion1(numerador1, denominador1);
                Fraccion fraccion2(numerador2, denominador2);
                fraccion1.multiplicacion(fraccion2);
            }
        }
        break;

    case 4:
        cout << endl << "Division" << endl;

        cout << "Ingrese la primera fraccion (por ejemplo: 7/2): ";
        cin >> primeraFraccion;
        if (validarInput(primeraFraccion, numerador1, denominador1)) {
            cout << "Ingrese la segunda fraccion: ";
            string segundaFraccion;
            cin >> segundaFraccion;
            if (validarInput(segundaFraccion, numerador2, denominador2)) {
                Fraccion fraccion1(numerador1, denominador1);
                Fraccion fraccion2(numerador2, denominador2);
                fraccion1.division(fraccion2);
            }
        }
        break;

    default:
        cout << "Seleccione una operacion valida" << endl;
        break;
    }
}