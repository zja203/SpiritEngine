project "TestApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	links {
		"SpiritEngine"
	}

	files {
		"include/**.hpp",
		"src/**.cpp",
	}

	includedirs {
		"include",
		"%{wks.location}/spirit/include",
		"%{wks.location}/spirit",
		"%{wks.location}/spirit/vendor/include"
	}

	filter "system:windows"
		systemversion "latest"

		files {
			"platform/windows/src/**.cpp",
			"platform/windows/**.hpp",
		}

		removefiles {
			"include/sprtpch.hpp",
			"src/sprtpch.cpp"
		}

		links {
			"GLFW",
			"opengl32.lib"
		}

	filter "system:linux"
		systemversion "latest"

		links {"pthread", "GL", "glfw", "GLEW", "GLU"}

		files {
			"platform/linux/src/**.cpp",
			"platform/linux/**.hpp",
		}
		
		defines {
			"_GLFW_X11",
		}

	filter "configurations:Debug"
		defines {
			"SPRT_DEBUG",
			"SPRT_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPRT_RELEASE"
		runtime "Release"
		optimize "on"
