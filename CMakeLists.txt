cmake_minimum_required(VERSION 2.8.3)
project(gui)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)

catkin_package(
 INCLUDE_DIRS #include
 CATKIN_DEPENDS roscpp 
)

link_directories(
${GTKMM_LIBRARY_DIRS})

include_directories(
${catkin_INCLUDE_DIRS}
${roscpp_INCLUDE_DIRS}
${GTKMM_INCLUDE_DIRS})

add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(gui src/gui.cpp)

target_link_libraries(gui ${catkin_LIBRARIES} ${roscpp_LIBRARIES} ${GTKMM_LIBRARIES})
