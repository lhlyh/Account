@echo off

set /p n= 请输入文件名:
set file_name=%n%
set prj_path=%cd%
cd include
cd.>%file_name%.h
cd ../src/core
cd.>%file_name%.cc
cd %prj_path%
cd src/gtest
cd.>gtest_%file_name%.cc
echo file Created!
pause