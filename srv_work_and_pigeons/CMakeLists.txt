cmake_minimum_required(VERSION 3.14)

project(srv_work_and_pigeons)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_REQUIRED_COMPONENTS system)

# Найдите Boost
find_package(Boost REQUIRED COMPONENTS ${Boost_REQUIRED_COMPONENTS})

# Подключите директории Boost
include_directories(${Boost_INCLUDE_DIRS})

# Основной исполняемый файл
add_executable(srv_work_and_pigeons main.cpp)

# Линковка с Boost.System (необходим для Asio)
target_link_libraries(srv_work_and_pigeons ${Boost_LIBRARIES})