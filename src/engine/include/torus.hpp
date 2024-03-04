#ifndef TORUS_HPP_
#define TORUS_HPP_

#include "shape.hpp"
#include "texture.hpp"

/// @brief Torus class
class Torus : public Shape {
public:
  /// @brief Default amount of sides
  static const unsigned int s_defaultSidesCount;
  /// @brief Deefault amount of rings
  static const unsigned int s_defaultRingsCount;

  /// @brief Generates vertices for torus 
  static verticies_t generateVertices(float innerRadius, float outerRadius,
                                      unsigned int sides, unsigned int rings);

  /// @brief Generates indicies for torus
  static indicies_t generateIndicies(unsigned int sides, unsigned int rings);

private:
  /// @brief The outer radius
  float m_outerRadius;
  /// @brief The inner radius
  float m_innerRadius;

public:
  /// @brief Constructor 
  Torus(float innerRadius = 1.f, float outerRadius = 2.f,
        Texture textureDiffuse = Texture{Texture::TextureType::diffuse},
        Texture textureSpecular = Texture{Texture::TextureType::specular},
        unsigned int sides = s_defaultSidesCount,
        unsigned int rings = s_defaultSidesCount);
};

#endif // TORUS_HPP_
