workspace "Malic"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Malic"
	location "Malic"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"

	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MA_BUILD_DLL",
			"MA_PLATFORM_WINDOWS"

		}

		postbuildcommands 
		{
			"copy /B /Y ..\\bin\\" .. outputdir .. "\\Malic\\Malic.dll ..\\bin\\" .. outputdir .. "\\Sandbox\\ > nul"
		}		

	filter "configurations:Debug"
		defines "MA_DEBUG"
		symbols "On"

	
	filter "configurations:Release"
		defines "MA_RELEASE"
		optimize "On"

	
	filter "configurations:Dist"
		defines "MA_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Malic/vendor/spdlog/include",
		"Malic/src"
	}

	links
	{
		"Malic"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MA_PLATFORM_WINDOWS"

		}

	filter "configurations:Debug"
		defines "MA_DEBUG"
		symbols "On"

	
	filter "configurations:Release"
		defines "MA_RELEASE"
		optimize "On"

	
	filter "configurations:Dist"
		defines "MA_DIST"
		optimize "On"
