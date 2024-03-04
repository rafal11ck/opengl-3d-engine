#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "cube.hpp"
#include "moveable.hpp"
#include "shader.hpp"
#include <glm/glm.hpp>

/// @brief Light class
class Light : public Movable {
private:
  /// @brief Ambient light vector
  glm::vec3 ambient{0};
  /// @brief Diffuse light vector
  glm::vec3 diffuse{0};
  /// @brief Specular light vector
  glm::vec3 specular{0};

public:
  /// @brief Constructor
  Light();
  /// @brief Destructor
  ~Light();

  /// @brief Ambient setter by vector
  void setAmbient(glm::vec3 ambient);
  /// @brief Diffuse setter by vector
  void setDiffuse(glm::vec3 diffuse);
  /// @brief Specular setter by vector
  void setSpecular(glm::vec3 specular);
  /// @brief Ambient setter by values
  void setAmbient(GLfloat r, GLfloat g, GLfloat b);
  /// @brief Diffuse setter by values
  void setDiffuse(GLfloat r, GLfloat g, GLfloat b);
  /// @brief Specular setter by values
  void setSpecular(GLfloat r, GLfloat g, GLfloat b);

  /// @brief Ambient getter
  glm::vec3 getAmbient() const;
  /// @brief Diffuse getter
  glm::vec3 getDiffuse() const;
  /// @brief Specular getter
  glm::vec3 getSpecular() const;

  /**
   *@brief Sets shader uniforms to data from this light
   **/
  void update(Shader &shader, int index) const;
};

#endif // LIGHT_HPP_
