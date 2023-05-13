project(Cylinder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -W -pedantic -fPIC")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}../../../../../../plugins/")

set(CYLINDER_SRC "Cylinder.cpp" "Cylinder.hpp" "../AShape.hpp" "../IShape.hpp" "../../Object.cpp" "../../Object.hpp")
add_library(cylinder SHARED ${CYLINDER_SRC})
set_target_properties(cylinder PROPERTIES PREFIX "")