# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-src"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-build"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-subbuild/boost-populate-prefix"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-subbuild/boost-populate-prefix/tmp"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-subbuild/boost-populate-prefix/src"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
