/**
 *@file
 *@brief Textures example.
 **/

#include "cube.hpp"
#include "engine.hpp"

/// engine reference
Engine &engine{Engine::getInstance()};

int main() {
  /// Set ProjectionType perspective so that it looks natural.
  engine.setProjectionType(Engine::ProjectionType::perspective);

  /// Add light to engine that is full ambient light so that textures are
  /// visible
  Light *light{new Light{}};
  light->setAmbient(glm::vec3{1});
  engine.addLight(light);

  /// Instanitate Cube with diffuse light texture
  Cube *cube{new Cube{Texture{Texture::TextureType::diffuse,
                              getResourcesPath() + "textures/container.png"}}};
  // Set Cube position
  cube->setPosition(-2, 0, -10);
  /// Add cube to engine
  engine.addDrawable(cube);

  // Add another cube with another texture
  Cube *cube2{new Cube{Texture{Texture::TextureType::diffuse,
                               getResourcesPath() + "textures/eureka.png"}}};
  // flip the cube
  cube2->rotate(glm::radians(90.f), {1, 0, 0});
  cube2->setPosition(2, 0, -10);
  engine.addDrawable(cube2);

  /// activate loop
  engine.loop();
}
