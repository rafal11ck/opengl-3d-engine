#include "torus.hpp"
#include "log.hpp"
#include "shape.hpp"
#include "texture.hpp"
#include "vertex.hpp"
#include <vector>

const unsigned int Torus::s_defaultSidesCount{30};
const unsigned int Torus::s_defaultRingsCount{30};

std::vector<Vertex> Torus::generateVertices(float innerRadius,
                                            float outerRadius,
                                            unsigned int sides,
                                            unsigned int rings) {

  std::vector<Vertex> result{};

  float sideStep{2 * static_cast<float>(M_PI) / sides};
  float ringStep{2 * static_cast<float>(M_PI) / rings};

  for (int i = 0; i <= rings; ++i) {
    float theta{i * ringStep};

    for (int j = 0; j <= sides; ++j) {
      float phi{j * sideStep};

      float x{(outerRadius + innerRadius * static_cast<float>(cos(phi))) *
              static_cast<float>(cos(theta))};
      float y{(outerRadius + innerRadius * static_cast<float>(cos(phi))) *
              static_cast<float>(sin(theta))};
      float z{innerRadius * static_cast<float>(sin(phi))};

      glm::vec3 normal = glm::normalize(
          glm::vec3(cos(phi) * cos(theta), cos(phi) * sin(theta), sin(phi)));

      float u{static_cast<float>(j) / sides};
      float v{static_cast<float>(i) / rings};

      result.push_back(Vertex{glm::vec3(x, y, z), normal, glm::vec2(u, v)});
    }
  }
  return result;
}

Torus::indicies_t Torus::generateIndicies(unsigned int sides,
                                          unsigned int rings) {
  indicies_t result{};
  for (int i = 0; i < rings; ++i) {
    for (int j = 0; j < sides; ++j) {
      int first = (i * (sides + 1)) + j;
      int second = first + sides + 1;

      result.push_back(first);
      result.push_back(second);
      result.push_back(first + 1);

      result.push_back(second);
      result.push_back(second + 1);
      result.push_back(first + 1);
    }
  }
  return result;
}

Torus::Torus(float innerRadius, float outerRadius, Texture textureDiffuse,
             Texture textureSpecular, unsigned int sides, unsigned int rings)
    : Shape(generateVertices(innerRadius, outerRadius, sides, rings),
            generateIndicies(sides, rings), textureDiffuse, textureSpecular) {
  LOGTRACEN;
};
