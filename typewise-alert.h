#include "constants.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
typedef void (*alertMedium)(BreachType);

map<CoolingType,Limit> CoolingInfo;
map<AlertTarget,alertMedium> AlertInfo;
map<BreachType,string> messageForBreachType;
