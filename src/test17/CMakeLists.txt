
FetchContent_Declare(
    gl_text
    GIT_REPOSITORY https://github.com/vallentin/glText.git
    GIT_TAG        master
)

FetchContent_GetProperties(gl_text)
if(NOT gl_text_POPULATED)
    FetchContent_Populate(gl_text)
    add_library(gl_text INTERFACE)
    target_include_directories(gl_text INTERFACE ${gl_text_SOURCE_DIR})
endif()


set(CMAKE_CXX_STANDARD_REQUIRED 23)
set(CMAKE_CXX_STANDARD 23)
add_executable(test17 main.cpp gl_text.cpp)
target_link_libraries(test17 engine gl_text)
