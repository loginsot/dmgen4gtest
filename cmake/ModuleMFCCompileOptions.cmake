

macro(SetMFCCompileOptions)
    message(STATUS "================================================================================")
    #set(CMAKE_MFC_FLAG 1)  
    #add_definitions(-DUNICODE -D_UNICODE)
    #add_definitions(-D_AFXDLL)
    #set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")

    message(STATUS "================================================================================")
endmacro(SetMFCCompileOptions)