cmake_minimum_required (VERSION 3.0)
project (AudioFx)


include_directories ("${PROJECT_SOURCE_DIR}/include")


# glob all the sources
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Create the library
add_library(afx SHARED ${SOURCES})

# Generate a header for exporting definitions (windows...)
include (GenerateExportHeader)
GENERATE_EXPORT_HEADER( afx
             BASE_NAME AudioFx
             EXPORT_MACRO_NAME AFX_DLL
             EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/include/exports.h
             STATIC_DEFINE AFX_BUILT_AS_STATIC
)

# installations
file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/include/*.h")
install(TARGETS afx EXPORT AudioFx DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include)