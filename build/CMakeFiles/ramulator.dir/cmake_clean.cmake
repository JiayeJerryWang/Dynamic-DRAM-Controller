file(REMOVE_RECURSE
  "../libramulator.pdb"
  "../libramulator.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/ramulator.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
