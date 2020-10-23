#ifndef SPRITESURFACE_H
#define SPRITESURFACE_H

#include <glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include "../../Core/Camera/Camera.h"
#include "../../Core/Graphics/TextureHandler.h"

struct Vertex {
	glm::vec2 position;
	glm::vec2 textureCoordinates;
};

class SpriteSurface
{
public:
	SpriteSurface(std::string name_, float scale_, float angle_, glm::vec4 tintColour_);
	~SpriteSurface();
	void Draw(Camera* camera_, std::vector<glm::vec2> postion_);
	int getWidth();
	int getHeight();
private:
	void GenerateBuffers();
	float width, height, angle;
	GLuint shaderProgram;
	GLuint VAO, VBO;
	GLuint textureID;
	GLuint modelLoc, projLoc, tintColour, textureLoc;
	std::string name;
	glm::vec2 scale;
	std::vector<Vertex> vertexList;
};
#endif 