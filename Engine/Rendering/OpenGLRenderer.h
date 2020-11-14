#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <string>
#include <iostream>
#include "../Core/Debug.h"
#include "Renderer.h"

class OpenGLRenderer : public Renderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	virtual bool OnCreate(std::string name_, int width_, int height_);
	virtual bool OnDestroy();

private:
	void SetAttributes();
	int width;
	int height;
	SDL_Window* window;
	SDL_GLContext context;
	
};


#endif // !OPENGLRENDERER
