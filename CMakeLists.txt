cmake_minimum_required(VERSION 3.9)
project(raytracer)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wshadow -Wuninitialized -lconfig++")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(INCLUDE_SRC "src"
                "src/Maths"
                "src/Maths/Ray"
                "src/Maths/Rect3D"
                "src/Maths/Vector"
                "src/Maths/Vertex"
                "src/RayTracer/Builder"
                "src/RayTracer/HitRecord"
                "src/RayTracer/Material"
                "src/RayTracer/Object"
                "src/RayTracer/Object/Camera"
                "src/RayTracer/Object/Light"
                "src/RayTracer/Object/Shape"
                "src/RayTracer/Object/Shape/Sphere"
                "src/RayTracer/Object/Shape/Plane"
                "src/RayTracer/Object/Shape/Cylinder"
                "src/RayTracer/Core"
                "src/RayTracer/Core/SFMLCore"
                "src/RayTracer/Core/BasicCore"
                "src/RayTracer/Object/Light/DirectionalLight"
                "src/RayTracer/Renderer"
                "src/RayTracer/Renderer/EnhanceRenderer"
                "src/RayTracer/Renderer/FastRenderer"
                "src/RayTracer/Scene"
                "src/RayTracer/Transformation"
                "src/RayTracer/RGBAColor"
                "src/RayTracer/Frame"
                "src/RayTracer/Displayer"
                "src/RayTracer/Displayer/PPMDisplayer")
include_directories(${INCLUDE_SRC})
set(SRC "src/Maths/Ray/Ray.cpp"
        "src/Maths/Rect3D/Rect3D.cpp"
        "src/Maths/Vector/Vector.cpp"
        "src/Maths/Vertex/Vertex.cpp"
        "src/RayTracer/Object/Camera/Camera.cpp"
        "src/RayTracer/Core/SFMLCore/SFMLCore.cpp"
        "src/RayTracer/Core/BasicCore/BasicCore.cpp"
        "src/RayTracer/Object/Shape/Sphere/Sphere.cpp"
        "src/RayTracer/Object/Shape/Plane/Plane.cpp"
        "src/RayTracer/Object/Shape/Cylinder/Cylinder.cpp"
        "src/RayTracer/Object/Light/DirectionalLight/DirectionalLight.cpp"
        "src/RayTracer/Object/Object.cpp"
        "src/RayTracer/RGBAColor/RGBAColor.cpp"
        "src/RayTracer/Renderer/EnhanceRenderer/EnhanceRenderer.cpp"
        "src/RayTracer/Renderer/FastRenderer/FastRenderer.cpp"
        "src/RayTracer/Displayer/PPMDisplayer/PPMDisplayer.cpp"
        "src/RayTracer/Frame/Frame.cpp")
set(MAIN "main.cpp")

add_executable(raytracer ${MAIN} ${SRC})
find_package(SFML COMPONENTS graphics window system REQUIRED)
target_link_libraries(raytracer sfml-graphics sfml-window sfml-system)
target_link_libraries(raytracer ${CMAKE_DL_LIBS})
target_link_libraries(raytracer config++)
### TESTS ###

set(CMAKE_CXX_FLAGS "-ldl -Wall -Werror -Wextra -Wshadow -Wuninitialized --coverage -lcriterion")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

enable_testing()
set(TEST_SRC "tests/Maths/tests_vertex.cpp"
"tests/Maths/tests_vector.cpp"
"tests/Maths/tests_rect3D.cpp"
"tests/Maths/tests_ray.cpp"
"tests/RayTracer/Object/Shape/tests_sphere.cpp"
"tests/RayTracer/Object/Shape/tests_plane.cpp"
"tests/RayTracer/Frame/tests_frame.cpp"
"tests/RayTracer/Displayer/PPMDisplayer/tests_ppmdisplayer.cpp"
"tests/RayTracer/Object/Camera/tests_camera.cpp")

add_executable(tests_run ${TEST_SRC} ${SRC})
target_link_libraries(tests_run sfml-graphics sfml-window sfml-system)
target_link_libraries(tests_run ${CMAKE_DL_LIBS})
target_link_libraries(tests_run config++)

