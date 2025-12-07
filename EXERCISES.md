# 💪 Ejercicios Prácticos de Refactorización

## Nivel 1: Principiante 🟢

### Ejercicio 1.1: Nombres Significativos
**Tiempo estimado**: 15 minutos

Refactoriza la clase `e` y todos sus miembros:
- [ ] Renombrar clase `e` a `Employee`
- [ ] Renombrar `n` a `name`
- [ ] Renombrar `a` a `age`
- [ ] Renombrar `s` a `salary`
- [ ] Renombrar `t` a `type` o mejor aún, crear un enum `EmployeeType`
- [ ] Renombrar `p` a `projects`

### Ejercicio 1.2: Constantes Mágicas
**Tiempo estimado**: 10 minutos

Elimina los números mágicos:
- [ ] Crear constantes para percentages de bonos (0.1, 0.15, 0.08, etc.)
- [ ] Crear constantes para tramos de impuestos (30000, 60000, 100000)
- [ ] Crear constantes para tipos de empleado (1, 2, 3, 4)

### Ejercicio 1.3: Formateo Básico
**Tiempo estimado**: 15 minutos

Mejora el formateo del código:
- [ ] Agregar espacios consistentes alrededor de operadores
- [ ] Separar declaraciones en líneas individuales
- [ ] Agregar espacios en blanco vertical para separar secciones
- [ ] Consistencia en llaves `{}`

## Nivel 2: Intermedio 🟡

### Ejercicio 2.1: Extraer Funciones
**Tiempo estimado**: 30 minutos

Divide la función `calc()` en funciones más pequeñas:
- [ ] `calculateBonus()` - Calcular solo el bono
- [ ] `calculateTax()` - Calcular solo los impuestos
- [ ] `calculateNetSalary()` - Calcular salario neto
- [ ] `printCalculationResults()` - Imprimir resultados
- [ ] `saveCalculationToFile()` - Guardar en archivo

### Ejercicio 2.2: Eliminar Parámetros Booleanos
**Tiempo estimado**: 20 minutos

Refactoriza `calc(bool print, bool save, string file)`:
- [ ] Crear `calculateAndPrint()`
- [ ] Crear `calculateAndSave(string filename)`
- [ ] Crear `calculate()` que solo retorna el valor

### Ejercicio 2.3: Single Responsibility Principle
**Tiempo estimado**: 45 minutos

Separa responsabilidades de la clase `Employee`:
- [ ] Crear clase `EmployeeRepository` para persistencia
- [ ] Crear clase `SalaryCalculator` para cálculos
- [ ] Crear clase `EmployeePresenter` para presentación
- [ ] Dejar en `Employee` solo los datos

## Nivel 3: Avanzado 🔴

### Ejercicio 3.1: Polimorfismo sobre Condicionales
**Tiempo estimado**: 60 minutos

Reemplaza if/else con polimorfismo:
- [ ] Crear clase base abstracta `Employee`
- [ ] Crear `Developer extends Employee`
- [ ] Crear `Manager extends Employee`
- [ ] Crear `Designer extends Employee`
- [ ] Crear `Tester extends Employee`
- [ ] Implementar `calculateBonus()` en cada una

### Ejercicio 3.2: Manejo de Errores
**Tiempo estimado**: 45 minutos

Implementa manejo de errores apropiado:
- [ ] Crear excepciones personalizadas (`InvalidEmployeeException`, `FileOperationException`)
- [ ] Reemplazar códigos de error con excepciones
- [ ] Agregar try-catch donde se necesita
- [ ] Validar entradas del usuario
- [ ] Manejar división por cero

### Ejercicio 3.3: Gestión de Recursos
**Tiempo estimado**: 30 minutos

Elimina memory leaks:
- [ ] Implementar destructor apropiado
- [ ] Usar smart pointers (`unique_ptr`, `shared_ptr`)
- [ ] Implementar RAII para archivos
- [ ] Eliminar punteros crudos

## Nivel 4: Expert 🔥

### Ejercicio 4.1: Arquitectura Limpia
**Tiempo estimado**: 2-3 horas

Implementa arquitectura de capas:
- [ ] **Capa de Dominio**: `Employee`, `Salary`, `Project`
- [ ] **Capa de Aplicación**: `EmployeeService`, `SalaryService`
- [ ] **Capa de Infraestructura**: `FileRepository`, `ConsoleUI`
- [ ] **Capa de Presentación**: `EmployeeController`

### Ejercicio 4.2: Dependency Injection
**Tiempo estimado**: 1-2 horas

Implementa inyección de dependencias:
- [ ] Crear interfaces: `IEmployeeRepository`, `ISalaryCalculator`, `ILogger`
- [ ] Implementar las interfaces
- [ ] Inyectar dependencias a través de constructores
- [ ] Eliminar variables globales

### Ejercicio 4.3: Testing
**Tiempo estimado**: 2-3 horas

Hacer el código testeable y agregar tests:
- [ ] Configurar framework de testing (Google Test, Catch2)
- [ ] Escribir tests unitarios para `SalaryCalculator`
- [ ] Escribir tests para `EmployeeService`
- [ ] Implementar mocks para `IEmployeeRepository`
- [ ] Alcanzar 80%+ de cobertura

## Nivel 5: Maestro 🏆

### Ejercicio 5.1: Refactorización Completa
**Tiempo estimado**: 8-10 horas

Crear una versión completamente refactorizada:
- [ ] Aplicar todos los principios SOLID
- [ ] Implementar patrones de diseño apropiados (Strategy, Factory, Repository)
- [ ] Separación completa de concerns
- [ ] 100% testeable
- [ ] Sin violaciones de Clean Code
- [ ] Documentación completa
- [ ] CI/CD pipeline

### Ejercicio 5.2: Comparación y Documentación
**Tiempo estimado**: 2 horas

Documenta tu aprendizaje:
- [ ] Crear documento comparativo "antes vs después"
- [ ] Métricas de calidad (complejidad ciclomática, acoplamiento, cohesión)
- [ ] Lista de patrones aplicados
- [ ] Lecciones aprendidas
- [ ] Presentación del proyecto

## 🎯 Desafío Extra: Code Review

Realiza un code review del código original:
- [ ] Identifica TODAS las violaciones (usa `VIOLATIONS_LIST.md`)
- [ ] Prioriza las violaciones por impacto
- [ ] Crea un plan de refactorización
- [ ] Estima esfuerzo para cada mejora

## 📊 Métricas de Progreso

Usa estas métricas para medir tu progreso:

### Antes (Código Original)
- **Líneas por función**: 50-200
- **Complejidad ciclomática**: 15-30
- **Acoplamiento**: Alto
- **Cohesión**: Baja
- **Testabilidad**: 0%
- **Violaciones**: 150+

### Objetivo (Código Refactorizado)
- **Líneas por función**: <20
- **Complejidad ciclomática**: <5
- **Acoplamiento**: Bajo
- **Cohesión**: Alta
- **Testabilidad**: 90%+
- **Violaciones**: 0

## 💡 Consejos

1. **No intentes arreglarlo todo de una vez**: Refactoriza incrementalmente
2. **Haz commits frecuentes**: Para poder volver atrás si algo sale mal
3. **Escribe tests primero**: Para asegurar que no rompes funcionalidad
4. **Lee Clean Code**: Consulta el libro mientras refactorizas
5. **Pide feedback**: Comparte tu código refactorizado con otros

## 📚 Recursos Recomendados

- **Libro**: "Clean Code" - Robert C. Martin
- **Libro**: "Refactoring" - Martin Fowler
- **Video**: Clean Code - Uncle Bob / lessons
- **Sitio**: refactoring.guru
- **Práctica**: Code katas en codewars.com

---

**¡Éxito en tu viaje hacia el Clean Code!** 🚀
