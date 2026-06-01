//This will solve the duplicated declarations in header files
#pragma once

// Using enum to assign numbers to each item in the defined classes
enum class PressureUnits {
    Pa,
    Bar,
    Atm,
    Psi
};

enum class TemperatureUnits {
    K,
    C,
    F
};

enum class EnergyUnits {
    J,
    Cal,
    Btu
};