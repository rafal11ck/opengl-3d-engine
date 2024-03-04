#ifndef SCALEABLE_HPP_
#define SCALEABLE_HPP_

#include "transformable.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>

/// @brief Indicates that object is transformable
class Scalable : virtual public Transformable {
  /// @brief Scale vector
  glm::vec3 m_scale{1.f};

public:
  /**
   *@brief Set scale factor on all axises */
  void setScale(GLfloat scaleFactor);

  /**
   *  @brief Set scale on respiective axises.
   *  @param x Scale factor of x axis.
   *  @param y Scale factor of y axis.
   *  @param z Scale factor of z axis.
   *  */
  void setScale(GLfloat x, GLfloat y, GLfloat z);

  /**
   *@brief Set scale on respiective axises.
   *@param scale Scale factor
   **/
  void setScale(glm::vec3 scale);

  /// @brief Scale getter 
  glm::vec3 getScale() const;

  /// @brief Destructor
  virtual ~Scalable() = 0;
};

#endif // SCALEABLE_HPP_
