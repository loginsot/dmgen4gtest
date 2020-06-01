cmake_minimum_required(VERSION 2.8)

SET(DMPROJECT_NAME "dmgen4gtest")
PROJECT(${DMPROJECT_NAME})
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
INCLUDE(cmake/ModuleMFCCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMGEN_VERSION_MAJOR "1")
SET(DMGEN_VERSION_MINOR "0")
SET(DMGEN_VERSION_PATCH "1")
SET(DMGEN_VERSION "${DMGEN_VERSION_MAJOR}.${DMGEN_VERSION_MINOR}.${DMGEN_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMGEN_VERSION}")

OPTION(USE_DMGEN "use dmgen" ON)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/${DMPROJECT_NAME}_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/${DMPROJECT_NAME}_config.h)

ADD_DEFINITIONS(-DCTEMPLATE_DLL_DECL=)

ModuleImportAll("thirdparty")

ExeImport("src" "dmtemplate")

#ShowEnvironment()