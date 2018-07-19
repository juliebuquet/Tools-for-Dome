cmake_minimum_required(VERSION 2.8)

project(testSkeltrack)

set(APP ${PROJECT_NAME})

cmake_minimum_required(VERSION 3.1)

#set(OF_ROOT  "${CMAKE_CURRENT_SOURCE_DIR}"../.. CACHE PATH "The root directory of ofnode/of project.")
set(OF_ROOT  ~/Documents/repos/of CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)





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
target_include_directories(${APP} PUBLIC ${GFREENECT_INCLUDE_DIR})
target_link_libraries (${APP} ${GFREENECT_LIBRARY})

target_include_directories(${APP} PUBLIC ${SKELTRACK_INCLUDE_DIR})
target_link_libraries (${APP} ${SKELTRACK_LIBRARY})

target_include_directories(${APP} PUBLIC ${CLUTTER_INCLUDE_DIR})
target_link_libraries (${APP} ${CLUTTER_LIBRARY})

target_include_directories(${APP} PUBLIC ${COGL_INCLUDE_DIR})
target_link_libraries (${APP} ${COGL_LIBRARY})

target_include_directories(${APP} PUBLIC ${JSON-GLIB_INCLUDE_DIR})
target_link_libraries (${APP} ${JSON-GLIB_LIBRARY})

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


