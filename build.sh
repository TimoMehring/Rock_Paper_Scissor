#!/bin/bash

cd "$(dirname "$0")"

mkdir -p build

clang++ -std=c++17 \
src/main.cpp \
-o build/app \
-I/opt/homebrew/include \
-L/opt/homebrew/lib \
-lraylib \
-framework OpenGL \
-framework Cocoa \
-framework IOKit \
-framework CoreVideo

if [ $? -ne 0 ]; then
    echo ""
    echo "Build fehlgeschlagen."
    exit 1
fi

echo ""
echo "Build erfolgreich. Starte Programm..."
./build/app