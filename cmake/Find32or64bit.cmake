#
# Determining 32 or 64 (and/or both) from environment variables
# 

include(cmake/print.cmake)

set(MAKE32BITONLY $ENV{MAKE32BITONLY})
set(MAKE64BITONLY $ENV{MAKE64BITONLY})

if (MAKE32BITONLY AND MAKE64BITONLY)
  print(STATUS "both MAKE32BITONLY and MAKE64BITONLY requested")
  message( FATAL_ERROR "only MAKE32BITONLY or MAKE64BITONLY can be set at the same time" )
endif()

set(MAKE32BIT 1)
set(MAKE64BIT 1)

if (MAKE32BITONLY)
  unset(MAKE64BIT)
endif()

if (MAKE64BITONLY)
  unset(MAKE32BIT)
endif()

if (MAKE32BIT)
  print(STATUS "32bit make requested")
endif()

if (MAKE64BIT)
  print(STATUS "64bit make requested")
endif()

