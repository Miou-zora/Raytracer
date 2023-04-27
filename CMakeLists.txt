cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wshadow -Wuninitialized")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
project(raytracer)


set(INCLUDE_SRC "src/Maths/Ray"
                "src/Maths/Rect3D"
                "src/Maths/Vector"
                "src/Maths/Vertex")
set(SRC "src/Maths/Ray/Ray.cpp"
        "src/Maths/Rect3D/Rect3D.cpp"
        "src/Maths/Vector/Vector.cpp"
        "src/Maths/Vertex/Vertex.cpp")
include_directories(${INCLUDE_SRC})
set(MAIN "main.cpp")
add_executable(raytracer ${MAIN} ${SRC})

### TESTS ###

set(CMAKE_CXX_FLAGS "-ldl -Wall -Werror -Wextra -Wshadow -Wuninitialized --coverage -lcriterion")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

enable_testing()
set(TEST_SRC "tests/Maths/tests_vertex.cpp"
"tests/Maths/tests_vector.cpp"
"tests/Maths/tests_rect3D.cpp")

add_executable(tests_run ${TEST_SRC} ${SRC})

