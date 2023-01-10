#include "constants.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
typedef void (*alertMedium)(BreachType);

map<CoolingType,Limit> CoolingInfo = {{PASSIVE_COOLING,{PASSIVE_COOLING_LOWER_LIMIT,PASSIVE_COOLING_UPPER_LIMIT}},
                                      {MED_ACTIVE_COOLING,{MED_ACTIVE_COOLING_LOWER_LIMIT,MED_ACTIVE_COOLING_UPPER_LIMIT}},
                                      {HI_ACTIVE_COOLING,{HI_ACTIVE_COOLING_LOWER_LIMIT,HI_ACTIVE_COOLING_UPPER_LIMIT}}};


map<AlertTarget,alertMedium> AlertInfo = {{TO_CONTROLLER,&sendToController},
                                          {TO_EMAIL,&sendToEmail}};

map<BreachType,string> messageForBreachType= {{TOO_LOW,"Hi, the temperature is too low\n"},
                                              {TOO_HIGH,"Hi, the temperature is too high\n"}};
