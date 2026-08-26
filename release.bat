@echo off

cd /d %~dp0

echo ============================
echo Building RPS Release
echo ============================
echo.

REM Alten Release-Ordner entfernen
if exist release rmdir /s /q release

REM Neuen Release-Ordner erstellen
mkdir release

REM Windows Icon kompilieren
windres icon.rc -O coff -o release/icon.res

if %errorlevel% neq 0 (
    echo.
    echo Icon konnte nicht kompiliert werden.
    pause
    exit /b %errorlevel%
)

REM Spiel als Release kompilieren
g++ -std=c++17 -O2 ^
src/main.cpp ^
src/gameplay.cpp ^
src/states.cpp ^
src/graphics.cpp ^
src/audio.cpp ^
release/icon.res ^
-o release/Rock_Paper_Scissor.exe ^
-mwindows ^
-lraylib -lopengl32 -lgdi32 -lwinmm

if %errorlevel% neq 0 (
    echo.
    echo Release Build fehlgeschlagen.
    pause
    exit /b %errorlevel%
)

REM Assets kopieren
xcopy assets release\assets\ /E /I /Y >nul

REM Resource-Datei wird nach dem Build nicht mehr gebraucht
del release\icon.res

echo.
echo ============================
echo Release erfolgreich erstellt!
echo ============================
echo.
echo release\Rock_Paper_Scissor.exe
echo.

pause