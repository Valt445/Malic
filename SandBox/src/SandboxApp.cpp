#include <Malic.h>

class Sandbox : public Malic::Application
{
public:
	Sandbox()
		{

		}
	
	~Sandbox()
	{

	}
};

Malic::Application* Malic::CreateApplication()
{
	return new Sandbox();
}