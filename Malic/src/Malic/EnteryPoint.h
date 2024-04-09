#pragma once

#ifdef MA_PLATFORM_WINDOWS

extern Malic::Application* Malic::CreateApplication();

int main(int argc, char** argv)
{

	auto app = Malic::CreateApplication();
	app->run();
	delete app;
}

#endif