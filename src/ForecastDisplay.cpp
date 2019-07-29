#include "ForecastDisplay.h"

void ForecastDisplay::update()
{
    auto wd = dynamic_cast<WeatherData*>(m_weatherData);
    if (wd)
    {
        this->m_lastPressure = this->m_currentPressure;
        this->m_currentPressure = wd->getPressure();
    }
    display();
}

void ForecastDisplay::display() const
{
    std::cout << "Forecast: ";
    if (m_currentPressure > m_lastPressure) 
    {
        std::cout << "Improving weather on the way!\n";
    } 
    else if (m_currentPressure == m_lastPressure) 
    {
        std::cout << "More of the same\n";
    } 
    else if (m_currentPressure < m_lastPressure) 
    {
        std::cout << "Watch out for cooler, rainy weather\n";
    }
}