#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"
#include "Component.h"

class GameObject
{
public:
	GameObject(Model* model_);
	GameObject(Model* model_, glm::vec3 position_);
	~GameObject();

	void Update(const float deltaTime_);
	void Render(Camera* camera_);
	void OnDestroy();

	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;

	std::string GetTag() const;
	bool GetHit() const;

	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);

	BoundingBox GetBoundingBox() const;

	template<typename T>
	void AddComponent()
	{
		T* temp = new T();
		if (dynamic_cast<Component*>(temp)) {
			if (GetComponent<T>()) {
				Debug::Error("Component already exists", "GameObject.cpp", __LINE__);
				delete temp;
				return;
			}
			else if (GetComponent<T>() == nullptr) {
				component.push_back(temp);
				temp->OnCreate(this);
			}
		}

		else {
			Debug::Error("New object is not a child of component base class", "GameObject.cpp", __LINE__);
			delete temp;
			return;
		}
	}

	template<typename G>
	G* GetComponent() {
		for (auto c : component) {
			if (dynamic_cast<G*>(c)) {
				return dynamic_cast<G*>(c);
			}
		}
	}

	template<typename R>
	void RemoveComponent() {
		for (int i = 0; i < 5; i++) {
			if (dynamic_cast<R*>(i)) {
				component = nullptr;
				component.erase(component.begin() + i);
			}
		}
	}


private:
	int modelInstance;
	Model* model;

	std::vector<Component*> component;

	glm::vec3 position;
	float angle;
	glm::vec3 rotation;
	glm::vec3 scale;
	
	BoundingBox boundingbox;

	std::string tag;

	bool hit;

};

#endif