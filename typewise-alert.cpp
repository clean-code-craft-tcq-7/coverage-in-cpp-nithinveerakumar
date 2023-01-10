#include "typewise-alert.h"
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

map<CoolingType,Limit> CoolingInfo = {{PASSIVE_COOLING,{0,35}},{MED_ACTIVE_COOLING,{0,40}},{HI_ACTIVE_COOLING,{0,45}}};
typedef void (*alertMedium)(BreachType);
map<AlertTarget,alertMedium> AlertInfo = {{TO_CONTROLLER,&sendToController},{TO_EMAIL,&sendToEmail}};
map<BreachType,string> messageForBreachType= {{TOO_LOW,"Hi, the temperature is too low\n"},{TOO_HIGH,"Hi, the temperature is too high\n"}};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;

}



BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = CoolingInfo[coolingType].lowerLimit;
  int upperLimit = CoolingInfo[coolingType].upperLimit;
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );
  
  AlertInfo[alertTarget](breachType);
 
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);  
  printf(messageForBreachType[breachType].c_str());
}
  
