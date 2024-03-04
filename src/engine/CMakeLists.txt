
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include(FetchContent)

# sfml
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

# glm
# System has to have GLM installed
find_package(glm REQUIRED)

# stb
# System has to have STB installed
include_directories(/usr/include/stb REQUIRED)

# file(COPY resources DESTINATION resources)

include_directories(include)
include_directories(${GLM_INCLUDE_DIRS})

add_library(engine
basicMesh.cpp
camera.cpp
cube.cpp
drawable.cpp
elementBuffer.cpp
engine.cpp
include/basicMesh.hpp
include/camera.hpp
include/cube.hpp
include/drawable.hpp
include/elementBuffer.hpp
include/engine.hpp
include/light.hpp
include/log.hpp
include/moveable.hpp
include/resources.hpp
include/rotatable.hpp
include/scaleable.hpp
include/shader.hpp
include/shape.hpp
include/sphere.hpp
include/texture.hpp
include/torus.hpp
include/transformable.hpp
include/vertex.hpp
include/vertexArray.hpp
include/vertexBuffer.hpp
light.cpp
log.cpp
moveable.cpp
rotatable.cpp
scaleable.cpp
shader.cpp
shape.cpp
sphere.cpp
stb_image.cpp
texture.cpp
torus.cpp
transformable.cpp
vertexArray.cpp
vertexBuffer.cpp
${CMAKE_BINARY_DIR}/generated/resources.cpp
)

target_link_libraries(engine ${OPENGL_gl_LIBRARY})
target_link_libraries(engine glm)
target_link_libraries(engine ${GLEW_LIBRARIES})
target_link_libraries(engine sfml-graphics)
