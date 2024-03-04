#ifndef TRANSFORMABLE_HPP_
#define TRANSFORMABLE_HPP_

#include <glm/glm.hpp>

/**
 *@brief Enables to do transformations used as model matrix.
 **/
class Transformable {
protected:
  /**
   *@brief Model matrix.
   **/
  // glm::vec4 m_model{1.0f};

  /// @brief Pure virtual Model Matrix getter 
  virtual glm::mat4 getModelMatrix() = 0;
  /// @brief Pure virtual Destructor
  virtual ~Transformable() = 0;
};

#endif // TRANSFORMABLE_HPP_
