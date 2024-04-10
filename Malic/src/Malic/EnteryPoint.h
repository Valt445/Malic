#pragma once

#ifdef MA_PLATFORM_WINDOWS

extern Malic::Application* Malic::CreateApplication();

int main(int argc, char** argv)
{
	Malic::Log::Init();
	MA_CORE_WARN("hallo neice and nephew");
	MA_TRACE("fuiyoh uncle gordan make good fried rice");
	MA_CORE_INFO("HELLO");


	auto app = Malic::CreateApplication();
	app->run();
	delete app;
}

#endif