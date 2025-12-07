# 🚀 Quick Start Guide

## Inicio Rápido en 3 Pasos

### 1️⃣ Compilar

**Linux/Mac:**
```bash
./compile.sh
```

**Windows:**
```bash
compile.bat
```

### 2️⃣ Ejecutar

**Linux/Mac:**
```bash
./build/bin/employee_system
```

**Windows:**
```bash
build\bin\employee_system.exe
```

### 3️⃣ Usar

Comandos básicos al ejecutar:
- `help` - Ver todos los comandos
- `list` - Ver empleados precargados
- `stats` - Ver estadísticas
- `exit` - Salir

## 📁 Estructura del Proyecto

```
employee-management-dirty/
├── src/
│   └── main.cpp              # Código fuente (TODO el código malo aquí)
├── build/                     # Directorio de compilación (se genera)
│   └── bin/
│       └── employee_system   # Ejecutable compilado
├── CMakeLists.txt            # Configuración de CMake
├── compile.sh                # Script de compilación simple (Linux/Mac)
├── compile.bat               # Script de compilación simple (Windows)
├── build.sh                  # Script de compilación CMake (Linux/Mac)
├── build.bat                 # Script de compilación CMake (Windows)
├── employees_import.csv      # Datos de ejemplo para importar
├── README.md                 # Documentación completa
├── VIOLATIONS_LIST.md        # Lista de todas las violaciones
└── .gitignore               # Archivos a ignorar en git
```

## 🎯 Propósito Educativo

Este código contiene **150+ violaciones intencionales** de Clean Code para:
- ✅ Aprender a identificar code smells
- ✅ Practicar refactorización
- ✅ Entender por qué Clean Code es importante

## 📚 Siguientes Pasos

1. **Lee el código**: Abre `src/main.cpp` e identifica violaciones
2. **Usa la checklist**: Abre `VIOLATIONS_LIST.md` y marca cada una
3. **Refactoriza**: Intenta mejorar el código aplicando Clean Code
4. **Compara**: Crea una versión limpia y compara con la original

## ⚠️ Advertencias Importantes

- ❌ **NO usar este código en producción**
- ✅ Las advertencias del compilador son **intencionales**
- ✅ Los memory leaks son **parte del ejemplo**
- ✅ La falta de manejo de errores es **deliberada**

## 🔗 Recursos

Ver `README.md` para documentación completa.
Ver `VIOLATIONS_LIST.md` para lista exhaustiva de problemas.

---

**¡Feliz aprendizaje de Clean Code!** 🎓
