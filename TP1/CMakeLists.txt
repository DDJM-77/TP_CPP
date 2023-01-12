# Ceci est un commentaire.
# Retirez le # pour que l'instruction soit prise en compte.

cmake_minimum_required(VERSION 3.13)


if(MSVC)
    add_compile_options(/std:c++17 /W4 /WX)
else()
    add_compile_options(-std=c++17 -Wall -W -Werror)
endif()


# La commande ci-dessous permet de générer un exécutable à partir des fichiers spécifiés.
 add_executable(
     hello-world
     helloworld.cpp
 )
