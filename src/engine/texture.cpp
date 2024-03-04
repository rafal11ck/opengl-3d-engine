#include "include/texture.hpp"
#include "log.hpp"
#include "resources.hpp"
#include <stb/stb_image.h>

const std::string Texture::defaultTexturePath{getResourcesPath() +
                                              "/textures/default.png"};

GLenum Texture::getTextureTypeUnit(const TextureType type) {
  switch (type) {
  case TextureType::diffuse:
    return GL_TEXTURE0;
    break;
  case TextureType::specular:
    return GL_TEXTURE1;
    break;
  default:
    LOGERROR << "TextureType not handled\n";
    std::abort();
  }
};

void Texture::bind() {
  glActiveTexture(getTextureTypeUnit(m_type));
  glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::unBind() {
  glActiveTexture(getTextureTypeUnit(m_type));
  glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::Texture(TextureType type, const std::string path) : m_type(type) {

  stbi_set_flip_vertically_on_load(true);

  glGenTextures(1, &m_id);

  bind();

  glBindTexture(GL_TEXTURE_2D, m_id);
  // set the texture wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // load image, create texture and generate mipmaps
  int width, height, nrChannels;
  unsigned char *data =
      stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

  if (data) {

    LOGINFO << path << " has " << nrChannels << " chanels\n";
    GLenum format;
    switch (nrChannels) {
    case 3:
      format = GL_RGB;
      break;
    case 4:
      format = GL_RGBA;
      break;
    default:
      LOGERROR << "Chanel count " << nrChannels << "is not handled ";
      std::abort();
      break;
    }

    // note that the awesomeface.png has transparency and thus an alpha
    // channel, so make sure to tell OpenGL the data type is  ? of GL_RGBA?
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    LOGERROR << "Failed to load texture from " << path << "\n";
  }
  stbi_image_free(data);
}
