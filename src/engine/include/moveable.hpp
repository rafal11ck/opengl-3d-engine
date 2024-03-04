#ifndef MOVEABLE_HPP_
#define MOVEABLE_HPP_

#include "transformable.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>

/// @brief Indicates that object is moveable
class Movable : virtual public Transformable {
private:
  /// @brief Position vector
  glm::vec3 m_position{};

public:
  /// @brief Position setter by values 
  void setPosition(GLfloat x, GLfloat y, GLfloat z);
  /// @brief Position setter by vector
  void setPosition(glm::vec3 position);
  /// @brief Position getter 
  glm::vec3 getPosition() const;

  /// @brief Model Matrix getter 
  virtual glm::mat4 getModelMatrix() override;

  /// @brief Destructor
  virtual ~Movable() = 0;
};

;

#endif // MOVEABLE_HPP_
