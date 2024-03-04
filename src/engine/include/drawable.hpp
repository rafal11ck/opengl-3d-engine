#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include "log.hpp"
#include "shader.hpp"

/**
 *@brief Indicates that object is drawable.
 **/
class Drawable {

  /// @brief Shininess of drawable
  float shininess;

public:
  /// @brief Virtual method to draw a drawable
  /// @param shader Shader for the drawable
  virtual void draw(Shader &shader) = 0;

  /// @brief Destructor
  virtual ~Drawable() = 0;
};

#endif // DRAWABLE_HPP_
