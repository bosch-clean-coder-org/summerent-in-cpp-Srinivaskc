#pragma once
#include <map>
#include<iostream>
#include <stdio.h>
#include<string>
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

std::map<CoolingType, int> TemperatureUpperLimit{{PASSIVE_COOLING, 35}, {HI_ACTIVE_COOLING, 45}, {MED_ACTIVE_COOLING, 40}};
std::map<BreachType, std::string> TemperatureStatusList {{NORMAL,"Normal"},{TOO_LOW,"Temperature too low"},{TOO_HIGH,"Temperature too high"}};

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

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
