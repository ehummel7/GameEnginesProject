#ifndef GUIIMAGECOMPONENT_H
#define GUIIMAGECOMPONENT_H

#include <glew.h>
#include <glm/glm.hpp>
#include <string>
#include "../../Core/Camera/Camera.h"
#include "GUIObject.h"
#include "SpriteSurface.h"
#include "GUIComponent.h"

class GUIImageComponent : public GUIComponent
{
public:
    GUIImageComponent();
    virtual ~GUIImageComponent();
    virtual bool OnCreate(std::string name_, glm::vec2 offset_, glm::vec2 scale_, float angle_, glm::vec4 tintColour_);
    virtual void Draw(Camera* camera_, glm::vec2 position_);
    virtual void FindContainingPoint(glm::vec2 point_);

private:

    SpriteSurface* sprite;
    glm::vec2 offset;
};


#endif // !GUIIMAGECOMPONENT_H