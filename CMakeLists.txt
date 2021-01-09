cmake_minimum_required(VERSION 2.10)
project(RetroPanda)

#execute_process(COMMAND sdl-config --cflags OUTPUT_VARIABLE SDL_FLAGS)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 ${SDL_CONFIG}")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 ${SDL_CONFIG}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")

find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIRS})

find_package(SDL_ttf REQUIRED)
include_directories(${SDL_TTF_INCLUDE_DIRS})

find_package(SDL_image REQUIRED)
include_directories(${SDL_IMAGE_INCLUDE_DIRS})

find_package(SDL_mixer REQUIRED)
include_directories(${SDL_MIXER_INCLUDE_DIRS})

aux_source_directory(src/ SOURCES)

add_executable(${PROJECT_NAME} ${SOURCES})

# something strange
#execute_process(COMMAND sdl-config --libs OUTPUT_VARIABLE SDL_CONFIG_LIBS)
#string(STRIP ${SDL_CONFIG_LIBS} SDL_CONFIG_LIBS)
#
#target_link_libraries(${PROJECT_NAME} ${SDL_CONFIG_LIBS})
#

message(${SDL_LIBRARY})

# nice bug awesome 3 hours. SDL_LIBRAR[IES] don't wok 
target_link_libraries(${PROJECT_NAME} ${SDL_LIBRARY})
#

target_link_libraries(${PROJECT_NAME} ${SDL_TTF_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL_IMAGE_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL_MIXER_LIBRARIES})