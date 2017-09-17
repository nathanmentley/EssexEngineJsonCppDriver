#files

file(GLOB EssexEngineJsonCppDriver_HEADERS
    "src/Drivers/JsonCppDriver/*.h"
    "src/Drivers/JsonCppDriver/json/*.h"
)
file(GLOB EssexEngineJsonCppDriver_SRC
    ${EssexEngineJsonCppDriver_HEADERS}
    "src/Drivers/JsonCppDriver/*.cpp"
)

#setup headers

file(COPY ${EssexEngineJsonCppDriver_HEADERS} DESTINATION "${CMAKE_BINARY_DIR}/lib/include/EssexEngineJsonCppDriver/")

#setup build

add_library(EssexEngineJsonCppDriver SHARED ${EssexEngineJsonCppDriver_SRC})
target_link_libraries(EssexEngineJsonCppDriver EssexEngineCore)
target_link_libraries(EssexEngineJsonCppDriver EssexEngineJsonDaemon)
target_link_libraries(EssexEngineJsonCppDriver EssexEngineFileSystemDaemon)