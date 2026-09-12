# The following variables contains the files used by the different stages of the build process.
set(MCU2_SRC_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${MCU2_SRC_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${MCU2_SRC_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(MCU2_SRC_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${MCU2_SRC_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${MCU2_SRC_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(MCU2_SRC_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ADC_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../DIO_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../INTERRUPT_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../KEYPAD_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../LCD_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SPI_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../STEPMOTOR_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SevenSeg_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TIMER0_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TIMER1_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../UART_prog.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c")
set_source_files_properties(${MCU2_SRC_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(MCU2_SRC_default_default_XC8_FILE_TYPE_link)
set(MCU2_SRC_default_default_XC8_FILE_TYPE_objcopy_avr)
set(MCU2_SRC_default_image_name "default.elf")
set(MCU2_SRC_default_image_base_name "default")

# The output directory of the final image.
set(MCU2_SRC_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/MCU2_SRC")

# The full path to the final image.
set(MCU2_SRC_default_full_path_to_image ${MCU2_SRC_default_output_dir}/${MCU2_SRC_default_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .hxl
    .mum
    .o
    .sdb
    .sym
    .cmf)
list(TRANSFORM output_extensions PREPEND "${MCU2_SRC_default_output_dir}/${MCU2_SRC_default_image_base_name}")
