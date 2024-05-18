/**
 *@file
 *@brief Rendering text
 **/
#include "engine.hpp"
#include <format>

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

  sf::Clock cl{};
  engine.setLoopFunction([&]() {
    // Begin text drawing (this for instance calls glUseProgram)
    gltBeginDraw();

    const float time{cl.getElapsedTime().asSeconds()};

    std::string textdata{"Hello World! " + std::format("{:.2f}", time)};

    gltSetText(text, textdata.c_str());

    // Draw any amount of text between begin and end
    gltColor(1.0f, 1.0f, 1.0f, 1.0f);
    const auto size{engine.getWindow().getSize()};
    gltDrawText2DAligned(text, size.x / 2.0, size.y / 2.0, 4, GLT_CENTER,
                         GLT_CENTER);

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
