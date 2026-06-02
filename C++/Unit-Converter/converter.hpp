//This will solve the duplicated declarations in header files
#pragma once

#include <iostream>

// Unit classes with tool functions
struct PressureUnit 
{
    const int Pa    = 1;
    const int Bar   = 2;
    const int Atm   = 3;
    const int Psi   = 4;

    static std::string toString(int unit)
    {
        switch (unit)
        {
        case 1:     return "Pa";
        case 2:     return "Bar";
        case 3:     return "Atm";
        case 4:     return "Psi";
        default:    return "N/A";
        }
    }
};

struct TemperatureUnit 
{
    const int K     = 1;
    const int C     = 2;
    const int F     = 3;
    const int R     = 4;

    static std::string toString(int unit)
    {
        switch (unit)
        {
        case 1:     return "K";
        case 2:     return "C";
        case 3:     return "F";
        case 4:     return "R";
        default:    return "N/A";
        }
    }
};

struct EnergyUnit 
{
    const int J     = 1;
    const int Cal   = 2;
    const int Btu   = 3;

    static std::string toString(int unit)
    {
        switch (unit)
        {
        case 1:     return "J";
        case 2:     return "Cal";
        case 3:     return "Btu";
        default:    return "N/A";
        }
    }
};

// Result class for history loging
struct ConversionResults
{
    double inputValue;
    double outputValue;
    std::string inputUnit;
    std::string outputUnit;
};

// Ading forward declarations in header file to avoid compilation errors
double convertPressure(
    double value,
    const std::string& from,
    const std::string& to
);

double convertTemperature(
    double value,
    const std::string& from,
    const std::string& to
);

double convertEnergy(
    double value,
    const std::string& from,
    const std::string& to
);
