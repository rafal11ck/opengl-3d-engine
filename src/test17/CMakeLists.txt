
FetchContent_Declare(
  freetype
  GIT_REPOSITORY https://gitlab.freedesktop.org/freetype/freetype.git
  GIT_TAG master)
FetchContent_MakeAvailable(freetype)


add_executable(test17 main.cpp)
target_link_libraries(test17 engine freetype)
