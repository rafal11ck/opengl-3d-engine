/**
 *@file
 *@brief Rendering text
 **/
#include <freetype2/ft2build.h>

#include FT_FREETYPE_H
#include <freetype2/freetype/freetype.h>

#include "engine.hpp"

/// engine reference
Engine &engine{Engine::getInstance()};

int main() {

  Shader shader{Shader("text_vs.glsl", "text_f.glsl")};

  FT_Library ft;
  if (FT_Init_FreeType(&ft)) {
    std::cout << "ERROR::FREETYPE: Could not init FreeType Library"
              << std::endl;
    return -1;
  }

  FT_Face face;
  if (FT_New_Face(ft, "font.ttf", 0, &face)) {
    std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
    return -1;
  }

  /// activate loop
  engine.loop();
}
