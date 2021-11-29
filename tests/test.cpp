#include "gtest/gtest.h"
#include "display_test.hpp"
#include "../headers/Display.hpp"
#include "../headers/Scheduler.hpp"
#include "../headers/Menu.hpp"
#include "../headers/Remove.hpp"

using namespace std;



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
