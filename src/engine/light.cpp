#include "include/light.hpp"
#include "log.hpp"

Light::Light() {}

Light::~Light() {}

void Light::setAmbient(glm::vec3 ambient) { this->ambient = ambient; }

void Light::setDiffuse(glm::vec3 diffuse) { this->diffuse = diffuse; }

void Light::setSpecular(glm::vec3 specular) { this->specular = specular; }

void Light::setAmbient(GLfloat r, GLfloat g, GLfloat b) {
  this->ambient = glm::vec3(r, g, b);
}

void Light::setDiffuse(GLfloat r, GLfloat g, GLfloat b) {
  this->diffuse = glm::vec3(r, g, b);
}

void Light::setSpecular(GLfloat r, GLfloat g, GLfloat b) {
  this->specular = glm::vec3(r, g, b);
}

glm::vec3 Light::getAmbient() const { return this->ambient; }

glm::vec3 Light::getDiffuse() const { return this->diffuse; }

glm::vec3 Light::getSpecular() const { return this->specular; }

void Light::update(Shader &shader, int index) const {
  if (index >= 8 || index < 0) {
    LOGERROR
        << "SHADER ERROR "
        << "Light index out of range. This value should be between 0 and 7."
        << "Passed " << index << '\n';
    return;
  }

  std::string lightName = "light[" + std::to_string(index) + "]";

  shader.use();
  shader.setVec3(lightName + ".position", getPosition());
  shader.setVec3(lightName + ".ambient", getAmbient());
  shader.setVec3(lightName + ".diffuse", getDiffuse());
  shader.setVec3(lightName + ".specular", getSpecular());
}
