/**
 *@file
 *@brief engine usage example.
 **/

#include "engine.hpp"

/// engine reference
Engine &engine{Engine::getInstance()};

int main() {

  /// activate loop
  engine.loop();
}
