#include "StatisticsDisplay.h"

void StatisticsDisplay::update()
{
    auto wd = dynamic_cast<WeatherData*>(m_weatherData);
    if (wd)
    {
        m_temperature = wd->getTemperature();
        m_tempSum += m_temperature;
        m_numReadings++;
        if (m_temperature > m_maxTemp)
        {
            m_maxTemp = m_temperature;
        }
        if (m_temperature < m_minTemp)
        {
            m_minTemp = m_temperature;
        }
    }
    display();
}
void StatisticsDisplay::display() const
{
    std::cout << "Avg/Max/Min temperature = " << (m_tempSum / m_numReadings)
        << "/" << m_maxTemp << "/" << m_minTemp << std::endl;
}