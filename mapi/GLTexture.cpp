#include "GLTexture.h"

void GLTexture::update()
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
            //TODO: Esto esta bien?
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureSize[0], textureSize[1], 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
            //Generar mipmaps
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        
        //Liberar datos de CPU
        stbi_image_free(textureBytes.data());
    }
    else
    {
        std::cout << "Error loading texture" << std::endl;
    }
}

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"
//
//
// GLTexture::GLTexture(string fileName): textureName(fileName)
// {
//     //cargar imagen de fichero
//     int componentes = 0;
//
//     unsigned char* data = stbi_load(textureName.c_str(), &w, &h, &componentes, 4);
//     if(data){
//         rawImage.resize(w * h);
//         memcpy(rawImage.data(), data, w * h * 4);
//     //cargar imagen en GPU
//         //generar id de textura de OPENGL
//         glGenTextures(1, &GlTextID);
//         glBindTexture(GL_TEXTURE_2D, GlTextID);
//         //activar filtros
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//filtros
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//         //configurar uso
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//         //cargar en GPU datos de textura
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, rawImage.data());
//         //generar mipmaps
//         glGenerateMipmap(GL_TEXTURE_2D);
//      //liberar datos de cpu
//         stbi_image_free(data);
//     }
//     else {
//         cout << "ERROR: Fichero " << fileName << " no encontrado\n";
//     }
// }
//
// void GLTexture::updateTexture()
// {
//     glBindTexture(GL_TEXTURE_2D, GlTextID);
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, rawImage.data());
//
// }