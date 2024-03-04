#include "include/sphere.hpp"
#include "log.hpp"
#include "shape.hpp"

#include <GL/glew.h>
#include <vector>

unsigned int Sphere::defaultSectorCount{30};
unsigned int Sphere::defaultStackCount{30};

std::vector<Vertex> Sphere::generateVerticies(float radius,
                                              unsigned int sectorCount,
                                              unsigned int stackCount) {
  std::vector<Vertex> result{};

  GLfloat sectorStep = 2 * M_PI / static_cast<GLfloat>(sectorCount);
  GLfloat stackStep = M_PI / static_cast<GLfloat>(stackCount);
  GLfloat sectorAngle, stackAngle;

  Vertex vertex;
  for (GLuint i = 0; i <= stackCount; ++i) {
    stackAngle = M_PI / 2 - i * stackStep;

    GLfloat z, xy;
    xy = radius * cosf(stackAngle);
    z = radius * sinf(stackAngle);

    for (GLuint j = 0; j <= sectorCount; ++j) {
      sectorAngle = j * sectorStep;

      GLfloat x{xy * cosf(sectorAngle)};
      GLfloat y{xy * sinf(sectorAngle)};
      vertex.m_position = glm::vec3(x, y, z);

      GLfloat lengthInv = 1.0f / radius;
      GLfloat nx{x * lengthInv};
      GLfloat ny{y * lengthInv};
      GLfloat nz{z * lengthInv};
      vertex.m_normal = glm::vec3(nx, ny, nz);

      GLfloat s = (GLfloat)j / sectorCount;
      GLfloat t = (GLfloat)i / stackCount;
      vertex.m_texCord = glm::vec2(s, t);

      result.push_back(vertex);
    }
  }
  return result;
}

std::vector<GLuint> Sphere::generateIndicies(float radius,
                                             unsigned int sectorCount,
                                             unsigned int stackCount) {
  std::vector<GLuint> result{};
  for (GLuint i = 0; i < stackCount; i++) {
    GLuint k1{i * (sectorCount + 1)};
    GLuint k2{k1 + sectorCount + 1};

    for (GLuint j = 0; j < sectorCount; j++, k1++, k2++) {
      if (i != 0) {
        result.push_back(k1);
        result.push_back(k2);
        result.push_back(k1 + 1);
      }

      if (i != (stackCount - 1)) {
        result.push_back(k1 + 1);
        result.push_back(k2);
        result.push_back(k2 + 1);
      }
    }
  }
  return result;
}

Sphere::Sphere(float radius, Texture textureDiffuse, Texture textureSpecular,
               unsigned int sectorCount, unsigned int stackCount)
    : Shape(generateVerticies(radius, sectorCount, stackCount),
            generateIndicies(radius, sectorCount, stackCount), textureDiffuse,
            textureSpecular),
      m_radius(radius) {
  LOGTRACEN;
};
