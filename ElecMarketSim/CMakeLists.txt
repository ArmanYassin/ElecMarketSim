# CMakeList.txt : CMake project for ElecMarketSim1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ElecMarketSim1 "ElecMarketSim1.cpp" "ElecMarketSim1.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ElecMarketSim1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
