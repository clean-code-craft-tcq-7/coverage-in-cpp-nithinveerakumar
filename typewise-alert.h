#pragma once
#include <map>
using namespace std;
typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;


struct Limit {
  int lowerLimit;
  int upperLimit;
};

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

map<CoolingType,Limit> CoolingInfo = {{PASSIVE_COOLING,{0,35}},{MED_ACTIVE_COOLING,{0,40}},{HI_ACTIVE_COOLING,{0,45}}};
typedef void (*alertMedium)(BreachType);
map<AlertTarget,alertMedium> AlertInfo = {{TO_CONTROLLER,&sendToController},{TO_EMAIL,&sendToEmail}};