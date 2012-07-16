set(CTEST_PROJECT_NAME "dsncompat")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

if(NOT DEFINED CTEST_DROP_METHOD)
  set(CTEST_DROP_METHOD "http")
endif(NOT DEFINED CTEST_DROP_METHOD)

if(CTEST_DROP_METHOD STREQUAL "http")
  set(CTEST_DROP_SITE "harpy.png.das-system.vpn")
  set(CTEST_DROP_LOCATION "/cdash/submit.php?project=dsncompat")
  set(CTEST_TRIGGER_SITE "http://${CTEST_DROP_SITE}/")
endif(CTEST_DROP_METHOD STREQUAL "http")
