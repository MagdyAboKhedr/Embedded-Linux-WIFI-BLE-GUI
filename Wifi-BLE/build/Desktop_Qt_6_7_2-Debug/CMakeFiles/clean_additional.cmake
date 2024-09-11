# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Wifi-BLE_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Wifi-BLE_autogen.dir/ParseCache.txt"
  "Wifi-BLE_autogen"
  )
endif()
