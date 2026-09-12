include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(MCU1_SRC_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(MCU1_SRC_default_default_XC8_FILE_TYPE_assemble)
add_library(MCU1_SRC_default_default_XC8_assemble OBJECT ${MCU1_SRC_default_default_XC8_FILE_TYPE_assemble})
    MCU1_SRC_default_default_XC8_assemble_rule(MCU1_SRC_default_default_XC8_assemble)
    list(APPEND MCU1_SRC_default_library_list "$<TARGET_OBJECTS:MCU1_SRC_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(MCU1_SRC_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(MCU1_SRC_default_default_XC8_assemblePreprocess OBJECT ${MCU1_SRC_default_default_XC8_FILE_TYPE_assemblePreprocess})
    MCU1_SRC_default_default_XC8_assemblePreprocess_rule(MCU1_SRC_default_default_XC8_assemblePreprocess)
    list(APPEND MCU1_SRC_default_library_list "$<TARGET_OBJECTS:MCU1_SRC_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(MCU1_SRC_default_default_XC8_FILE_TYPE_compile)
add_library(MCU1_SRC_default_default_XC8_compile OBJECT ${MCU1_SRC_default_default_XC8_FILE_TYPE_compile})
    MCU1_SRC_default_default_XC8_compile_rule(MCU1_SRC_default_default_XC8_compile)
    list(APPEND MCU1_SRC_default_library_list "$<TARGET_OBJECTS:MCU1_SRC_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(MCU1_SRC_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(MCU1_SRC_default_default_XC8_objcopy_avr OBJECT ${MCU1_SRC_default_default_XC8_FILE_TYPE_objcopy_avr})
    MCU1_SRC_default_default_XC8_objcopy_avr_rule(MCU1_SRC_default_default_XC8_objcopy_avr)
    list(APPEND MCU1_SRC_default_library_list "$<TARGET_OBJECTS:MCU1_SRC_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(MCU1_SRC_default_image__0KzttPq ${MCU1_SRC_default_library_list})

set_target_properties(MCU1_SRC_default_image__0KzttPq PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${MCU1_SRC_default_output_dir}")
target_link_libraries(MCU1_SRC_default_image__0KzttPq PRIVATE ${MCU1_SRC_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
MCU1_SRC_default_link_rule( MCU1_SRC_default_image__0KzttPq)


#Add objcopy steps
MCU1_SRC_default_objcopy_avr_rule(MCU1_SRC_default_image__0KzttPq)

