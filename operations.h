// ============================================================
// Authors:
//     - Jack HASCOET
//     - Nathan ANDRE
// Date:   16/10/2024
// Projet: SMP TP_2
// ============================================================
#ifndef _OPERATION_H_
#define _OPERATION_H_
#include "entierlong.h"
#include <stdint.h>
#include <cstring>
#include "utilitaires.h"

/**
 * @brief Additionne deux entiers long de même signe
 * 
 * @param el_1 Entier long 1
 * @param el_2 Entier long 2
 * @return t_EntierLong
 */
t_EntierLong addELS(t_EntierLong el_1, t_EntierLong el_2);

/**
 * @brief Soustrait deux entiers long de même signe
 * 
 * @param el_1 Entier long 1
 * @param el_2 Entier long 2
 * @return t_EntierLong 
 */
t_EntierLong subELS(t_EntierLong el_1, t_EntierLong el_2);


/**
 * @brief Additionne deux entiers long de signes différents
 * 
 * @param el_1 Entier long 1
 * @param el_2 Entier long 2
 * @return t_EntierLong
 */
t_EntierLong addEL(t_EntierLong el_1, t_EntierLong el_2);


/**
 * @brief Soustrait deux entiers long de même signe
 * 
 * @param el_1 Entier long 1
 * @param el_2 Entier long 2
 * @return t_EntierLong
 */
t_EntierLong subEL(t_EntierLong el_1, t_EntierLong el_2);

#endif