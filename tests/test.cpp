// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <header.hpp>
TEST(main, mau){
  int i =   mainF();
  EXPECT_FALSE(i);
}