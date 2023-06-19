#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

BatteryCharacter batteryChar[3] = {{PASSIVE_COOLING,"abc"},{HI_ACTIVE_COOLING,"mail"}, {MED_ACTIVE_COOLING,"mail"}};

TEST_CASE("To classify temperature breach for Passive cooling NORMAL Temperature"){
REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 12) == NORMAL);
}

TEST_CASE("To classify temperature breach for High Active cooling NORMAL Temperature"){
REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 12) == NORMAL);
}

TEST_CASE("To classify temperature breach for Medium Active cooling NORMAL Temperature"){
REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 12) == NORMAL);
}

TEST_CASE("To classify temperature breach for Passive cooling LOW Temperature"){
REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
}

TEST_CASE("To classify temperature breach for High Active cooling LOW Temperature"){
REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1) == TOO_LOW);
}

TEST_CASE("To classify temperature breach for Medium Active cooling LOW Temperature"){
REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == TOO_LOW);
}

TEST_CASE("To classify temperature breach for Passive cooling HIGH Temperature"){
REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("To classify temperature breach for High Active cooling HIGH Temperature"){
REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 55) == TOO_HIGH);
}

TEST_CASE("To classify temperature breach for Medium Active cooling HIGH Temperature"){
REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 55) == TOO_HIGH);
}

TEST_CASE("To classify temperature breach for negative case"){
REQUIRE(classifyTemperatureBreach(CoolingType(5), 55) == TOO_HIGH);
}

TEST_CASE("To checkAndAlert the system state_1 EMAIL"){
(checkAndAlert(TO_EMAIL,batteryChar[0], 12));
}

TEST_CASE("To checkAndAlert the system state_2 EMAIL"){
(checkAndAlert(TO_EMAIL,batteryChar[1], -5));
}

TEST_CASE("To checkAndAlert the system state_3 EAMIL"){
(checkAndAlert(TO_EMAIL,batteryChar[2], 55));
}

TEST_CASE("To checkAndAlert the system state Controller"){
(checkAndAlert(TO_CONTROLLER,batteryChar[1], -5));
}