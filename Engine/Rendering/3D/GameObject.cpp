#include "GameObject.h"

GameObject::GameObject(Model* model_) : model(nullptr), tag(""), hit(false)
{
	model = model_;
	position = glm::vec3();
	angle = 0.0f;
	rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	scale = glm::vec3(1.0f);

	if (model)
	{
		modelInstance = model->CreateInstance(position, angle, rotation, scale);
	}
}

GameObject::GameObject(Model* model_, glm::vec3 position_) : model(nullptr), tag(""), hit(false)
{
	model = model_;
	position = position_;
	angle = 0.0f;
	rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	scale = glm::vec3(1.0f);

	if (model)
	{
		modelInstance = model->CreateInstance(position, angle, rotation, scale);
		boundingbox = model->GetBoundingBox();
		boundingbox.transform = model->GetTransform(modelInstance);
	}
}

GameObject::~GameObject()
{
	OnDestroy();
}

void GameObject::Update(const float deltaTime_)
{
	SetAngle(angle + 0.005f);
	
	GameObject::Update(deltaTime_);
}

void GameObject::Render(Camera* camera_)
{
	if (model)
	{
		model->Render(camera_);
	}
}

void GameObject::OnDestroy()
{
	model = nullptr;

	component.clear();
}

glm::vec3 GameObject::GetPosition() const
{
	return position;
}

float GameObject::GetAngle() const
{
	return angle;
}

glm::vec3 GameObject::GetRotation() const
{
	return rotation;
}

glm::vec3 GameObject::GetScale() const
{
	return scale;
}

std::string GameObject::GetTag() const
{
	return tag;
}

bool GameObject::GetHit() const
{
	return hit;
}

void GameObject::SetPosition(glm::vec3 position_)
{
	position = position_;

	if (model)
	{
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingbox.transform = model->GetTransform(modelInstance);

	}
}

void GameObject::SetAngle(float angle_)
{
	angle = angle_;

	if (model)
	{
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingbox.transform = model->GetTransform(modelInstance);
	}
}

void GameObject::SetRotation(glm::vec3 rotation_)
{
	rotation = rotation_;

	if (model)
	{
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingbox.transform = model->GetTransform(modelInstance);
	}
}

void GameObject::SetScale(glm::vec3 scale_)
{
	scale = scale_;

	if (model)
	{
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingbox.transform = model->GetTransform(modelInstance);
		boundingbox.minVert *= scale.x > 1.0f ? scale : (scale / 2.0f);
		boundingbox.maxVert *= scale.x > 1.0f ? scale : (scale / 2.0f);
	}
}

void GameObject::SetTag(std::string tag_)
{
	tag = tag_;
}

void GameObject::SetHit(bool hit_, int buttonType_)
{
	hit = hit_;
	std::cout << "Hit: " << tag << std::endl;
}

BoundingBox GameObject::GetBoundingBox() const
{
	return boundingbox;
}