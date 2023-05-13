project(Plane)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -W -pedantic -fPIC")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}../../../../../../plugins/")

set(PLANE_CPP "Plane.cpp" "Plane.hpp" "../AShape.hpp" "../IShape.hpp" "../../Object.cpp" "../../Object.hpp" "../../../../Maths/Vertex/Vertex.cpp" "../../../../Maths/Vertex/Vertex.hpp")
add_library(plane SHARED ${PLANE_CPP})
set_target_properties(plane PROPERTIES PREFIX "")