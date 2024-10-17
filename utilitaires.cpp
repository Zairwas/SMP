// ============================================================
// Authors:
//     - Jack HASCOET
//     - Nathan ANDRE
// Date:   16/10/2024
// Projet: SMP TP_2
// ============================================================
#include "utilitaires.h"

#include <stdint.h>
#include <iostream>

t_EntierLong converter(int integer)
{

    uint64_t counter = 0;

    int temp_int = integer;
    t_EntierLong temp_EntierLong = {
        .negatif = 0,
        .chiffres = {0}
    };

    // Test du signe
    if (temp_int < 0)
    {
        temp_EntierLong.negatif = true;
        temp_int = -temp_int; // Invertion du signe pour traiter la valeur absolue
    }

    // Remplissage du tableau de chiffres
    while (counter < MAXCHIFFRES)
    {
        
        temp_EntierLong.chiffres[counter] = temp_int % 10; // Recuperation de l'unite
        temp_int /= 10;                                    // Division par 10 pour "decaler" le nombre vers la droite
        
        counter++;
    }

    return temp_EntierLong;
}

bool compareAbs(t_EntierLong long_1, t_EntierLong long_2) {

    // Vérifie qu'au même index nous avons les mêmes valeurs
    for (int i = MAXCHIFFRES; i >= 0 ; i--)
    {
        if (long_1.chiffres[i] < long_2.chiffres[i])
        {
            return false;
        }
    }

    // Si tout est ok
    return true;
}

bool equality(t_EntierLong long_1, t_EntierLong long_2)
{

    // Vérifie le signe
    if (long_1.negatif != long_2.negatif)
    {
        return false;
    }

    for (int i = 0; i < MAXCHIFFRES; i++)
    {
        if (long_1.chiffres[i] != long_2.chiffres[i])
        {
            return false;
        }
    }

    // Si tout est ok
    return true;
}
