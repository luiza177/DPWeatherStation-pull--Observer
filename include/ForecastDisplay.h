#ifndef FORECASTDISPLAY_H
#define FORECASTDISPLAY_H
#include <iostream>
#include "WeatherData.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class ForecastDisplay : public IObserver, IDisplayElement
{
private:
    double m_currentPressure = 29.92;  
	double m_lastPressure;
    ISubject* m_weatherData;
public:
    ForecastDisplay(ISubject* weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(this);
    }
    virtual ~ForecastDisplay(){}
    
    void update() override;
    void display() const override;
};
#endif