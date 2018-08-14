@echo off
cd build
make
cd ../

set /p n= gtest_filter=
cd bin
main.exe
gtest_main.exe --gtest_filter=%n%*
cd ../

pause