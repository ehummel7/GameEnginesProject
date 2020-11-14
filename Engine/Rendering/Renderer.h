#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <string>

enum class RendererType
{
	NONE,
	OPENGL
};

class Renderer
{
public:
	Renderer();
	Renderer();
	virtual SDL_Window SDL_CreateWindow(std::string name_, int width_, int height_) = 0;
	virtual bool OnCreate() = 0;
	virtual bool OnDestroy() = 0;
	virtual bool Render() = 0;
	RendererType getRendererType()
	{
		return rendererType;
	}
	void setRendererType(RendererType rendererType_)
	{
		rendererType = rendererType_;
	}
private:
	Renderer* renderer;
	RendererType rendererType;

};


#endif // !OPENGLRENDERER
