#include <graphics.h>
#include<iostream>
using namespace std;

struct NODO {
	int dato;
	NODO* izq, * der;
};

int menu();
int menu2();
NODO* crear(NODO* raiz);
NODO* insertar(NODO* raiz, int dato, int* ins);
NODO* encontrar(NODO* raiz, int dato);
void buscar(NODO* raiz);
void en_orden(NODO* raiz);
void pre_orden(NODO* raiz);
void pos_orden(NODO* raiz);
void esquemaProcesosQuimicos();
void arbol_DiagramaClases();
void arbol_isomorfico();
void arbol_trie();

int main()
{
	int op, op2;
	NODO* raiz = NULL;

	do
	{
		op = menu();
		switch (op)
		{
		case 1: raiz = crear(raiz);
			cout << endl << endl << "DATOS EN EN-ORDEN" << endl;
			en_orden(raiz);
			cout << endl << endl << "DATOS EN PRE-ORDEN" << endl;
			pre_orden(raiz);
			cout << endl << endl << "DATOS EN POS-ORDEN" << endl;
			pos_orden(raiz);
			cout << endl << endl;
			system("PAUSE");
			break;
		case 2: 
			arbol_isomorfico();
			system("PAUSE");
			break;
		case 3: 
			esquemaProcesosQuimicos();
			system("PAUSE");
			break;
		case 4: 
			arbol_DiagramaClases();
			system("PAUSE");
			break;
		case 5: 
			arbol_trie();
			system("PAUSE");
			break;
		case 6:
			cout << "Gracias ... Vuelva pronto ..";
			break;
		default:
			cout << "Seleccione una opcion correcta.." << endl << endl;
			system("PAUSE");
		}
	} while (op != 6);
	return 0;
}

int menu()
{
	int op;
	system("CLS");
	cout << "MENU DE OPCIONES - ABB" << endl;
	cout << "----------------------" << endl;
	cout << "1. En-Orden / Pre-Orden / Pos-Orden" << endl;
	cout << "2. Arbol Isomorfico" << endl;
	cout << "3. Arbol composicion Atmosferica" << endl;
	cout << "4. Arbol Diagrama de clases" << endl;
	cout << "5. Arbol TRIE" << endl;
	cout << "6. Salir " << endl;
	cout << "Elija una opcion: ";
	cin >> op;
	return op;
}

//Encontrar un NODO
NODO* encontrar(NODO* raiz, int dato) {
	NODO* buscado;
	if (raiz == NULL || dato == raiz->dato)
		buscado = raiz;
	else
		if (dato < raiz->dato)
			buscado = encontrar(raiz->izq, dato);
		else
			buscado = encontrar(raiz->der, dato);
	return buscado;
}

//Insertar el NODO
NODO* insertar(NODO* raiz, int dato, int *ins) {

	if (raiz == NULL) {	//Nuevo Elmento
		NODO* nuevo;
		nuevo = new NODO;
		nuevo->dato = dato;
		nuevo->izq = NULL;
		nuevo->der= NULL;
		raiz = nuevo;
		*ins = 1; //Si se inserto
	}
	else {
		if (dato == raiz->dato)
			cout << "Descartado...";
		else
			if (dato < raiz->dato)
				raiz->izq = insertar(raiz->izq, dato, ins);
			else
				raiz->der = insertar(raiz->der, dato, ins);
	}
	return raiz;
}

//Crear ABB
NODO* crear(NODO* raiz)
{
	int n, i, dato, ins;
	system("CLS");
	cout << "CREAR ARBOL BINARIO DE BUSQUEDA" << endl << endl;
	cout << "Cuantos elementos desea agregar: ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "Ingrese el elemento: ";
		cin >> dato;
		ins = 0;//Falso
		raiz = insertar(raiz, dato, &ins);
		if (!ins) {
			i--;
		}
	}
	return raiz;
}
//Recorrrido en Orden
void en_orden(NODO* raiz)
{
	if (raiz == NULL)
		return;
	en_orden(raiz->izq);
	cout << raiz->dato << " - ";
	en_orden(raiz->der);
}
//Recorrrido en Pre Orden
void pre_orden(NODO* raiz)
{
	if (raiz == NULL)
		return;
	cout << raiz->dato << " - ";
	pre_orden(raiz->izq);
	pre_orden(raiz->der);
}
//Recorrrido en Pos Orden
void pos_orden(NODO* raiz)
{
	if (raiz == NULL)
		return;
	pos_orden(raiz->izq);
	pos_orden(raiz->der);
	cout << raiz->dato << " - ";
}

void esquemaProcesosQuimicos(){
	initwindow(1250,700,"Arbol composicion Atmosferica");
	setbkcolor(WHITE);
	cleardevice();
	
	readimagefile("Composición_atmosférica.jpg", 0,0,1250,700);
    getch();
    closegraph();
}

void arbol_DiagramaClases(){
	initwindow(1250,700,"Arbol Diagrama de clases");
	setbkcolor(WHITE);
	cleardevice();
	
	readimagefile("DiagramaClases.jpg", 0,0,1250,700);
    getch();
    closegraph();
}

void arbol_isomorfico(){
	initwindow(1400,700,"Arbol Isomórfico");
	setbkcolor(WHITE);
	cleardevice();
	
	readimagefile("isomórficos.jpg", 0,0,1400,700);
    getch();
    closegraph();
}

void arbol_trie(){
	initwindow(1400,700,"Arbol TRIE");
	setbkcolor(WHITE);
	cleardevice();
	
	readimagefile("ArbolTRIE.jpg", 0,0,1400,700);
    getch();
    closegraph();
}
