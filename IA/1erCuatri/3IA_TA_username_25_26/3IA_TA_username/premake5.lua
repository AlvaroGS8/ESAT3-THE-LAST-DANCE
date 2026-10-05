-- ---------------------------------
-- Toni Barella, Gustavo Aranda
-- Inteligencia Artificial 3VGP
-- ESAT 2016-2025
-- Premake Project Configuration.
-- ---------------------------------

-- Define workspace (replaces "solution" in Premake 4)
workspace ("3IA_Solution_" .. _ACTION)
    -- Define configurations and platforms for the build
    configurations { "Debug", "Release" }
    --platforms { "Win32", "Win64", "Win_arm64", "Linux_x64", "macos_universal" }
    platforms { "Win32", "Win64", "Linux_x64", "macos_universal" }
    location "build"
    language "C++"
    debugdir "."

    filter { "platforms:Win32" }
        system "windows"
        architecture "x86"
        libdirs { "./deps/esat/bin" }

    filter { "platforms:Win64" }
        system "windows"
        architecture "x86_64"
        libdirs { "./deps/esat/bin/win_x64" }
        
    --filter { "platforms:Win_arm64" }
    --    system "windows"
    --    architecture "ARM64"
    --    libdirs { "./deps/esat/bin/win_arm64" }

    filter { "platforms:Linux_x64" }
        system "linux"
        architecture "x64"
        libdirs { "./deps/esat/bin/linux64" }
        cppdialect "C++0x"
        
   filter { "platforms:macos_universal" }
        system "macosx"
        architecture "universal"
        libdirs { "./deps/esat/bin/macos64" }
        cppdialect "C++11"
        
    filter { }

    -- List of projects to build
    --local projects = { "PR0_Base", "PR1_AStar", "PR2_SuperAI" }
    local projects = { "PR0_Base" }

    -- Loop through each project to define its build settings
    for _, prj in ipairs(projects) do 
        project(prj)
        targetname(prj)

        -- Set project location inside build directory based on project name and action
        local prj_path = "./build/" .. prj
        location(prj_path .. "/" .. _ACTION)

        -- Include directories common to all projects
        includedirs {
            "./include/",
            "./include/common",
            "./deps/esat/include",
        }

        -- Files to be included in the build common for all projects
        files {
            "./include/common/*.h",
        }

        -- Enable extra compiler warnings
        --flags { "ExtraWarnings" }
        warnings "Extra"

        -- Set language and kind for the project
        language "C++"
        kind "ConsoleApp"

        -- Settings specific to Debug configuration
        filter "configurations:Debug"
            defines { "DEBUG" }
            targetdir "bin/Debug"
            targetsuffix "_d"
            objdir "build/Debug"
            symbols "On"         -- Produce debugging symbols

        -- Settings specific to Release configuration
        filter "configurations:Release"
            targetdir "bin/Release"
            objdir "build/Release"
            optimize "On"        -- Enable optimization

        -- Windows-specific filters (Visual Studio platform targeting)
        filter "system:windows"
            links { "opengl32", "user32", "shell32", "gdi32" }

            -- Define compiler macros
            defines { "_CRT_SECURE_NO_WARNINGS" }

            --filter "action:vs2019 or vs2022"
            --    systemversion "latest"

            filter { "system:windows", "configurations:Debug" }
                links { "ESAT_d" }

            filter { "system:windows", "configurations:Release" }
                links { "ESAT" }
            
        filter "system:linux"
            links { "ESAT", "asound", "dl", "pthread", "X11", "GL", "GLU" }
            buildoptions { "-m64" }

        filter "system:macosx"
            links { "ESAT", "OpenGL.framework", "Cocoa.framework", "Corevideo.framework", "IOKit.framework" }
            buildoptions { "-m64" }

        -- Clear filter to avoid leaking settings to other projects or configurations
        filter {}
    end

    -- Specific file inclusion for PR0_Base project
    project "PR0_Base"
        files { "./src/**.cc", "./include/**.h" }

    -- PR1_AStar project currently has no additional files included
    --project "PR1_AStar"
    --    files { }

