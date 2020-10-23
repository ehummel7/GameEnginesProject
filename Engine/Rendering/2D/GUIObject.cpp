#include "GUIObject.h"

GUIObject::GUIObject(glm::vec2 position_) {
	position = position_;
}

GUIObject::~GUIObject() {

}

void GUIObject::Draw(Camera* camera_) {
	for (int i = 0; i < container.size(); i++)
	{
		container[i].Draw(camera_);
	}
}

void GUIObject::SetTag(std::string tag_) {
	tag = tag_;
}