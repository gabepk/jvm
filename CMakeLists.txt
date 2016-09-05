cmake_minimum_required (VERSION 2.6)

project (jvm)

include_directories("${PROJECT_SOURCE_DIR}/src" "${PROJECT_SOURCE_DIR}/include")

add_executable(jvm WIN32
    src/main.cpp
    src/classloader.cpp
    src/classviewer.cpp
    src/utils.cpp
    src/methodarea.cpp
    src/heap.cpp
    src/vmstack.cpp
    src/frame.cpp
    src/executionengine.cpp
    src/stringobject.cpp
    src/arrayobject.cpp
    src/classinstance.cpp
    src/classruntime.cpp
    include/utils.h
    include/classloader.h
    include/classviewer.h
    include/tipos.h
    include/methodarea.h
    include/object.h
    include/heap.h
    include/vmstack.h
    include/frame.h
    include/executionengine.h
    include/tipos.h
    include/stringobject.h
    include/arrayobject.h
    include/classinstance.h
    include/classruntime.h
)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/java" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_definitions(-std=c++11)
