#include "CurrentConditionsDisplay.h"

void CurrentConditionsDisplay::update()
{
    auto wd = dynamic_cast<WeatherData*>(m_weatherData);
    if (wd)
    {
        this->m_temperature = wd->getTemperature();
        this->m_humidity = wd->getHumidity();
    }
    display();
}

void CurrentConditionsDisplay::display() const
{
    std::cout << "Current Conditions: " << m_temperature
        << "C degrees and " << m_humidity <<
        "% humidity" << std::endl;
};