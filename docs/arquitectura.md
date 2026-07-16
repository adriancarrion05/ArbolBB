# Documentación del Proyecto: Menú de Estructuras de Árboles (ABB y Gráficos)

Este proyecto consiste en una aplicación de consola en C++ enfocada en la gestión de **Árboles Binarios de Búsqueda (ABB)** y la visualización gráfica de conceptos avanzados sobre teoría de árboles (isomorfismo, diagramas de clases, composición y estructuras TRIE) utilizando la biblioteca clásica `<graphics.h>`.

## 1. Estructura de Datos Principal

El núcleo dinámico del programa se basa en un nodo estándar para árboles binarios:

```cpp
struct NODO {
	int dato;
	NODO* izq, * der;
};

```

* `dato`: Almacena el valor entero del nodo.
* `izq` / `der`: Punteros autoreferenciales hacia los subárboles izquierdo y derecho.

---

## 2. Módulos y Funcionalidades

El sistema está dividido en dos grandes bloques lógicos: la lógica interna del ABB y los despliegues visuales externos.

### A. Gestión del Árbol Binario de Búsqueda (Opción 1)

Permite construir un árbol desde cero e imprimir sus datos mediante tres estrategias clásicas de recursividad:

* `crear(...)`: Solicita al usuario la cantidad de elementos y los inserta secuencialmente de manera controlada.
* `insertar(...)`: Ubica de forma ordenada cada número (los menores a la izquierda, los mayores a la derecha). Evita duplicados mandando un mensaje de "Descartado...".
* **Recorridos fundamentales:**
* **En-Orden:** Izquierda $\rightarrow$ Raíz $\rightarrow$ Derecha (Muestra los datos ordenados de menor a mayor).
* **Pre-Orden:** Raíz $\rightarrow$ Izquierda $\rightarrow$ Derecha.
* **Pos-Orden:** Izquierda $\rightarrow$ Derecha $\rightarrow$ Raíz.



### B. Módulos Gráficos e Ilustrativos (Opciones 2 a 5)

Estas funciones inicializan ventanas gráficas de tamaño personalizado y cargan diagramas externos utilizando la biblioteca `graphics.h`. Sirven como soporte educativo para explicar diferentes tipos de árboles conceptuales:

---

## 3. Flujo del Programa

El programa principal (`main`) utiliza una estructura de control cíclica `do-while` guiada por un menú numérico:

1. **Despliegue del Menú:** Función menu().
El usuario visualiza las 6 opciones disponibles en pantalla tras una limpieza de consola (`CLS`).


2. **Captura de Opción:** Switch-Case.
El programa evalúa la opción ingresada por teclado para ejecutar el bloque correspondiente.


3. **Ejecución de Tareas:** Procesamiento.
Se construye el árbol y se imprimen sus recorridos, o bien se despliega una ventana de gráficos (`initwindow`) con imágenes descriptivas que se cierran al presionar cualquier tecla (`getch()`).


4. **Cierre de Ciclo:** Opción 6.
El bucle finaliza únicamente cuando el usuario digita el número 6, finalizando el proceso de forma segura.


---

## 4. Requisitos de Compilación

* **Compilador:** Compatible con C++ (se recomienda configurar entornos clásicos como Dev-C++ o Code::Blocks que faciliten la integración de gráficos).
* **Dependencia Gráfica:** Requiere tener correctamente configurada la biblioteca **WinBGIm / Graphics.h** en el enlazador (Linker), así como los archivos de imagen (`.jpg`) en la misma ruta de ejecución del binario.