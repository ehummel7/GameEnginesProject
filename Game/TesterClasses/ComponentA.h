#ifndef COMPONENTA_H
#define COMPONENTA_H

#include "../../Engine/Core/CoreEngine.h"

class GameObject;
class ComponentA
{
public:
	ComponentA();
	virtual ~ComponentA();

	bool OnCreate(GameObject* parent_);
	void Update(float deltaTime_);


protected:
	GameObject* parent;
};

#endif