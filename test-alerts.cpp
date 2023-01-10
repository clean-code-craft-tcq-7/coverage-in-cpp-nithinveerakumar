#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  //cover inferBreach
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(31, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
  //cover classifyTemperatureBreach
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,-5) == TOO_LOW);
  //cover checkAndAlert
  BatteryCharacter bc = {HI_ACTIVE_COOLING,"SAMSU"};
  checkAndAlert(TO_CONTROLLER,bc,20);
  //
  sendToController(NORMAL);
  sendToEmail(TOO_HIGH);

}
