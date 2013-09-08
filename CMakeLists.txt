cmake_minimum_required(VERSION 2.8.10)

project(ag)

list (APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

function (CTSanitiseBuildType)
  set (build_cache_string "Choose the type of build; options are: Debug Release RelWithDebInfo MinSizeRel.")
  if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Debug" CACHE STRING "${build_cache_string}" FORCE)
  endif ()
endfunction ()


function (CTCheckBuildDirectorySanityOrDie)
  if ("${CMAKE_SOURCE_DIR}" MATCHES " " OR "${CMAKE_BINARY_DIR}" MATCHES " ")
    message(FATAL_ERROR
            "Your source or binary path contains whitespace, which Linux "
            "tools often mishandle. Aborting!\n"
            "Source path: ${CMAKE_SOURCE_DIR}\n"
            "Binary path: ${CMAKE_BINARY_DIR}")
  endif ()

  if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR
            "We only allow out-of-source builds. Please build in some other "
            "directory.")
  endif ()
endfunction ()

CTCheckBuildDirectorySanityOrDie()
CTSanitiseBuildType()

set (sources
  src/decompress.c
  src/ignore.c
  src/log.c
  src/main.c
  src/options.c
  src/print.c
  src/scandir.c
  src/search.c
  src/util.c
)

add_executable(ag ${sources})

target_compile_definitions(ag PRIVATE
  -DPACKAGE_VERSION=0.16
)

target_include_directories(ag PRIVATE
  "src/win32"
)
