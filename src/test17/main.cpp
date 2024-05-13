/**
 *@file
 *@brief Rendering text
 **/
#include "engine.hpp"

// #define GLT_MANUAL_VIEWPORT
#define GLT_IMPLEMENTATION
#include "gltext.h"

/// engine reference
Engine &engine{Engine::getInstance()};

int main() {
  // Initialize glText
  gltInit();

  // Creating text
  GLTtext *text = gltCreateText();
  gltSetText(text, "Hello World!");

  engine.setLoopFunction([&]() {
    // Begin text drawing (this for instance calls glUseProgram)
    gltBeginDraw();

    // Draw any amount of text between begin and end
    gltColor(1.0f, 1.0f, 1.0f, 1.0f);
    gltDrawText2D(text, 40, 40, 1.0);

    // Finish drawing text
    gltEndDraw();
  });
  /// activate loop
  engine.loop();

  // Deleting text
  gltDeleteText(text);

  // Destroy glText
  gltTerminate();
}
