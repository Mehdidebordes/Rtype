# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-src"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-build"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-subbuild/sfml-populate-prefix"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
