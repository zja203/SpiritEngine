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
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SPRT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPRT_RELEASE"
		runtime "Release"
		optimize "on"
