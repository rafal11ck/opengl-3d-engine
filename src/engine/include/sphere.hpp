#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "shape.hpp"
#include "texture.hpp"
#include "vertex.hpp"
#include <GL/glew.h>

/// @brief Sphere class
class Sphere : public Shape {
  /// @brief Amount of sectors
  static unsigned int defaultSectorCount;
  /// @brief Amount of stacks of sectors
  static unsigned int defaultStackCount;

public:
  /// @brief Generates verticies for the sphere
  static std::vector<Vertex> generateVerticies(float radius,
                                               unsigned int sectorCount,
                                               unsigned int stackCount);
  /// @brief Generates indicies for the sphere
  static std::vector<GLuint> generateIndicies(float radius,
                                              unsigned int sectorCount,
                                              unsigned int stackCount);

  /// @brief Constructor
  Sphere(float radius = 1,
         Texture textureDiffuse = Texture{Texture::TextureType::diffuse},
         Texture textureSpecular = Texture{Texture::TextureType::specular},
         unsigned int sectorCount = defaultSectorCount,
         unsigned int stackCount = defaultStackCount);

private:
  /// @brief Radius of the sphere
  float m_radius;
};

#endif // SPHERE_HPP_
