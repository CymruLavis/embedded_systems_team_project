# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cocktail_machine_front_end_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cocktail_machine_front_end_autogen.dir\\ParseCache.txt"
  "cocktail_machine_front_end_autogen"
  )
endif()
