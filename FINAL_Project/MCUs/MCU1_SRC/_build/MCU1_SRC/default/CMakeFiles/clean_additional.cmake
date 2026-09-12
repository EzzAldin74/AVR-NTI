# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  [[D:\FINAL_Project\MCUs\MCU1_SRC\out\MCU1_SRC\default.cmf]]
  [[D:\FINAL_Project\MCUs\MCU1_SRC\out\MCU1_SRC\default.hex]]
  [[D:\FINAL_Project\MCUs\MCU1_SRC\out\MCU1_SRC\default.hxl]]
  [[D:\FINAL_Project\MCUs\MCU1_SRC\out\MCU1_SRC\default.mum]]
  [[D:\FINAL_Project\MCUs\MCU1_SRC\out\MCU1_SRC\default.o]]
  [[D:\FINAL_Project\MCUs\MCU1_SRC\out\MCU1_SRC\default.sdb]]
  [[D:\FINAL_Project\MCUs\MCU1_SRC\out\MCU1_SRC\default.sym]]
  )
endif()
