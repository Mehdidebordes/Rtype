# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-src"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-build"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-subbuild/asio-populate-prefix"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-subbuild/asio-populate-prefix/tmp"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-subbuild/asio-populate-prefix/src/asio-populate-stamp"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-subbuild/asio-populate-prefix/src"
  "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-subbuild/asio-populate-prefix/src/asio-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-subbuild/asio-populate-prefix/src/asio-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/mehdi/TEK_3/Projet_présentation/B-CPP-500-MPL-5-1-rtype-phearoak.em/_deps/asio-subbuild/asio-populate-prefix/src/asio-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
