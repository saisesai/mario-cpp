#include "Engine.h"
#include "Window.h"

#include <plog/Init.h>
#include <plog/Log.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Formatters/CsvFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>

Engine::Engine()
{
	// Initialize pLog
	plog::ColorConsoleAppender<plog::TxtFormatter> logConsleAppender;
	plog::RollingFileAppender<plog::CsvFormatter> logFileAppender("./log/engine.log", 0, 0);
	plog::init(plog::verbose, &logConsleAppender).addAppender(&logFileAppender);

	PLOG(plog::info) << "start engine";

	this->im = new InstanceManager();

	Window::GetInstance()->Run();
}

Engine::~Engine()
{
	delete this->im;
}