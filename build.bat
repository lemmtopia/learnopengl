@echo off

mkdir bin

cls
pushd bin

cl -D_LEARN_OPENGL_SDL3 ..\src\learn_opengl.cpp -Zi -I..\external\SDL3\include -I..\external\glad\include ..\external\SDL3\lib\x64\SDL3.lib

popd
