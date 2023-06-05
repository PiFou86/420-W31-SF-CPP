#pragma once

#include <string>

void demoPointeurs();

void demoConst();


// Pointeurs fonctions
void saluerFrancais(const std::string& p_nom);
void saluerBasque(const std::string& p_nom);
void demoPointeurFonction(void (*p_saluer)(const std::string&));

void demoPointeurObjet();

void demoArithmetiquePointeurs();

void testListeEntiers();