@echo off
cd build
make
cd ../

cd bin
main.exe
gtest_main.exe
cd ../

pause