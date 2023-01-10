#include "typewise-alert.h"

map<CoolingType,Limit> CoolingInfo = {{PASSIVE_COOLING,{PASSIVE_COOLING_LOWER_LIMIT,PASSIVE_COOLING_UPPER_LIMIT}},
                                      {MED_ACTIVE_COOLING,{MED_ACTIVE_COOLING_LOWER_LIMIT,MED_ACTIVE_COOLING_UPPER_LIMIT}},
                                      {HI_ACTIVE_COOLING,{HI_ACTIVE_COOLING_LOWER_LIMIT,HI_ACTIVE_COOLING_UPPER_LIMIT}}};


map<AlertTarget,alertMedium> sendAlert = {{TO_CONTROLLER,&sendToController},
                                          {TO_EMAIL,&sendToEmail}};

map<BreachType,string> getMessageForBreachType = {{TOO_LOW,"Hi, the temperature is too low\n"},
                                              {TOO_HIGH,"Hi, the temperature is too high\n"}};


BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;

}



BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = CoolingInfo[coolingType].lowerLimit;
  int upperLimit = CoolingInfo[coolingType].upperLimit;
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  sendAlert[alertTarget](breachType);
 
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);  
  printf(getMessageForBreachType[breachType].c_str());
}
  
