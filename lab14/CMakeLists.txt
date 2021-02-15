cmake_minimum_required (VERSION 2.6)
project (Lab14 CXX)
include_directories(src include)

add_executable(Lab14 main.cpp src/Arr2D.cpp include/Arr2D.h)

set(LIBSRC include/Arr2D.h src/Arr2D.cpp )
add_library(lab14 ${LIBSRC})

target_link_libraries(Lab14 lab14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab14 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab14
    DEPENDS Lab14
)