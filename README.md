# Employee Management System - Dirty Code Edition

⚠️ **ADVERTENCIA**: Este proyecto contiene INTENCIONALMENTE código de mala calidad como ejemplo educativo para aprender los principios de Clean Code.

## 📋 Descripción

Este es un sistema de gestión de empleados escrito deliberadamente violando todos los principios de Clean Code. Es un ejemplo perfecto para:
- Aprender a identificar code smells
- Practicar refactorización
- Entender por qué Clean Code es importante

## 🔨 Compilación

### Opción 1: Compilación Simple (Recomendada)

**Linux/Mac:**
```bash
./compile.sh
./build/bin/employee_system
```

**Windows:**
```bash
compile.bat
build\bin\employee_system.exe
```

**Manual:**
```bash
# Linux/Mac
g++ -std=c++17 -Wall src/main.cpp -o build/bin/employee_system

# Windows
g++ -std=c++17 -Wall src\main.cpp -o build\bin\employee_system.exe
```

### Opción 2: Compilación con CMake

**Requisitos:**
- CMake 3.10 o superior
- Compilador C++ con soporte para C++17 (GCC, Clang, MSVC)

**Linux/Mac:**
```bash
./build.sh
# o manualmente:
mkdir build && cd build
cmake ..
cmake --build .
./bin/employee_system
```

**Windows (Visual Studio):**
```bash
build.bat
# o manualmente:
mkdir build && cd build
cmake ..
cmake --build . --config Release
.\bin\Release\employee_system.exe
```

**Windows (MinGW):**
```bash
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
.\bin\employee_system.exe
```

⚠️ **Nota:** Las advertencias del compilador son **intencionales** - forman parte de las violaciones de Clean Code para propósitos educativos.

## 🎮 Uso del Sistema

Una vez ejecutado, verás un menú interactivo. Comandos disponibles:

- `add` o `a` - Agregar nuevo empleado
- `list` o `l` - Listar todos los empleados
- `bonus` o `b` - Calcular bonos
- `search` o `s` - Buscar empleado por nombre
- `raise` o `r` - Aplicar aumento salarial
- `avgsal` o `avg` - Calcular salario promedio
- `delete` o `d` - Eliminar empleado
- `export` o `e` - Exportar a CSV
- `import` o `i` - Importar desde CSV
- `stats` - Mostrar estadísticas
- `logs` - Ver logs del sistema
- `help` o `h` o `?` - Mostrar ayuda
- `exit` o `quit` o `q` - Salir

## 🐛 Violaciones de Clean Code Incluidas

### 1. **Nombres Sin Significado**
- Variables de una letra: `e`, `n`, `a`, `s`, `t`
- Abreviaciones confusas
- Nombres inconsistentes

### 2. **Funciones Problemáticas**
- Funciones muy largas (>100 líneas)
- Múltiples responsabilidades
- Demasiados parámetros
- Parámetros booleanos
- Efectos secundarios ocultos

### 3. **Manejo de Errores**
- Sin manejo de excepciones
- Códigos de error en vez de excepciones
- Catch genérico
- Sin validación de entrada
- División por cero no manejada

### 4. **Gestión de Memoria**
- Memory leaks (new sin delete)
- Punteros crudos sin gestión
- Destructor ausente

### 5. **Diseño y Arquitectura**
- Variables globales
- Sin encapsulamiento (todo público)
- Violación de SRP
- Acoplamiento fuerte
- Sin separación de capas

### 6. **Code Smells**
- Código duplicado
- Números mágicos
- Código muerto
- Comentarios innecesarios
- Formateo inconsistente

### 7. **Otros Problemas**
- Using namespace std
- Macros en vez de constantes
- Hardcoded values
- Sin tests
- Todo en un archivo

## 📚 Para Aprender

Este proyecto es ideal para:

1. **Identificar violaciones**: Lee el código y anota todas las violaciones que encuentres
2. **Practicar refactorización**: Intenta mejorar una función a la vez
3. **Comparar antes/después**: Crea una versión limpia y compara

## 🎯 Ejercicios Sugeridos

1. Identifica todas las violaciones del principio SRP
2. Refactoriza la clase `e` para que tenga nombres significativos
3. Extrae la función `processEmployees` en múltiples funciones pequeñas
4. Implementa manejo de errores apropiado
5. Elimina los memory leaks
6. Separa responsabilidades en diferentes clases
7. Crea una versión con tests unitarios

## 📖 Recursos de Clean Code

- **Libro**: "Clean Code" por Robert C. Martin
- **Principios SOLID**
- **Refactoring** por Martin Fowler
- **Design Patterns**

## ⚠️ Disclaimer

Este código NO debe usarse en producción. Es únicamente con fines educativos para demostrar malas prácticas.

---

**Autor**: Ejemplo educativo para aprendizaje de Clean Code
**Licencia**: Uso educativo libre
