# Lista Completa de Violaciones de Clean Code

## 📊 Resumen de Violaciones por Categoría

### 1. NOMBRES (Meaningful Names)
- [ ] Variables de una sola letra: `e`, `n`, `a`, `s`, `t`, `p`, `b`, `f`, `i`
- [ ] Clase con nombre sin significado: `e` en vez de `Employee`
- [ ] Nombres inconsistentes: `calc` vs `printInfo` vs `update`
- [ ] Abreviaciones no estándar: `emps`, `mgrs`, `dess`, `addr`
- [ ] Nombres que no revelan intención: `t` para tipo
- [ ] Sin usar nombres pronunciables

### 2. FUNCIONES (Functions)
- [ ] Función `calc()` hace 5 cosas diferentes: calcula bono, impuestos, neto, imprime y guarda
- [ ] Función `processEmployees()` tiene más de 200 líneas
- [ ] Función con demasiados parámetros: `update(7 parámetros)`
- [ ] Parámetros booleanos que cambian comportamiento: `calc(bool print, bool save, ...)`
- [ ] Funciones con parámetros de salida: `processEmployees(..., int& totalProcessed, bool& hasError)`
- [ ] Función que hace y retorna (Command-Query Separation): `applyRaise()`
- [ ] Nombres de función que no describen lo que hacen: `calc()` retorna net salary
- [ ] Múltiples niveles de abstracción en una sola función
- [ ] Efectos secundarios ocultos: constructor incrementa `globalCounter`
- [ ] Función `main()` demasiado larga (más de 70 líneas)

### 3. COMENTARIOS (Comments)
- [ ] Comentarios obvios: `// name`, `// age`, `// salary`
- [ ] Comentarios que explican código malo en vez de refactorizar
- [ ] Comentarios VIOLACIÓN repetidos innecesariamente
- [ ] Falta documentación donde se necesita (API pública)
- [ ] Comentarios de código muerto: "This will never print"

### 4. FORMATEO (Formatting)
- [ ] Inconsistencia en espaciado: `if(x)` vs `if (x)`
- [ ] Inconsistencia en llaves: algunas en misma línea, otras no
- [ ] Líneas muy largas (>120 caracteres)
- [ ] Falta de espacios en blanco vertical para separar conceptos
- [ ] Declaraciones múltiples en una línea: `n=nn;a=aa;s=ss;t=tt;`

### 5. OBJETOS Y ESTRUCTURAS DE DATOS (Objects and Data Structures)
- [ ] Todo público, sin encapsulamiento
- [ ] Getters/Setters implícitos por acceso directo
- [ ] Exposición de detalles de implementación
- [ ] Clase híbrida (ni objeto ni estructura de datos)
- [ ] Sin Data Transfer Objects (DTOs)

### 6. MANEJO DE ERRORES (Error Handling)
- [ ] Sin try-catch donde se necesita (lectura de archivos)
- [ ] Catch genérico que oculta errores: `catch(...)`
- [ ] Códigos de error en vez de excepciones: `addProject()` retorna -1, -2, -3
- [ ] Sin validación de entrada del usuario
- [ ] División por cero no manejada: `total/activeCount`
- [ ] Sin verificar si archivo se abrió correctamente
- [ ] Operaciones con punteros sin verificar nullptr
- [ ] `stoi()` puede lanzar excepción sin capturar

### 7. LÍMITES (Boundaries)
- [ ] Using namespace std global
- [ ] Sin abstracción de bibliotecas externas
- [ ] Sin interfaces para dependencias
- [ ] Acoplamiento fuerte con iostream
- [ ] Todo en un solo archivo

### 8. CLASES (Classes)
- [ ] Violación de Single Responsibility Principle (SRP)
- [ ] Clase `e` hace demasiadas cosas: datos, cálculos, presentación, persistencia
- [ ] Sin cohesión: miembros no relacionados entre sí
- [ ] Constructor con efectos secundarios
- [ ] Destructor ausente (memory leak)
- [ ] Sin separación de interfaz e implementación

### 9. SISTEMAS (Systems)
- [ ] Variables globales: `globalCounter`, `logs`, `debugMode`, `DB_FILE`
- [ ] Dependencias ocultas
- [ ] Sin inyección de dependencias
- [ ] Sin separación de concerns
- [ ] Lógica de negocio mezclada con UI
- [ ] Sin patrón de arquitectura (MVC, Clean Architecture, etc.)

### 10. EMERGENCIA / CODE SMELLS (Emergence / Smells)
- [ ] Código duplicado (cálculo de bonos por proyectos repetido 3 veces)
- [ ] Números mágicos: 0.1, 0.15, 0.08, 500, 1000, etc.
- [ ] Código muerto: `cout<<"This will never print"<<endl;`
- [ ] Feature envy: `processEmployees` manipula internals de `e`
- [ ] Long parameter list
- [ ] Primitive obsession: usar int para tipos en vez de enum
- [ ] Switch statements que deberían ser polimorfismo
- [ ] Speculative generality: array de 10 bonos sin razón clara
- [ ] Temporary field: `bonusHistory` solo se usa a veces

### 11. CONCURRENCIA (Concurrency)
- [ ] N/A - No aplica en este ejemplo

### 12. REFINAMIENTO SUCESIVO (Successive Refinement)
- [ ] Sin tests unitarios
- [ ] Código no testeable
- [ ] Sin refactorización incremental
- [ ] Todo escrito de una vez sin iteraciones

### 13. GESTIÓN DE RECURSOS
- [ ] Memory leak: `new` sin `delete` en destructor
- [ ] Punteros crudos: `string* addr`
- [ ] Array dinámico sin gestión: `double* bonusHistory`
- [ ] Archivos sin cerrar apropiadamente (en caso de error)
- [ ] Sin uso de RAII
- [ ] Sin smart pointers

### 14. CONSTANTES Y MACROS
- [ ] Macros en vez de constantes: `#define MAX 100`
- [ ] Sin uso de `const` o `constexpr`
- [ ] Valores hardcodeados en todo el código

### 15. LÓGICA DE NEGOCIO
- [ ] Lógica de negocio esparcida (cálculo de bonos, impuestos, etc.)
- [ ] Sin validación de reglas de negocio
- [ ] Cálculos complejos sin extraer
- [ ] Condicionales anidados profundos (4-5 niveles)
- [ ] Lógica escondida: `if(a>50)tax-=500;`

### 16. ESTRUCTURAS DE CONTROL
- [ ] If-else en cadena gigante (12+ bloques en `processEmployees`)
- [ ] Comparación con literales múltiples: `if(op=="add"||op=="ADD"||op=="a")`
- [ ] Return temprano sin cleanup
- [ ] Loop infinito con break escondido
- [ ] Iteración con índices en vez de iteradores
- [ ] Modificar colección durante iteración

### 17. ENTRADA/SALIDA
- [ ] Mezcla de input/output con lógica
- [ ] Sin separación de capas (presentación/negocio/datos)
- [ ] Formato de salida inconsistente
- [ ] Sin abstracción de UI
- [ ] Hardcoded prompts

### 18. TESTING
- [ ] Cero tests
- [ ] Código difícil de testear (acoplamiento, efectos secundarios)
- [ ] Sin mocks o stubs
- [ ] Sin coverage

### 19. PRINCIPIOS SOLID
- [ ] **S** - Single Responsibility: violado en clase `e` y función `processEmployees`
- [ ] **O** - Open/Closed: difícil de extender sin modificar
- [ ] **L** - Liskov Substitution: N/A (sin herencia)
- [ ] **I** - Interface Segregation: sin interfaces
- [ ] **D** - Dependency Inversion: dependencias concretas, no abstracciones

### 20. OTROS PROBLEMAS
- [ ] Sin namespace propio
- [ ] Sin versionado
- [ ] Sin logging apropiado (cout en vez de logger)
- [ ] Sin configuración externa
- [ ] Sin documentación de API
- [ ] Sin manejo de internacionalización
- [ ] ASCII art innecesario
- [ ] Emojis en código de producción

---

## 🎯 Total de Violaciones: ~150+

Este código es un ejemplo perfecto de **todo lo que NO se debe hacer** en programación profesional.

## 📝 Ejercicio

Marca cada violación a medida que la identifiques en el código. Luego intenta refactorizar cada categoría una a la vez.
