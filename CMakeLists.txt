cmake_minimum_required(VERSION 3.23)
project(AED_TP1)

set(CMAKE_CXX_STANDARD 14)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

include_directories(headers)

add_executable(AED_TP1
        src/main.cpp
        headers/Slot.h
        src/Slot.cpp
        headers/Class.h
        src/Class.cpp
        headers/UC.h
        src/UC.cpp
        headers/Student.h
        src/Student.cpp
        headers/ScheduleManager.h
        src/ScheduleManager.cpp
        headers/Request.h
        headers/AddRequest.h
        src/AddRequest.cpp
        headers/RemoveRequest.h
        src/RemoveRequest.cpp
        headers/SwitchRequest.h
        src/SwitchRequest.cpp
        headers/SwapRequest.h
        src/SwapRequest.cpp
        headers/Oopsie.h
        src/Oopsie.cpp
        headers/Menu.h
        src/Menu.cpp)
