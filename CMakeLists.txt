# This CMakeLists.txt is intended to be used with ofnode CMake build system for openFrameworks
# see https://github.com/ofnode/of

project(version-de-travail)
set(APP ${PROJECT_NAME})

cmake_minimum_required(VERSION 3.1)

set(OF_ROOT ~/Documents/repos/of CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)

ofxaddon(ofxOscQuery)
#ofxaddon(ofxOsc)
ofxaddon(ofxGui)
ofxaddon(ofxAssimpModelLoader)
ofxaddon(ofxXmlSettings)
ofxaddon(ofxKinect)
ofxaddon(ofxOpenCv)
#ofxaddon(OpenNI-master)
#ofxaddon(ofxOpenNI-master)



option(COTIRE "Use cotire" ON)

set(SOURCES
    src/main.cpp
    src/ofApp.cpp

    src/CirclesRenderer.h
    src/CirclesRenderer.cpp
    src/Swarm.h
    src/Swarm.cpp
    src/Cube.h
    src/Cube.cpp
    src/Material.h
    src/Material.cpp
    src/Camera.h
    src/Camera.cpp
    src/ofxgamecamera.h
    src/ofxgamecamera.cpp
    src/ofxjoystick.h
    src/ofxjoystick.cpp
#    src/ofxopenni.h
#    src/ofxopenni.cpp
#    src/ofxopennitypes.h
#    src/ofxopennitypes.cpp
#    ../src/ofxOssiaTypes.h
#    ../src/ofxOscQueryServer.h
#    ../src/ofxOssiaNode.h
#    ../libs/ossia/include/ossia-cpp98.hpp
)


add_executable(
    ${APP}
    MACOSX_BUNDLE
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

target_link_libraries(
    ${APP}
    ${OPENFRAMEWORKS_LIBRARIES}

)

find_package (SDL)
if (SDL_FOUND)
    message( "libsdl found")

  # Une fois la dépendance trouvée, nous l'incluons au projet
  target_include_directories(${APP} PUBLIC ${SDL_INCLUDE_DIR})
  target_link_libraries (${APP} ${SDL_LIBRARY}
      )
else ()
  # Sinon, nous affichons un message
  message(FATAL_ERROR "libsdl not found")
endif ()


set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) # definir le dossier où les exécutables vont être produits

if(UNIX AND NOT APPLE)
  target_link_libraries(
    ${APP}
    avahi-client
    avahi-common
  )
endif()

set_target_properties(
    ${APP} PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST
    "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist"
)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set_target_properties( ${APP} PROPERTIES OUTPUT_NAME "${APP}-Debug")
endif()

if (CMAKE_CROSSCOMPILING)
    set_target_properties( ${APP} PROPERTIES OUTPUT_NAME
      "${APP}-${OF_PLATFORM}-${CMAKE_BUILD_TYPE}")
endif()

if (COTIRE)
    cotire(${APP})
endif()
