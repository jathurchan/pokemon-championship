
# ---- Global Cmake Targets ----

# Generate all cpp headers
add_custom_target(generate-headers)

# Clean all cpp headers created using "generate-headers" target
add_custom_target(clean-headers
  COMMAND rm -vf ${PROJECT_SOURCE_DIR}/src/*/*.hpp
  COMMAND rm -vf ${PROJECT_SOURCE_DIR}/src/*/*/*.hpp
  COMMAND rm -f ${PROJECT_BINARY_DIR}/generate_header_*.stamp
)


# ---- Functions ----

# Generate cpp header files from dia files using dia2code.
# Input: dia filename (DIA FILE MUST CONTAIN ONLY 1 NAMESPACE WITH THE SAME NAME)
function(generate_dia_header dia_file)

  # Path to the .dia file used to generate the cpp headers
  get_filename_component(namespace ${dia_file} NAME_WE)

  # Path to the output directory
  set(output_dir ${CMAKE_CURRENT_SOURCE_DIR})

  # Stamp file that take care of the dependency chain
  set(stamp ${PROJECT_BINARY_DIR}/generate_header_${namespace}.stamp)

  # Custom command that generate the cpp headers and create the stamp file
  add_custom_command(
    OUTPUT ${stamp}
    COMMAND rm -vf ${PROJECT_SOURCE_DIR}/src/*/${namespace}.hpp
    COMMAND rm -vf ${PROJECT_SOURCE_DIR}/src/*/${namespace}/*.hpp
    COMMAND $<TARGET_FILE:dia2code> -ns ${namespace} -d ${output_dir} -ext hpp -t cpp ${dia_file}
    COMMAND ${CMAKE_COMMAND} -E touch ${stamp}
    DEPENDS ${dia_file}
    )

  # Create cmake intermediate target to generate the cpp headers
  add_custom_target(generate-header-${namespace} DEPENDS ${stamp})

  # Add the intermediate target as a dependency of the global cmake target for header
  # generation.
  add_dependencies(generate-headers generate-header-${namespace})

endfunction()