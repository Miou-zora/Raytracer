project(Sphere)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -W -pedantic -fPIC")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}../../../../../../plugins/")

set(SPHERE_CPP "Sphere.cpp" "Sphere.hpp" "../AShape.hpp" "../IShape.hpp" "../../Object.cpp" "../../Object.hpp")
add_library(sphere SHARED ${SPHERE_CPP})
set_target_properties(sphere PROPERTIES PREFIX "")