#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer()
{
	window = nullptr;
	width = 0;
	height = 0;
}

OpenGLRenderer::~OpenGLRenderer()
{
	OnDestroy();
}

bool OpenGLRenderer::OnCreate(std::string name_, int width_, int height_)
{
	Debug::DebugInit();
	Debug::SetSeverity(MessageType::TYPE_INFO);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Debug::FatalError("Window failed to create", name_, __LINE__);
		return false;
	}

	width = width_;
	height = height_;

	window = SDL_CreateWindow(name_.c_str(), width_, height_);

	if (window == nullptr)
	{
		Debug::FatalError("Graphics failed to render", name_, __LINE__);
		return false;
	}

	context = SDL_GL_CreateContext(window);
	SetAttributes();

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		Debug::Error("Failed to initialize glewInt", name_, __LINE__);
		return false;
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_VIEWPORT);

	Debug::Info("Everything works", name_, __LINE__);

	return true;
}

bool OpenGLRenderer::OnDestroy()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;
}

void OpenGLRenderer::SetAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);

	glewExperimental = GL_TRUE;
}