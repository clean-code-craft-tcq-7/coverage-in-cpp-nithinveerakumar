#pragma once

#define PASSIVE_COOLING_LOWER_LIMIT 0
#define PASSIVE_COOLING_UPPER_LIMIT 35
#define MED_ACTIVE_COOLING_LOWER_LIMIT 0
#define MED_ACTIVE_COOLING_UPPER_LIMIT 40
#define HI_ACTIVE_COOLING_LOWER_LIMIT 0
#define HI_ACTIVE_COOLING_UPPER_LIMIT 45



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
