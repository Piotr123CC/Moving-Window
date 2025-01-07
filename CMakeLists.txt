cmake_minimum_required(VERSION 3.10)

project(MovingWindow LANGUAGES C)

message(STATUS "-----------------------Moving Window-----------------------")


if(WIN32)
    message(STATUS "Building on Windows")
elseif (UNIX)
    message(STATUS "Building on Linux")
endif()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -DNDEBUG -DEIGEN_MPL2_ONLY -std=c11")

if (${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
    add_compile_options(-fdiagnostics-color=always)
endif()

set(SRC
    ${CMAKE_SOURCE_DIR}/Src/main.c
    ${CMAKE_SOURCE_DIR}/Src/file.c
    ${CMAKE_SOURCE_DIR}/Src/queue.c
    ${CMAKE_SOURCE_DIR}/Src/algorithms.c)


add_library(MyLib ${SRC})

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/Src/main.c)

target_include_directories(MyLib PUBLIC Inc)

target_link_libraries(${PROJECT_NAME} PRIVATE MyLib)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND move "${CMAKE_SOURCE_DIR}\\build\\${PROJECT_NAME}.exe" "${CMAKE_SOURCE_DIR}" )
elseif(UNIX)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND mv "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}" "${CMAKE_SOURCE_DIR}" )
endif()