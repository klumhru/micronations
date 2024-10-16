cmake_minimum_required(VERSION 3.29)
project(micronations)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/deps)
set(PROTOC_ ${CMAKE_CURRENT_SOURCE_DIR}/deps/bin/protoc)

file(GLOB micronations_SRC "src/*/*.cpp" "src/*/*.cc" "src/*/*.h" "main.cpp")
file(GLOB micronations_PROTO "src/data/*.proto")

add_compile_definitions(
        AUTO_INITIALIZE_EASYLOGGINGPP=ON
)

include_directories(
        deps/include
        src
)

link_directories(
        deps/lib
)

find_package(absl CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/data/id.pb.cc
        COMMAND ${PROTOC_}
        ARGS    --cpp_out=${CMAKE_CURRENT_SOURCE_DIR}/src/data
                -I ${CMAKE_CURRENT_SOURCE_DIR}/src/data
                ${micronations_PROTO}
        DEPENDS ${micronations_PROTO}
)

add_custom_target(
        mn_grpc_client
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/data/id.pb.cc
)


add_executable(
        micronations
        ${micronations_SRC}
)

target_link_libraries(
        micronations
        SDL3
        SDL3_image
        protobuf::libprotobuf
        gRPC::grpc++
        absl::base
 )

add_dependencies(
        micronations
        mn_grpc_client
)
