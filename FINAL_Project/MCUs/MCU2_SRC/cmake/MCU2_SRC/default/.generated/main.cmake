include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(MCU2_SRC_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(MCU2_SRC_default_default_XC8_FILE_TYPE_assemble)
add_library(MCU2_SRC_default_default_XC8_assemble OBJECT ${MCU2_SRC_default_default_XC8_FILE_TYPE_assemble})
    MCU2_SRC_default_default_XC8_assemble_rule(MCU2_SRC_default_default_XC8_assemble)
    list(APPEND MCU2_SRC_default_library_list "$<TARGET_OBJECTS:MCU2_SRC_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(MCU2_SRC_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(MCU2_SRC_default_default_XC8_assemblePreprocess OBJECT ${MCU2_SRC_default_default_XC8_FILE_TYPE_assemblePreprocess})
    MCU2_SRC_default_default_XC8_assemblePreprocess_rule(MCU2_SRC_default_default_XC8_assemblePreprocess)
    list(APPEND MCU2_SRC_default_library_list "$<TARGET_OBJECTS:MCU2_SRC_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(MCU2_SRC_default_default_XC8_FILE_TYPE_compile)
add_library(MCU2_SRC_default_default_XC8_compile OBJECT ${MCU2_SRC_default_default_XC8_FILE_TYPE_compile})
    MCU2_SRC_default_default_XC8_compile_rule(MCU2_SRC_default_default_XC8_compile)
    list(APPEND MCU2_SRC_default_library_list "$<TARGET_OBJECTS:MCU2_SRC_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(MCU2_SRC_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(MCU2_SRC_default_default_XC8_objcopy_avr OBJECT ${MCU2_SRC_default_default_XC8_FILE_TYPE_objcopy_avr})
    MCU2_SRC_default_default_XC8_objcopy_avr_rule(MCU2_SRC_default_default_XC8_objcopy_avr)
    list(APPEND MCU2_SRC_default_library_list "$<TARGET_OBJECTS:MCU2_SRC_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(MCU2_SRC_default_image_p_yG7UKG ${MCU2_SRC_default_library_list})

set_target_properties(MCU2_SRC_default_image_p_yG7UKG PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${MCU2_SRC_default_output_dir}")
target_link_libraries(MCU2_SRC_default_image_p_yG7UKG PRIVATE ${MCU2_SRC_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
MCU2_SRC_default_link_rule( MCU2_SRC_default_image_p_yG7UKG)


#Add objcopy steps
MCU2_SRC_default_objcopy_avr_rule(MCU2_SRC_default_image_p_yG7UKG)

