#include "rotor.h"

Rotor::Rotor(int numberOfBlades, float R_tip, float R_hub){
    numberBlades = numberOfBlades;
    rTip = R_tip;
    rHub = R_hub;
    blade = new std::vector <Section*>;
}
