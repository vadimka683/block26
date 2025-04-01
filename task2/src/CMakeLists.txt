cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("task2")

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (task2 task2.cpp record.cpp Phone.cpp ${MY_INCLUDE_DIR}/record.h ${MY_INCLUDE_DIR}/Phone.h ClassNumber.cpp ${MY_INCLUDE_DIR}/ClassNumber.h)
target_include_directories(task2 PUBLIC ${MY_INCLUDE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET task2 PROPERTY CXX_STANDARD 20)
endif()

