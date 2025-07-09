@echo off

mkdir bin
copy external\SDL3\lib\x64\SDL3.dll bin\

cls
pushd bin

cl -DLEARN_OPENGL_SDL3 -DASSERTIONS_ENABLED ..\src\learn_opengl.cpp -Zi -I..\external\SDL3\include -I..\external\glad\include ..\external\SDL3\lib\x64\SDL3.lib

popd
