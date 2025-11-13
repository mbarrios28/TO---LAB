# Sistema de Logger con Patrón Singleton en C++

## Descripción
Implementación en **C++** de un sistema de registro (*logging*) utilizando el **patrón de diseño Singleton**.  
Este sistema garantiza una única instancia global para el registro de mensajes en toda la aplicación, escribiendo en un archivo de bitácora con marcas temporales.

---

## Características

- **Patrón Singleton:** Garantiza una única instancia en toda la aplicación.  
- **Registro con timestamp:** Cada mensaje incluye fecha y hora exactas.  
- **Archivo persistente:** Todos los logs se guardan en `bitacora.log`.  
- **Thread-safe:** Implementación segura para entornos multihilo (versión con referencia).  
- **Fácil integración:** Simple de usar desde cualquier parte del código.

---

## Características Técnicas

- **Prevención de copias:** Constructores de copia y operadores de asignación eliminados.  
- **Manejo seguro de recursos:** Cierre automático del archivo al finalizar.  
- **Formato consistente:** Estructura uniforme en todos los mensajes de log.  
- **Salida dual:** Escribe en archivo y muestra en consola simultáneamente.

---

## Estructura del Proyecto

EJERCICIO 2/
│
├── Logger.h # Interfaz de la clase Logger
├── Logger.cpp # Implementación del Logger (versión puntero)
├── FuncionesPrueba.h # Declaraciones de funciones de prueba
├── FuncionesPrueba.cpp # Implementación de funciones de prueba
├── main.cpp # Programa principal de demostración
├── makefile # Sistema de build automatizado
└── README.md

---

## Compilación con Makefile

```bash
# Clonar el repositorio
git clone https://github.com/mbarrios28/TO---LAB.git
cd "Laboratorio 7"

# Compilar versión principal 
make

# Limpiar archivos compilados
make clean