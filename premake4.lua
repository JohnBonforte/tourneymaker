-- will create the folders according to the action (gmake, vs2010, etc) and os
bin_os_compiler = "bin/" .. os.get() .. "/" .. _ACTION

-- A solution contains projects, and defines the available configurations
solution "Tourneymaker"
   configurations { "Debug", "Release" }
   location (bin_os_compiler) 
 
   -- A project defines one build target
   project "tourneymaker"
      kind "ConsoleApp"
      language "C++"
      files { "**.h", "**.cpp" }
      location (bin_os_compiler) 
      objdir (bin_os_compiler) 
      targetdir (bin_os_compiler) 
      includedirs { "inc" }

      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }    

      configuration { "gmake" }
          buildoptions { "-Wall", "-pedantic", "-std=c++0x" }



