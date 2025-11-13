Ejercicio1
Descripción General

El patrón Singleton es un patrón de diseño creacional que garantiza que una clase tenga una única instancia durante la ejecución del programa, y que exista un punto de acceso global a esa instancia.

Este patrón es útil cuando se necesita una única configuración compartida, una conexión global o un recurso que no deba duplicarse (por ejemplo: configuración del sistema, registro de logs, conexión a base de datos, etc.).

⚙️ Implementación

En este ejemplo se implementa el patrón Singleton mediante la clase Configuracion, que almacena parámetros del sistema como zona horaria, idioma, brillo y sonido.

El control de instancia se realiza utilizando std::unique_ptr, que garantiza que solo haya una instancia activa del objeto en memoria.


Explicación del código
Atributo estático configuracion
static unique_ptr<Configuracion> configuracion;

Este puntero almacena la única instancia del objeto Configuracion.
Como es static, pertenece a la clase y no a una instancia en particular.


Constructor privado
Configuracion(string zona_horaria, string idioma, int brillo, int sonido);

Al ser privado, se evita que otros objetos creen instancias directamente.
La única forma de crear el objeto es a través del método iniciarConfiguracion().


Método estático iniciarConfiguracion()
static Configuracion& iniciarConfiguracion(string z, string i, int b, int s);

Verifica si la instancia ya existe.
Si no existe, la crea usando reset() y new Configuracion(...).
Devuelve una referencia a la instancia única.
Así, aunque se invoque varias veces con distintos parámetros, solo se crea una vez.

Uso de std::unique_ptr

unique_ptr es un puntero inteligente que gestiona automáticamente la memoria.
Solo puede existir una copia del puntero en todo el programa, lo cual encaja perfectamente con la idea del Singleton: una única instancia controlada.

Cuando el programa finaliza, unique_ptr elimina automáticamente el objeto de memoria.

Salida esperada
Zona horaria: GMT-5
Idioma: Español
Brillo: 25
Sonido: 50
----------------------------
Zona horaria: GMT-5
Idioma: Español
Brillo: 25
Sonido: 50
----------------------------
Zona horaria: GMT-5
Idioma: Español
Brillo: 25
Sonido: 50
----------------------------


Aunque se intenta "crear" tres configuraciones diferentes, todas las llamadas hacen referencia al mismo objeto creado la primera vez.