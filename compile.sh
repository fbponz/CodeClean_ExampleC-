#!/bin/bash

echo "╔════════════════════════════════════════╗"
echo "║  Building Employee Management System   ║"
echo "║       (Dirty Code Edition)             ║"
echo "╚════════════════════════════════════════╝"
echo ""

# Crear directorios si no existen
mkdir -p build/bin

echo "🔨 Compiling with g++..."
g++ -std=c++17 -Wall -Wextra src/main.cpp -o build/bin/employee_system

if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    exit 1
fi

echo ""
echo "✅ Build successful!"
echo ""
echo "⚠️  Warnings are INTENTIONAL - they are part of Clean Code violations!"
echo ""
echo "To run the program:"
echo "  ./build/bin/employee_system"
echo ""
