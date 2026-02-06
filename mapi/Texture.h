#pragma once
#include "common.h"
#include "stb_image.h"

class Texture
{
protected:
    // ATTRIBUTES //
    static inline glm::uint32_t textureCounter = 0;
    
    glm::uint32_t textureID;
    //TODO: Esto esta bien?
    glm::ivec2<2, int> textureSize;
    
    bool cubeMap = false;
    
    bool bilinear = false;
    
    bool repeat = true;
    
    std::vector<unsigned char> textureBytes;
    
    std::string fileName;
public:
    
    // CONSTRUCTOR //
    
    Texture() {textureID = textureCounter++;}
    
    Texture(std::string fileName)
    {
        textureID = textureCounter++;
        load(fileName);
        
    }
    
    // METHODS //
    
    void load(std::string fileName)
    {
        this->fileName = fileName;
        int components = 0;
        textureBytes = stbi_load(fileName.c_str(), &textureSize[0], &textureSize[1], &components, 4);
    }
    
    virtual void update() = 0;
    
    // GETTERS & SETTERS
    
    glm::uint32_t getTextureID()
    {
        return textureID;
    }

    void setTextureID(glm::uint32_t textureID)
    {
        this->textureID = textureID;
    }

    glm::ivec2<2, int> getTextureSize()
    {
        return textureSize;
    }

    void setTextureSize(glm::ivec2 textureSize)
    {
        this->textureSize = textureSize;
    }

    bool isCubeMap()
    {
        return cubeMap;
    }

    void setCubeMap(bool cubeMap)
    {
        this->cubeMap = cube_map;
    }

    bool isBilinear()
    {
        return bilinear;
    }

    void setBilinear(bool bilinear)
    {
        this->bilinear = bilinear;
    }

    bool isRepeat()
    {
        return repeat;
    }

    void setRepeat(bool repeat)
    {
        this->repeat = repeat;
    }

    std::vector<unsigned char> getTextureBytes()
    {
        return textureBytes;
    }

    void setTextureBytes(std::vector<unsigned char> textureBytes)
    {
        this->textureBytes = textureBytes;
    }

    std::string getFileName()
    {
        return fileName;
    }

    void setFileName(std::string fileName)
    {
        this->fileName = fileName;
    }
};
