#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H
#include <iostream>
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"
#include "WeatherData.h"

class CurrentConditionsDisplay : public IObserver, IDisplayElement
{
private:
    double m_temperature, m_humidity;
    ISubject* m_weatherData;
public:
    CurrentConditionsDisplay(ISubject* weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(this);
    }
    virtual ~CurrentConditionsDisplay() {}
    void update() override;
    void display() const override;
};
#endif