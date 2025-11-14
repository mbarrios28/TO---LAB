ControlJuego – Implementación del Patrón Singleton en un Sistema de Juego

Este ejercicio implementa un sistema básico de juego en C++ donde varios módulos (jugador, enemigos e interfaz) comparten el mismo estado global.
Para ello se utiliza el patrón Singleton, garantizando que solo exista una instancia del estado del juego en toda la ejecución.


Objetivo del Ejercicio

El ejercicio solicita:

Crear una clase ControlJuego que maneje el estado global del juego, incluyendo:

Nivel actual

Puntaje

Vida del jugador

Aplicar el patrón Singleton, de modo que:

Todos los componentes del juego compartan la misma instancia de ControlJuego.

Implementar un main que simule cómo distintos módulos acceden al mismo estado global.

Este repositorio contiene esa implementación completa.


Estructura de Clases
1. ControlJuego (Singleton)

Es la clase principal del ejercicio. Controla:

nivel_actual

puntaje

vida

Se implementa con:

static unique_ptr<ControlJuego> control;


y dos métodos estáticos para obtener la única instancia:

static ControlJuego& iniciarControl(int p, int v);
static ControlJuego& iniciarControl();


Esto garantiza que:

- Solo exista un único ControlJuego
- Todos los módulos accedan a la misma instancia
- El estado se persista a lo largo del juego

2. Entidad (Clase Base)

Clase general para cualquier entidad del juego con:

nombre

ataque

Es usada como base para Jugador y Enemigo.

3. Jugador

El jugador hereda de Entidad y usa el ControlJuego para consultar o modificar:

Vida

Puntaje

Nivel

Método principal:

void atacar(Enemigo& enemigo);


Si derrota al enemigo, el jugador gana puntaje global.

4. Enemigo

También hereda de Entidad.
Puede atacar al jugador y recibir daño.

Método para atacar:

void atacar();


Este método afecta la vida global almacenada en ControlJuego.

5. Interfaz

Simula un módulo externo (como un HUD o un menú) que también interactúa con el estado global del juego:

Cura al jugador

Aumenta puntaje


Cómo Funciona el Patrón Singleton en el Juego

Todos los módulos del juego llaman:

ControlJuego& jugador = ControlJuego::iniciarControl();


O bien:

ControlJuego& jugador = ControlJuego::iniciarControl(puntaje, vida);


Sin importar desde dónde se invoque:

Enemigos

Jugador

Interfaz

Siempre reciben la misma instancia de ControlJuego.

Esto garantiza que:

- La vida del jugador afectada por un enemigo
- Los puntos ganados al vencer enemigos
- Las curaciones desde la interfaz

Todos modifican el mismo estado centralizado.


Simulación en main()

El main demuestra cómo los distintos componentes interactúan con el mismo estado global:

Se inicializa el juego con vida = 200 y puntaje = 0.

El enemigo ataca al jugador → la vida global disminuye.

El jugador ataca al enemigo → si lo derrota, suma puntaje global.

La interfaz permite curar y aumentar puntaje.

Se muestra el estado en cada paso.

Esto comprueba que todos modifican el mismo ControlJuego, cumpliendo el ejercicio.


Ejecutar el Programa

Compilar:

g++ main.cpp -o juego


Ejecutar:

./juego