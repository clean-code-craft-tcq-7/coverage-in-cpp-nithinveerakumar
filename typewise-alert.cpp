#include "typewise-alert.h"
#include <stdio.h>
#include <iostream>
using namespace std;
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
  
  AlertInfo[alertTarget];
 
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
