@echo off

if not exist "build" ( md build )

cd build
cmake -G "MinGW Makefiles" ../
make
cd ../

pause