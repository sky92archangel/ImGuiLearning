workspace "ImGuiDemo"
	architecture "x64"

	 configurations { "Debug", "Release" ,"Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "ImGuiDemoGlad"
	location "ImGuiDemoGlad"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir ..  "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir ..  "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		-- "%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/../_dependency_/glad/include",
		"%{prj.name}/../_dependency_/glfw/glfw-3.3.8.bin.WIN64/include",
		"%{prj.name}/../_dependency_/imgui/1.88",
		"%{prj.name}/../_dependency_/glew/glew-2.1.0/include",
		"%{prj.name}/../_dependency_/glm",
	}

	libdirs {
		"%{prj.name}/../_dependency_/glfw/glfw-3.3.8.bin.WIN64/lib-vc2022", 
		"%{prj.name}/../_dependency_/glew/glew-2.1.0/lib/Release/x64", 
	 }
	 links{
		"glfw3.lib",
		"opengl32.lib",
		"glew32s.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL",
			--"_WINDLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"
		 


-- project "Sandbox"
-- 	location "Sandbox"
-- 	kind "ConsoleApp"
-- 	language "C++"

-- 	targetdir ("bin/" .. outputdir ..  "/%{prj.name}")
-- 	objdir ("bin-obj/" .. outputdir ..  "/%{prj.name}")
--  	files{
-- 		"%{prj.name}/src/**.h",
-- 		"%{prj.name}/src/**.cpp",
-- 	}

-- 	includedirs {
-- 		--"../Hazel/vendor/spdlog/include"
-- 		"Hazel/vendor/spdlog/include",
-- 		"Hazel/src"
-- 	}

-- 	links{
-- 		"Hazel"
-- 	}

-- 	filter "system:windows"
-- 		cppdialect "C++17"
-- 		staticruntime "On"
-- 		systemversion "latest"

-- 		defines{
-- 			"HZ_PLATFORM_WINDOWS" 
-- 			--"_WINDLL"
-- 		}

-- 	filter "configurations:Debug"
-- 		defines "HZ_DEBUG"
-- 		symbols "On"

-- 	filter "configurations:Release"
-- 		defines "HZ_RELEASE"
-- 		optimize "On"

-- 	filter "configurations:Dist"
-- 		defines "HZ_DIST"
-- 		optimize "On"
		 

-- workspace "MyWorkspace"
--     configurations { "Debug", "Release" }
-- 
-- project "MyProject"
--     kind "ConsoleApp"
--     language "C++"
--     files { "**.h", "**.cpp" }
-- 
--     filter { "configurations:Debug" }
--         defines { "DEBUG" }
--         symbols "On"
-- 
--     filter { "configurations:Release" }
--         defines { "NDEBUG" }
--         optimize "On"