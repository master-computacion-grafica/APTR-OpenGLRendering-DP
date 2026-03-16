#include "GLTexture.h"

void GLTexture::setupGLTexture()
{
    if (!textureBytes.empty())
    {
        //Cargar imagen en CPU
        //Generar id de TEXTURA en OPENGL
        glGenTextures(1, &glTextureID);
        if (isCubeMap())
        {
            std::cout << "Cubemaps not implemented yet" << std::endl;
            glBindTexture(GL_TEXTURE_CUBE_MAP, glTextureID);
        }
        else
        {
            glBindTexture(GL_TEXTURE_2D, glTextureID); //Las siguientes instrucciones afectan a la textura bindeada
            if (isBilinear())
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);                
            }
            else
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            }
            if (isRepeat())
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            }
            else
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            }
            
            //Cargar en GPU datos de textura
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureSize.x, textureSize.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureBytes.data());
            //Generar mipmaps
            glGenerateMipmap(GL_TEXTURE_2D);
        }
    }
    else
    {
        std::cout << "Error loading texture" << std::endl;
    }
}

void GLTexture::update()
{
    glBindTexture(GL_TEXTURE_2D, glTextureID); //Las siguientes instrucciones afectan a la textura bindeada
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureSize.x, textureSize.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureBytes.data());
}