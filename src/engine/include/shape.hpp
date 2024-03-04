#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include "basicMesh.hpp"
#include "rotatable.hpp"
#include "scaleable.hpp"
#include "texture.hpp"

/// @brief Shape class
class Shape : public BasicMesh,
              public virtual Movable,
              public virtual Rotatable,
              public virtual Scalable {

public:
  /// @brief Constructor
  /// @param verticies The verticies of the shape
  /// @param indicies The indicies of the shape
  /// @param textureDiffuse The Texture for Diffuse Lighting
  /// @param textureSpecular The Texture for Specular Lighting
  Shape(verticies_t verticies, indicies_t indicies,
        Texture textureDiffuse = Texture{Texture::TextureType::diffuse},
        Texture textureSpecular = Texture{Texture::TextureType::specular}

  );

  /// @brief Model Matrix getter
  virtual glm::mat4 getModelMatrix() override;

  /// @brief Draws shader for the shape 
  virtual void draw(Shader &shader) override;

  /// @brief Destructor
  virtual ~Shape() override;

private:
  Texture m_textureDiffuse;
  Texture m_textureSpecular;
};

#endif // SHAPE_HPP_
