#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "GL/glew.h"
#include "shape.hpp"
#include "texture.hpp"

/// @brief Cube class
class Cube : public Shape {
  /// @brief shape's verticies vector
  static const std::vector<Vertex> s_verticies;
  /// @brief shape's indicies vector
  static const std::vector<GLuint> s_indicies;

public:
  /// @brief Constructor
  /// @param textureDiffuse The Diffuse lighting texture
  /// @param textureSpecular Thee Specular lighting texture
  Cube(Texture textureDiffuse = Texture{Texture::TextureType::diffuse},
       Texture textureSpecular = Texture{Texture::TextureType::specular});
};

#endif // CUBE_HPP_
