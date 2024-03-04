
/**
 *@file
 *@brief Light example.
 **/

#include "engine.hpp"
#include "sphere.hpp"
#include "torus.hpp"
#include <cmath>
#include <glm/fwd.hpp>
#include <glm/trigonometric.hpp>

/// engine reference
Engine &engine{Engine::getInstance()};

constexpr float rotateSpeed{10};
constexpr glm::vec3 rotationAxis{0, 1, 1};
constexpr float lightDistance{2};

int main() {
  /// Set ProjectionType perspective so that it looks natural.
  engine.setProjectionType(Engine::ProjectionType::perspective);

  /// Enable keyboard movement
  engine.setCameraHandlingKeyboard(true);

  /// Add light to engine that is full ambient light so that textures are
  /// visible
  Light *light{new Light{}};
  light->setAmbient(glm::vec3{0.2});
  constexpr glm::vec3 lightColor{0.3, 0.3, 0.01};
  light->setSpecular(lightColor);
  light->setDiffuse(lightColor);
  // move light up
  light->setPosition(0, 1, 0);
  engine.addLight(light);

  Shape *sun{new Torus{}};
  engine.addDrawable(sun);
  sun->setScale(0.1);

  // Add another cube with another texture
  Shape *ball{new Sphere{}};

  // flip the cube
  ball->rotate(glm::radians(90.f), {1, 0, 0});
  ball->setPosition(0, 0, -10);
  engine.addDrawable(ball);

  // Rotate the cubes
  engine.setLoopFunction([&]() {
    static float time{};
    float dt{engine.getLastFrameDuration().asSeconds()};

    time += dt;
    if (time > 2 * M_PI) {
      time -= 2 * M_PI;
    }

    float x{static_cast<float>(sin(time) * lightDistance)};
    float z{static_cast<float>(cos(time) * lightDistance)};

    sun->setPosition(glm::vec3{0, 0, -10} + glm::vec3{x, 0, z});
    light->setPosition(glm::vec3{0, 0, -10} + glm::vec3{x, 0, z});

    sun->rotate(rotateSpeed * dt, rotationAxis);

    // ball->rotate(glm::radians(cubeRotateSpeed * dt), cubeRotationAxis);
    //
  });

  /// activate loop
  engine.loop();
}
