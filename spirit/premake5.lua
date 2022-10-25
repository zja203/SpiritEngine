project "SpiritEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	
	targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"src/**.cpp",
		"include/**.hpp",
		"vendor/**"
	}

	includedirs {
		"include",
		"vendor/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "system:linux"
		systemversion "latest"

	filter { "system:windows", "configurations:Debug" }
		buildoptions "/MTd"

	filter { "system:linux", "configurations:Debug" }
		buildoptions "-ggdb"

	filter { "configurations:Debug" }
		runtime "Debug"
		symbols "on"
		optimize "off"
		defines "SPRT_DEBUG"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

	filter { "configurations:Release" }
		runtime "Release"
		optimize "on"
		defines "SPRT_RELEASE"
