
/**
 *@file
 *@brief Test setting textures.
 **/

#include "resources.hpp"
#include "texture.hpp"
#include "vertex.hpp"
#include <glm/fwd.hpp>
#define TRACE
#include "log.hpp"

#include "engine.hpp"
#include "shape.hpp"
#include <vector>

Engine &engine{Engine::getInstance()};

std::vector<Vertex> verticies{
    Vertex{glm::vec3{1.f, 1.f, 0.0f}, glm::vec3{0.f}, {1.f, 1.f}}, // top right
    Vertex{glm::vec3{1.f, -1.f, 0.0f},
           glm::vec3{0.f},
           {1.f, -0.f}}, // bottom right
    Vertex{glm::vec3{-1.f, -1.f, 0.0f},
           glm::vec3{0.f},
           {0.f, -0.f}}, // bottom left
    Vertex{glm::vec3{-1.f, 1.f, 0.0f}, glm::vec3{0.f}, {0.f, 1.f}} // top left
};

std::vector<GLuint> indicies{0, 1, 3, 1, 2, 3};

int main() {
  engine.setMaxFps(75);
  // engine.setProjectionType(Engine::ProjectionType::perspective);

  Shape *rectangle =
      new Shape{verticies, indicies,
                Texture{Texture::TextureType::diffuse,
                        getResourcesPath() + "/textures/eureka.png"}};

  // move it so it won't be clipped.
  rectangle->setPosition(0.5, 0, -1);
  rectangle->setScale(0.5);
  engine.addDrawable(rectangle);

  Shape *box =
      new Shape{verticies, indicies,
                Texture{Texture::TextureType::diffuse,
                        getResourcesPath() + "/textures/container.png"},
                Texture{Texture::TextureType::specular,
                        getResourcesPath() + "/textures/eureka.png"}};

  box->setPosition(-0.5, 0, -1);
  box->setScale(0.5);
  engine.addDrawable(box);

  engine.setLoopFunction([&]() {
    static constexpr float angleSpeed{60};
    const float rotation{
        glm::radians(angleSpeed * engine.getLastFrameDuration().asSeconds())};

    rectangle->rotate(rotation, {0, 1, 0});
    box->rotate(rotation, {1, 0, 0});
  });

  engine.loop();

  delete rectangle;
}
