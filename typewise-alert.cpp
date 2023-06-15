#include "typewise-alert.h"

BreachType CheckLowLimit(double value, double lowerLimit)
{
  BreachType retBreachType = NORMAL;
  //retBreachType = (BreachType)(value < lowerLimit);
  if (value < lowerLimit)
  {
    retBreachType = TOO_LOW;
  }
  return retBreachType;
}

BreachType CheckHighLimit(double value, double upperLimit)
{
  BreachType retBreachType = NORMAL;
  if(value > upperLimit)
  {
    retBreachType = TOO_HIGH;
  }
  return retBreachType;
}

BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  BreachType retBreachType = NORMAL;
  retBreachType = CheckLowLimit(value,lowerLimit);
  retBreachType = CheckHighLimit(value,upperLimit);

  return retBreachType;
}
int GetUpperLimit(CoolingType coolingType)
{  
  int UpperLimit = 0;
  auto itr = TemperatureUpperLimit.find(coolingType);  
  if(itr != TemperatureUpperLimit.end())
  {
    UpperLimit = itr->second;
  }
  return UpperLimit;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  return inferBreach(temperatureInC, lowerLimit, GetUpperLimit(coolingType));
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(
      batteryChar.coolingType, temperatureInC);

  if (alertTarget)
  {
    sendToEmail(breachType);
    return;
  }
  sendToController(breachType);
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;

  printf("%x : %x\n", header, breachType);
}


void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  printf("%s\n",TemperatureStatusList[breachType]); 
}
