workspace "CloudManRenderer"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CloudManRenderer"
    location "CloudManRenderer"
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

    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
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