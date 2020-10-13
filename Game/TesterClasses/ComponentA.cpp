#include "ComponentA.h"

ComponentA::ComponentA()
{

}

ComponentA::~ComponentA()
{

}

bool ComponentA::OnCreate(GameObject* parent_)
{
	parent = parent_;
	return true;
}

void ComponentA::Update(float deltaTime_)
{
	std::cout << "Updating component A" << std::endl;
}