workspace "CloudManRenderer"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "3rdparty/GLFW/include"

include "/3rdparty/GLFW"

project "CloudManRenderer"
    location "CloudManRenderer"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "CMR_Pch.h"
    pchsource "%{prj.name}/src/CMR_Pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "3rdparty/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "opengl32.lib",
        "GLFW"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "10.0.19041.0"

        defines
        {   
            "CMR_PLATFORM_WINDOWS"
        }


    filter "configurations:Debug"
        defines "CMR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CMR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CMR_DIST"
        optimize "On"