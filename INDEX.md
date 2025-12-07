# 📦 Employee Management System - Dirty Code Edition

## 🎯 Propósito

Este proyecto contiene **intencionalmente** código de mala calidad para aprender Clean Code mediante ejemplos prácticos.

## 📂 Estructura del Proyecto

```
employee-management-dirty/
│
├── 📄 QUICK_START.md          ⭐ EMPIEZA AQUÍ - Guía rápida
├── 📄 README.md               📖 Documentación completa
├── 📄 VIOLATIONS_LIST.md      ✅ Checklist de 150+ violaciones
├── 📄 EXERCISES.md            💪 Ejercicios prácticos de refactorización
│
├── 🔨 compile.sh              🚀 Compilación simple (Linux/Mac)
├── 🔨 compile.bat             🚀 Compilación simple (Windows)
├── 🔨 build.sh                🏗️  Compilación con CMake (Linux/Mac)
├── 🔨 build.bat               🏗️  Compilación con CMake (Windows)
├── ⚙️  CMakeLists.txt          🏗️  Configuración de CMake
│
├── 📁 src/
│   └── main.cpp               💀 EL CÓDIGO HORRIBLE (2000+ líneas)
│
├── 📁 build/                   🔧 Directorio de compilación
│   └── bin/
│       └── employee_system    ▶️  Ejecutable compilado
│
├── 📄 employees_import.csv    📊 Datos de ejemplo
└── 📄 .gitignore              🚫 Archivos a ignorar

```

## 🚀 Inicio Rápido (3 pasos)

### 1. Compilar
```bash
# Linux/Mac
./compile.sh

# Windows
compile.bat
```

### 2. Ejecutar
```bash
# Linux/Mac
./build/bin/employee_system

# Windows
build\bin\employee_system.exe
```

### 3. Explorar
```
> help          # Ver comandos disponibles
> list          # Ver empleados precargados
> stats         # Ver estadísticas
> exit          # Salir
```

## 📚 Guía de Lectura Recomendada

1. **QUICK_START.md** - Para empezar rápido (5 min)
2. **README.md** - Documentación completa (15 min)
3. **src/main.cpp** - Leer el código horrible (30 min)
4. **VIOLATIONS_LIST.md** - Identificar violaciones (45 min)
5. **EXERCISES.md** - Practicar refactorización (horas/días)

## 🎓 Camino de Aprendizaje

### Nivel 1: Observación (1-2 horas)
- ✅ Compila y ejecuta el programa
- ✅ Lee el código fuente
- ✅ Identifica violaciones obvias (nombres, formateo)

### Nivel 2: Análisis (2-4 horas)
- ✅ Usa `VIOLATIONS_LIST.md` como checklist
- ✅ Marca cada violación que encuentres
- ✅ Entiende POR QUÉ cada una es problemática

### Nivel 3: Práctica (5-10 horas)
- ✅ Completa ejercicios de Nivel 1-2 en `EXERCISES.md`
- ✅ Refactoriza funciones individuales
- ✅ Aplica principios de Clean Code

### Nivel 4: Maestría (10+ horas)
- ✅ Completa ejercicios de Nivel 3-5
- ✅ Reconstruye el proyecto desde cero
- ✅ Implementa arquitectura limpia
- ✅ Agrega tests unitarios

## 🐛 Categorías de Violaciones

- ❌ **Nombres** (15+ violaciones)
- ❌ **Funciones** (20+ violaciones)
- ❌ **Comentarios** (10+ violaciones)
- ❌ **Formateo** (15+ violaciones)
- ❌ **Objetos/Estructuras** (10+ violaciones)
- ❌ **Manejo de Errores** (15+ violaciones)
- ❌ **Límites** (5+ violaciones)
- ❌ **Clases** (10+ violaciones)
- ❌ **Sistemas** (10+ violaciones)
- ❌ **Code Smells** (30+ violaciones)
- ❌ **Gestión de Recursos** (10+ violaciones)

**Total: 150+ violaciones intencionales**

## 📖 Recursos Adicionales

### Libros Recomendados
- 📕 "Clean Code" - Robert C. Martin
- 📗 "Refactoring" - Martin Fowler
- 📘 "Design Patterns" - Gang of Four
- 📙 "The Pragmatic Programmer"

### Sitios Web
- 🌐 refactoring.guru
- 🌐 sourcemaking.com
- 🌐 clean-code-developer.com

### Práctica
- 💻 codewars.com
- 💻 exercism.org
- 💻 leetcode.com

## ⚠️ Advertencias Importantes

- ❌ **NO usar en producción**: Este código es intencionalmente malo
- ✅ **Warnings del compilador**: Son parte del ejemplo educativo
- ✅ **Memory leaks**: Deliberados para demostrar malas prácticas
- ✅ **Sin tests**: Intencional, para que agregues los tuyos

## 🎯 Objetivos de Aprendizaje

Al completar este proyecto, deberías ser capaz de:

- ✅ Identificar violaciones de Clean Code
- ✅ Entender POR QUÉ son problemáticas
- ✅ Aplicar principios SOLID
- ✅ Refactorizar código legacy
- ✅ Escribir código mantenible
- ✅ Implementar arquitectura limpia
- ✅ Hacer código testeable

## 💬 Preguntas Frecuentes

**P: ¿Por qué tantas violaciones?**
R: Para tener ejemplos de TODO lo que puede salir mal.

**P: ¿Debería usar este código en mi proyecto?**
R: ¡Absolutamente NO! Es solo para aprender.

**P: ¿Las advertencias del compilador son normales?**
R: Sí, son intencionales. Un código limpio no tendría advertencias.

**P: ¿Cuánto tiempo tomará refactorizar todo?**
R: Depende de tu nivel, desde 10 hasta 40+ horas.

**P: ¿Necesito CMake?**
R: No, puedes usar los scripts `compile.sh` o `compile.bat`.

## 📊 Estadísticas del Proyecto

- **Líneas de código**: ~2000
- **Funciones**: 15
- **Clases**: 1 (horrible)
- **Violaciones**: 150+
- **Memory leaks**: 3+
- **Código duplicado**: 30%+
- **Complejidad ciclomática**: 25+
- **Testabilidad**: 0%

## 🏆 Desafío Final

¿Puedes refactorizar este código y lograr:
- ✅ 0 violaciones de Clean Code
- ✅ 0 warnings del compilador
- ✅ 90%+ cobertura de tests
- ✅ Complejidad ciclomática < 5 por función
- ✅ Arquitectura limpia con capas separadas

---

## 🚀 ¡Comienza Ahora!

```bash
# 1. Compila
./compile.sh

# 2. Ejecuta
./build/bin/employee_system

# 3. Lee
cat QUICK_START.md

# 4. Aprende
cat VIOLATIONS_LIST.md

# 5. Practica
cat EXERCISES.md
```

**¡Buena suerte en tu viaje hacia el Clean Code!** 🎓✨

---

**Versión**: 1.0  
**Autor**: Proyecto Educativo  
**Licencia**: Uso educativo libre  
**Última actualización**: Diciembre 2025
