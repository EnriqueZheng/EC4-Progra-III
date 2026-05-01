cmake_minimum_required(VERSION 3.10.2)
project(prog3_unit2_template_clases_v2026_01)

set(CMAKE_CXX_STANDARD 23)
if(UNIX AND NOT APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

if(MINGW OR CYGWIN)
    add_definitions(-O3)
endif()

include_directories(./include ./src)
file(GLOB_RECURSE source_files CONFIGURE_DEPENDS
        src/*.cpp
        src/*.cc
        src/*.cxx)

add_executable(${PROJECT_NAME}
        main.cpp
        ${source_files}
        array_wrapper.cpp
        array_wrapper.h
        tuple_printer.cpp
        tuple_printer.h
        static_matrix.cpp
        static_matrix.h
        type_list.cpp
        type_list.h
        serializer.cpp
        serializer.h
        fixed_point.cpp
        fixed_point.h
        logger.cpp
        logger.h
        polynomial.cpp
        polynomial.h
        smart_array.cpp
        smart_array.h
        unit.cpp
        unit.h
        array_wrapper.cpp)

if(UNIX AND NOT APPLE)
    find_package(TBB)
    target_link_libraries(${PROJECT_NAME} TBB::tbb)
endif()


