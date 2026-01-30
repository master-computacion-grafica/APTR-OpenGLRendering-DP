// #include "GLTexture.h"
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
