project "SpiritEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	
	targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "include/sprtpch.hpp"
	pchsource "src/sprtpch.cpp"

	files {
		"src/**.cpp",
		"include/**.hpp",
		"vendor/**"
	}

	includedirs {
		"include",
		".",
		"vendor/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

		files {
			"platform/windows/src/**.cpp",
			"platform/windows/**.hpp"
		}

		links {
			"GLFW",
			"opengl32.lib"
		}

	filter "system:linux"
		systemversion "latest"
		links { "pthread", "glfw", "GLEW", "GLU"}
		
		files {
			"platform/linux/src/**.cpp",
			"platform/linux/**.hpp"
		}

		defines {
			"_GLFW_X11"
		}

	filter { "system:windows", "configurations:Debug" }
		buildoptions "/MTd"

	filter { "system:linux", "configurations:Debug" }
		buildoptions "-ggdb"

	filter { "configurations:Debug" }
		runtime "Debug"
		symbols "on"
		optimize "off"
		defines {
			"SPRT_DEBUG",
			"SPRT_ENABLE_ASSERTS"
		}

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

	filter { "configurations:Release" }
		runtime "Release"
		optimize "on"
		defines "SPRT_RELEASE"
