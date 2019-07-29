cmake_minimum_required(VERSION 3.15)

Project(WeatherStation-pull)

add_subdirectory(WeatherFromWeb-cpp)

include_directories(include)

set(SOURCESPULL
    src/main-pull.cpp
    src/CurrentConditionsDisplay.cpp
    src/ForecastDisplay.cpp
    src/StatisticsDisplay.cpp
    src/HeatIndexDisplay.cpp
    src/WeatherData.cpp
)

add_executable(WeatherStationPull ${SOURCESPULL})
target_link_libraries(WeatherStationPull WeatherFromWeb)