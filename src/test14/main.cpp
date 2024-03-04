
/**
 *@file
 *@brief Primitives example.
 **/

#include "cube.hpp"
#include "engine.hpp"
#include "light.hpp"
#include "sphere.hpp"
#include "torus.hpp"

/// engine reference
Engine &engine{Engine::getInstance()};

int main() {
  /// Set ProjectionType perspective so that it looks natural.
  engine.setProjectionType(Engine::ProjectionType::perspective);

  // Enable wireframe mode so that shapes can be noticed
  engine.setWireframeMode(true);

  /// Instanitate Cube
  Cube *cube{new Cube{}};
  // Set Cube position
  cube->setPosition(0, 0, -10);
  /// Add cube to engine
  engine.addDrawable(cube);

  /// Add Sphere
  Sphere *sphere{new Sphere{}};
  sphere->setPosition(-3, 0, -10);
  engine.addDrawable(sphere);

  /// Add torus
  Torus *torus{new Torus{}};
  torus->setScale(0.5);
  torus->setPosition(3, 0, -10);
  engine.addDrawable(torus);

  /// activate loop
  engine.loop();
}
