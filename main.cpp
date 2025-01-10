#include <iostream>
#include <cmath> // Pour les fonctions mathématiques
using namespace std;

void Menu(int *n);
void Simple_calcul(char *list[], int size);
void Scientific_calcul(char *list[], int size);
void Trigonometric_calcul(char *list[], int size);
void Enter(int *x, const string &name);
void Enter_double(double *x, const string &name);
void Enter_operation(string &op, char *list[], int size);
void Print_list(char *list[], int size);

int main()
{
    int n;
    bool quit = false;

    char* list1[] = {"(", "+", "-", "*", "/", "%", "^", ")"}; // Calculs simples
    char* list2[] = {"sqrt", "pow", "log", "exp", "abs", "ceil", "floor"}; // Calculs scientifiques
    char* list3[] = {"sin", "cos", "tan", "asin", "acos", "atan"};        // Calculs trigonométriques

    cout << "Bienvenue dans le programme de calculatrice !" << endl;

    while (!quit) {
        Menu(&n);

        switch (n) {
            case 1:
                Simple_calcul(list1, sizeof(list1) / sizeof(list1[0]));
                break;
            case 2:
                Scientific_calcul(list2, sizeof(list2) / sizeof(list2[0]));
                break;
            case 3:
                Trigonometric_calcul(list3, sizeof(list3) / sizeof(list3[0]));
                break;
            case 4:
                cout << "Au revoir !" << endl;
                quit = true;
                break;
            default:
                cout << "Choix invalide ! Réessayez." << endl;
        }

        if (!quit) {
            char response;
            cout << "\nVoulez-vous effectuer un autre calcul ? (y/n) : ";
            cin >> response;
            if (response == 'n' || response == 'N') {
                cout << "Au revoir !" << endl;
                quit = true;
            }
        }
    }

    return 0;
}

void Menu(int *n) {
    cout << "\n== Menu ==" << endl;
    cout << "1- Calcul simple" << endl;
    cout << "2- Calcul scientifique" << endl;
    cout << "3- Calcul trigonométrique" << endl;
    cout << "4- Quitter" << endl;
    cout << "Choix : ";
    cin >> *n;
}

void Simple_calcul(char *list[], int size) {
    int x, y;
    string op;

    Enter(&x, "x");
    Enter_operation(op, list, size);
    Enter(&y, "y");

    if (op == "+") {
        cout << x << " + " << y << " = " << x + y << endl;
    } else if (op == "-") {
        cout << x << " - " << y << " = " << x - y << endl;
    } else if (op == "*") {
        cout << x << " * " << y << " = " << x * y << endl;
    } else if (op == "/") {
        if (y != 0)
            cout << x << " / " << y << " = " << x / y << endl;
        else
            cout << "Erreur : Division par zéro !" << endl;
    } else if (op == "%") {
        cout << x << " % " << y << " = " << x % y << endl;
    } else if (op == "^") {
        cout << x << " ^ " << y << " = " << pow(x, y) << endl;
    } else {
        cout << "Opérateur invalide !" << endl;
    }
}

void Scientific_calcul(char *list[], int size) {
    double x, y;
    string op;

    Enter_double(&x, "x");
    cout << "Opérations scientifiques disponibles : ";
    Print_list(list, size);
    cout << "\nEntrez une opération : ";
    cin >> op;

    if (op == "sqrt") {
        cout << "sqrt(" << x << ") = " << sqrt(x) << endl;
    } else if (op == "pow") {
        Enter_double(&y, "exposant");
        cout << "pow(" << x << ", " << y << ") = " << pow(x, y) << endl;
    } else if (op == "log") {
        if (x > 0)
            cout << "log(" << x << ") = " << log(x) << endl;
        else
            cout << "Erreur : Logarithme d'un nombre non positif !" << endl;
    } else if (op == "exp") {
        cout << "exp(" << x << ") = " << exp(x) << endl;
    } else if (op == "abs") {
        cout << "abs(" << x << ") = " << abs(x) << endl;
    } else if (op == "ceil") {
        cout << "ceil(" << x << ") = " << ceil(x) << endl;
    } else if (op == "floor") {
        cout << "floor(" << x << ") = " << floor(x) << endl;
    } else {
        cout << "Opération scientifique invalide !" << endl;
    }
}

void Trigonometric_calcul(char *list[], int size) {
    double x;
    string op;

    Enter_double(&x, "angle (en degrés)");
    double radians = x * M_PI / 180.0; // Conversion degrés -> radians

    cout << "Opérations trigonométriques disponibles : ";
    Print_list(list, size);
    cout << "\nEntrez une opération : ";
    cin >> op;

    if (op == "sin") {
        cout << "sin(" << x << "°) = " << sin(radians) << endl;
    } else if (op == "cos") {
        cout << "cos(" << x << "°) = " << cos(radians) << endl;
    } else if (op == "tan") {
        if (fmod(x, 90.0) == 0 && fmod(x, 180.0) != 0)
            cout << "Erreur : tan(" << x << "°) est indéfini !" << endl;
        else
            cout << "tan(" << x << "°) = " << tan(radians) << endl;
    } else if (op == "asin") {
        cout << "asin(" << x << ") = " << asin(x) * 180.0 / M_PI << "°" << endl;
    } else if (op == "acos") {
        cout << "acos(" << x << ") = " << acos(x) * 180.0 / M_PI << "°" << endl;
    } else if (op == "atan") {
        cout << "atan(" << x << ") = " << atan(x) * 180.0 / M_PI << "°" << endl;
    } else {
        cout << "Opération trigonométrique invalide !" << endl;
    }
}

void Enter(int *x, const string &name) {
    cout << "Entrez une valeur pour " << name << ": ";
    cin >> *x;
}

void Enter_double(double *x, const string &name) {
    cout << "Entrez une valeur pour " << name << ": ";
    cin >> *x;
}

void Enter_operation(string &op, char *list[], int size) {
    cout << "Entrez une opération ";
    Print_list(list, size);
    cout << ": ";
    cin >> op;
}

void Print_list(char *list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << list[i];
        if (i < size - 1) cout << ", ";
    }
}
