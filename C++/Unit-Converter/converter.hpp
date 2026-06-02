//This will solve the duplicated declarations in header files
#pragma once

#include <iostream>

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
