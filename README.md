# CMU 24780 yyaah2023
 24-780 final group project

### Compile and run on Mac using CMake
$> cd OSX
$> ./build_and_run.sh

### Compile and run on Mac
$> cd OSX

$> mkdir -p test.app/Contents/MacOS

$> clang -c fssimplewindowobjc.m

[tentative subject to change]
$> clang++ main.cpp fssimplewindowcpp.cpp fssimplewindowobjc.o Projectile.cpp -framework Cocoa -framework OpenGL -o test.app/Contents/MacOS/exe

$> test.app/Contents/MacOS/exe