#pragma once

#ifdef MA_PLATFORM_WINDOWS

extern Malic::Application* Malic::CreateApplication();

int main(int argc, char** argv)
{
	Malic::Log::Init();
	MA_TRACE("haiyaa uncle joshua make good fried rice");

	auto app = Malic::CreateApplication();
	app->run();
	delete app;
}

#endif