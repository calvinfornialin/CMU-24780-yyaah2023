cmake_minimum_required(VERSION 3.26)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES 
main.cpp
Character.cpp
Projectile.cpp
Stage.cpp
fssimplewindowcpp.cpp
ysglfontdata.c
yspng.cpp
fssimplewindowobjc.o
yssimplesound.cpp
yssimplesound_macosx_objc.o
)

# Header files
set(HEADERS
Character.h
Projectile.h
Stage.h
fssimplewindow.h
ysglfontdata.h
yspng.h
yssimplesound.h
)

# Add an executable target
add_executable(exe ${SOURCES} ${HEADERS})
# add_executable(exe ${SOURCES})

target_link_libraries(exe PRIVATE
    "-framework Cocoa"
    "-framework OpenGL"
    "-framework AVFoundation"
)

# Set output directory
set_target_properties(exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test.app/Contents/MacOS/)
