// ============================================================
// Authors:
//     - Jack HASCOET
//     - Nathan ANDRE
// Date:   16/10/2024
// Projet: SMP TP_2
// ============================================================

#include "operations.h"

t_EntierLong addELS(t_EntierLong el_1, t_EntierLong el_2)
{
    int chiffres[MAXCHIFFRES] = {0};
    int somme;
    for (int i = 0; i < MAXCHIFFRES; i++)
    {
        somme = el_1.chiffres[i] + el_2.chiffres[i];

        chiffres[i] += somme % 10;

        if (i + 1 < MAXCHIFFRES)
        {
            chiffres[i + 1] = somme / 10;
        }
    }

    struct t_EntierLong resEl = {
        .negatif = el_1.negatif};
    memcpy(resEl.chiffres, chiffres, sizeof(int) * MAXCHIFFRES);

    return resEl;
}

t_EntierLong subELS(t_EntierLong el_1, t_EntierLong el_2)
{
    bool retenu;
    t_EntierLong high_el = compareAbs(el_1, el_2) ? el_1 : el_2;
    t_EntierLong low_el = !compareAbs(el_1, el_2) ? el_1 : el_2;
    int chiffres[MAXCHIFFRES] = {0};

    for (int i = 0; i > MAXCHIFFRES; i++)
    {
        retenu = false;
        chiffres[i] = high_el.chiffres[i] - low_el.chiffres[i];
        if (chiffres[i] < 0)
        {
            chiffres[i] = (10 + high_el.chiffres[i]) - low_el.chiffres[i];
            retenu = true;
        }

        if (retenu)
        {
            bool added = false;
            int j = i + 1;
            while (j < MAXCHIFFRES && !added)
            {
                if (low_el.chiffres[j] < 9)
                {
                    low_el.chiffres[i + 1] += 1;
                    added = true;
                } else {
                    low_el.chiffres[j] = 0;
                }
                j++;
            }
        }
    }
    struct t_EntierLong resEl = {
        .negatif = el_1.negatif};
    memcpy(resEl.chiffres, chiffres, sizeof(int) * MAXCHIFFRES);

    return resEl;
}

t_EntierLong addEL(t_EntierLong el_1, t_EntierLong el_2)
{
}

t_EntierLong subEL(t_EntierLong el_1, t_EntierLong el_2)
{
}