#ifndef HEATINDEXDISPLAY_H
#define HEATINDEXDISPLAY_H
#include <iostream>
#include "WeatherData.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class HeatIndexDisplay : public IObserver, IDisplayElement
{
private:
    double m_temperature, m_humidity, m_heatIndex;
    ISubject* m_weatherData;
    double computeHeatIndex(double ct, double rh);
public:
    HeatIndexDisplay(ISubject* weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(this);
    }
    virtual ~HeatIndexDisplay(){}
    void update() override;
    void display() const override;
};
#endif