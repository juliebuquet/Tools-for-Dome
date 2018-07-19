cmake_minimum_required(VERSION 2.8)

project(TestHandGesture)
set(APP ${PROJECT_NAME})


set(OF_ROOT ~/Documents/repos/of CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)

#ofxaddon(ofxOsc)
#ofxaddon(ofxGui)
#ofxaddon(ofxAssimpModelLoader)
#ofxaddon(ofxXmlSettings)
#ofxaddon(ofxKinect)
ofxaddon(ofxOpenCv)
#ofxaddon(OpenNI-master)
#ofxaddon(ofxOpenNI-master)



option(COTIRE "Use cotire" ON)

set(SOURCES
    "main.cpp"

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
