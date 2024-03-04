#ifndef SHADER_HPP_
#define SHADER_HPP_

// @clang-format off
#include <GL/glew.h>
// @clang-format on
#include <SFML/OpenGL.hpp>
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <sstream>
#include <string>

/// @brief Shader class
class Shader {
private:
  /// @brief Enum of types VERTEX and FRAGMENT
  using ShaderType = enum SHADER_TYPE { VERTEX, FRAGMENT };
  /// @brief Enum for exceptions
  using Exception = enum EXCEPTION { COMPILE, LINK };
  /// @brief fragment shader
  GLuint fragmentShader;
  /// @brief vertex shader
  GLuint vertexShader;
  /// @brief program id
  GLuint id;

  /// @brief Loads shader from file 
  std::string loadShaderFromFile(const char *path);
  /// @brief Creates a shader
  /// @param path path to shader
  /// @param type shader type
  /// @return returns a non-zero value by which it can be referenced 
  GLuint createShader(const char *path, ShaderType type);
  /// @brief Creates a program
  /// @return returns a non-zero value by which it can be referenced
  GLuint createProgram();
  /// @brief Checks for exceptions in created program
  /// @param program program to be checked
  /// @param exceptionType exception type
  void checkForException(GLuint program, Exception exceptionType);

public:
  /// @brief Constructor
  /// @param vertexPath path to vertex shader
  /// @param fragmentPath path to fragment shader
  Shader(const char *vertexPath, const char *fragmentPath);
  /// @brief Constructor
  /// @param vertexPath path to vertex shader
  /// @param fragmentPath path to fragment shader
  Shader(const std::string vertexPath, const std::string fragmentPath);

  /// @brief Installs the program object specified by id as part of current rendering state
  void use();
  /// @brief Boolean setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param value Specifies the new values to be used for the specified uniform variable
  void setBool(const std::string name, bool value);
  /// @brief Integer setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param value Specifies the new values to be used for the specified uniform variable
  void setInt(const std::string name, int value);
  /// @brief Float setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param value Specifies the new values to be used for the specified uniform variable
  void setFloat(const std::string name, float value);
  /// @brief 2D vector setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param value Specifies a pointer to an array of count values that will be used to update the specified uniform variable
  void setVec2(const std::string name, const glm::vec2 &value);
  /// @brief 2D vector setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param x Specifies the new values to be used for the specified uniform variable
  /// @param y Specifies the new values to be used for the specified uniform variable
  void setVec2(const std::string name, float x, float y);
  /// @brief 3D vector setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param value Specifies a pointer to an array of count values that will be used to update the specified uniform variable
  void setVec3(const std::string name, const glm::vec3 &value);
  /// @brief 3D vector setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param x Specifies the new values to be used for the specified uniform variable
  /// @param y Specifies the new values to be used for the specified uniform variable
  /// @param z Specifies the new values to be used for the specified uniform variable
  void setVec3(const std::string name, float x, float y, float z);
  /// @brief 4D vector setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param value Specifies a pointer to an array of count values that will be used to update the specified uniform variable
  void setVec4(const std::string name, const glm::vec4 &value);
  /// @brief 4D vector setter
  /// @param name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param x Specifies the new values to be used for the specified uniform variable
  /// @param y Specifies the new values to be used for the specified uniform variable
  /// @param z Specifies the new values to be used for the specified uniform variable
  /// @param w Specifies the new values to be used for the specified uniform variable
  void setVec4(const std::string name, float x, float y, float z, float w);
  /// @brief 2x2 matrix setter
  /// @param name name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param mat Specifies a pointer to an array of count values that will be used to update the specified uniform variable
  void setMat2(const std::string name, const glm::mat2 &mat);
  /// @brief 3x3 matrix setter
  /// @param name name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param mat Specifies a pointer to an array of count values that will be used to update the specified uniform variable
  void setMat3(const std::string name, const glm::mat3 &mat);
  /// @brief 4x4 matrix setter
  /// @param name name Points to a null terminated string containing the name of the uniform variable whose location is to be queried
  /// @param mat Specifies a pointer to an array of count values that will be used to update the specified uniform variable
  void setMat4(const std::string name, const glm::mat4 &mat);
};

#endif // SHADER_HPP_
