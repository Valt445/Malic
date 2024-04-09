#pragma once

#include "Core.h"

namespace Malic
{
	class MALIC_API Application
	{

	public:
		Application();
		virtual ~Application();

		void run();

	};

	//to be defined in client
	Application* CreateApplication();
}



