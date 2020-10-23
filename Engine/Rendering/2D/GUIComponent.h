#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include <glew.h>
#include <glm/glm.hpp>
#include <string>
#include "../../Core/Camera/Camera.h"

class GUIComponent
{
public:
	inline GUIComponent() {

	}
	virtual inline ~GUIComponent() {

	}
	virtual void Draw(Camera* camera_, glm::vec2 position_) = 0;
	virtual void FindContainingPoint() = 0;
	virtual bool OnCreate(std::string imageName_, glm::vec2 offset_, glm::vec2 guiScale_, float guiAngle_, glm::vec4 guiTint_) = 0;
};

#endif