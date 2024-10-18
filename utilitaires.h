// ============================================================
// Authors:
//     - Jack HASCOET
//     - Nathan ANDRE
// Date:   16/10/2024
// Projet: SMP TP_2
// ============================================================
#ifndef _UTILITAIRE_H_
#define _UTILITAIRE_H_

#include "entierlong.h"

/**
 * @brief Convertis un entier cpp en un entierLong
 * 
 * @param integer Nombre à convertir
 * @return t_EntierLong
 */
t_EntierLong converter(int integer);

/**
 * @brief Vérifie l'égalité entre deux valeurs
 * 
 * @param long_1 Nombre long 1
 * @param long_2 Nombre long 2
 * @return true si long_1 est égale à long 2, false sinon
 */
bool equality(t_EntierLong long_1, t_EntierLong long_2);


/**
 * @brief Compare la valeur absolue de deux entier long, long_1 >= long_2
 * 
 * @param long_1 Nombre long à comparé
 * @param long_2 Nombre long servant de comparaison
 * @return true si long_1 >= long_2, false sinon
 */
bool compareAbs(t_EntierLong long_1, t_EntierLong long_2);


#endif