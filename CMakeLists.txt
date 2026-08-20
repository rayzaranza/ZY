cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Zengine")

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable (Zengine "Zengine.cpp" "Zengine.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Zengine PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Zengine PRIVATE glm::glm glad::glad glfw)