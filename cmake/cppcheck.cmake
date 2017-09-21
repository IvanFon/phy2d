# Target for cppcheck
# Make sure you find cppcheck first!
#
# Variables:
# CPPCHECK_SOURCES - sources that should be analysed
# CPPCHECK_ARGS - arguments to pass to cppcheck

# Check if cppcheck has already been found
if (NOT CPPCHECK_FOUND)
message (FATAL_ERROR
  "Error: cppcheck not found. Make sure
  you use Findcppcheck.cmake first!"
)
endif ()

# cppcheck arguments
set (CPPCHECK_ARGS "--enable=warning,performance,information,style")

add_custom_target (
cppcheck
COMMAND ${CPPCHECK_BIN}
${CPPCHECK_ARGS}
${CPPCHECK_SOURCES}
)
