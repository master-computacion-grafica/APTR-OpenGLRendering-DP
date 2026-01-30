// #pragma once
// #include "common.h"
//
// using namespace std;
//
// #define byte unsigned char
//
//
// typedef struct {
//     byte r;
//     byte g;
//     byte b;
//     byte a;
//
// }pixel_t;
//
// class GLTexture
// {
// public:
//     vector<pixel_t> rawImage;
//     int w;
//     int h;
//     string textureName;
//
//     GLuint GlTextID;
//
//     GLTexture(string fileName);
//
//     pixel_t& getPixel(int x, int y) { return rawImage[y * w + x]; };
//     
//     void updateTexture();
//
// };
//
