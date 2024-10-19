// ============================================================
// Authors:
//     - Jack HASCOET
//     - Nathan ANDRE
// Date:   16/10/2024
// Projet: SMP TP_2
// ============================================================

// ============================================================
// =        Includes                                          =
// ============================================================
// Global
#include <stdint.h>
#include <iostream>
#include <cstring>

// Project
#include "entierlong.h"
#include "utilitaires.h"
#include "lit_ecrit.h"
#include "operations.h"

// ============================================================
// =        Prototypes                                        =
// ============================================================
bool test_converter(void);
bool test_compareAbs(void);
bool test_equality(void);
bool test_addELS(void);
bool test_subELS(void);

// ============================================================
// =        Main                                              =
// ============================================================

using namespace std;

int main(int argc, char const *argv[])
{
    test_converter();

    test_compareAbs();

    test_equality();

    test_addELS();

    test_subELS();
    return 0;
}

// ============================================================
// =        Tests                                             =
// ============================================================
bool test_converter(void)
{
    // ========= Cas de Test ==========
    // - 1, -1, 0, 2147483647, -2147483647

    // Variables de tests de verifications
    struct t_EntierLong test_1 = {
        .negatif = false,
        .chiffres = {0}};
    test_1.chiffres[0] = 1;

    struct t_EntierLong test_0 = {
        .negatif = false,
        .chiffres = {0}};

    struct t_EntierLong test_minus_1 = {
        .negatif = true,
        .chiffres = {1}};

    struct t_EntierLong test_max_int = {
        .negatif = false,
        .chiffres = {6, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    struct t_EntierLong test_min_int = {
        .negatif = true,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    struct t_EntierLong num_1 = converter(1);
    struct t_EntierLong num_minus_1 = converter(-1);
    struct t_EntierLong num_0 = converter(0);
    struct t_EntierLong num_max_int = converter(2147483646);
    struct t_EntierLong num_min_int = converter(-2147483647);

    cout << "=====> Test Convertion" << endl;
    cout << "Test: 1, -1, 0, 2147483647, -2147483647" << endl;
    // Test 1
    cout << "int 1\t-> t_EntierLong : ";
    afficheEntierLong(num_1);
    cout << "Verification: " << (memcmp(&num_1, &test_1, sizeof(t_EntierLong)) ? "ERREUR" : "Correct") << endl;

    // Test -1
    cout << "int -1\t-> t_EntierLong : ";
    afficheEntierLong(num_minus_1);
    cout << "Verification: " << (memcmp(&num_minus_1, &test_minus_1, sizeof(t_EntierLong)) ? "ERREUR" : "Correct") << endl;

    // Test 0
    cout << "int 0\t-> t_EntierLong : ";
    afficheEntierLong(num_0);
    cout << "Verification: " << (memcmp(&num_0, &test_0, sizeof(t_EntierLong)) ? "ERREUR" : "Correct") << endl;

    // Test max
    cout << "int 2147483647\t-> t_EntierLong : ";
    afficheEntierLong(num_max_int);
    cout << "Verification: " << (memcmp(&num_max_int, &test_max_int, sizeof(t_EntierLong)) ? "ERREUR" : "Correct") << endl;
    cout << memcmp(&num_max_int, &test_max_int, sizeof(t_EntierLong)) << endl;

    // Test min
    cout << "int -2147483647\t-> t_EntierLong : ";
    afficheEntierLong(num_min_int);
    cout << "Verification: " << (memcmp(&num_minus_1, &test_minus_1, sizeof(t_EntierLong)) ? "ERREUR" : "Correct") << endl;

    return true;
}

bool test_compareAbs(void)
{
    // ========= Cas de Test ==========
    // - 1, -1, 0, 2147483647, -2147483647
    struct t_EntierLong test_1 = {
        .negatif = false,
        .chiffres = {0}};
    test_1.chiffres[0] = 1;

    struct t_EntierLong test_0 = {
        .negatif = false,
        .chiffres = {0}};

    struct t_EntierLong test_minus_1 = {
        .negatif = true,
        .chiffres = {1}};

    struct t_EntierLong test_max_int = {
        .negatif = false,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    struct t_EntierLong test_min_int = {
        .negatif = true,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Entete
    cout << "=====> Test Convertion" << endl;

    // Comparaison de 1 et -1
    cout << "CompAbs |1| >= |-1|: " << (compareAbs(test_1, test_minus_1) ? "True" : "False") << endl;

    // Comparaison de 2147483647 et -2147483647
    cout << "CompAbs |2147483647| >= |-2147483647|: " << (compareAbs(test_max_int, test_min_int) ? "True" : "False") << endl;

    // Comparaison de 2147483647 et -1
    cout << "CompAbs |2147483647| >= |-1|: " << (compareAbs(test_max_int, test_minus_1) ? "True" : "False") << endl;

    // Comparaison de -1 et 2147483647
    cout << "CompAbs |-1| >= |2147483647| : " << (compareAbs(test_minus_1, test_max_int) ? "True" : "False") << endl;

    return true;
}

bool test_equality(void)
{

    // ========= Cas de Test ==========
    // - 1, -1, 0, 2147483647, -2147483647
    struct t_EntierLong test_1 = {
        .negatif = false,
        .chiffres = {0}};
    test_1.chiffres[0] = 1;

    struct t_EntierLong test_0 = {
        .negatif = false,
        .chiffres = {0}};

    struct t_EntierLong test_minus_1 = {
        .negatif = true,
        .chiffres = {1}};

    struct t_EntierLong test_max_int = {
        .negatif = false,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    struct t_EntierLong test_min_int = {
        .negatif = true,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Entete
    cout << "=====> Test Convertion" << endl;

    // Comparaison de 1 et 1
    cout << "CompAbs 1 == 1: " << (equality(test_1, test_1) ? "True" : "False") << endl;
    // Comparaison de 1 et -1
    cout << "CompAbs 1 == -1: " << (equality(test_1, test_minus_1) ? "True" : "False") << endl;

    // Comparaison de 2147483647 et -2147483647
    cout << "CompAbs 2147483647 == -2147483647: " << (equality(test_max_int, test_min_int) ? "True" : "False") << endl;

    // Comparaison de 2147483647 et -1
    cout << "CompAbs 2147483647 >= -1: " << (equality(test_max_int, test_minus_1) ? "True" : "False") << endl;

    // Comparaison de -1 et 2147483647
    cout << "CompAbs -1 == 2147483647 : " << (equality(test_minus_1, test_max_int) ? "True" : "False") << endl;

    // Comparaison de -2147483647 et -2147483647
    cout << "CompAbs -2147483647 == -2147483647: " << (equality(test_min_int, test_min_int) ? "True" : "False") << endl;

    return true;
}

bool test_addELS(void)
{
    struct t_EntierLong test_0 = {
        .negatif = false,
        .chiffres = {0}};
    test_0.chiffres[0] = 0;
    test_0.chiffres[19] = 1;
    test_0.chiffres[18] = 9;

    struct t_EntierLong test_1 = {
        .negatif = false,
        .chiffres = {0}};
    test_1.chiffres[0] = 1;
    test_1.chiffres[19] = 9;

    t_EntierLong abc = addELS(test_1, test_0);
    afficheEntierLong(abc);
}

bool test_subELS(void)
{
    struct t_EntierLong test_0 = {
        .negatif = false,
        .chiffres = {0}};
    test_0.chiffres[0] = 1;

    struct t_EntierLong test_1 = {
        .negatif = false,
        .chiffres = {0}};
    test_1.chiffres[0] = 0;
    test_1.chiffres[1] = 1;


    t_EntierLong abc = subELS(test_1, test_0);
    afficheEntierLong(abc);
}

void fibonnacci(int terme)
{
    t_EntierLong u0 = {false, {0}};
    t_EntierLong u1 = {false, {0}};
    u1.chiffres[0] = 1;

    for (int i = 0; i <= terme; i++)
    {
        if (i == terme)
        {
            if (compareAbs(u0, u1))
            {
                afficheEntierLong(u0);
                afficheEntierLong(u1);
            }
            else
            {
                afficheEntierLong(u1);
                afficheEntierLong(u0);
            }
        }
        if (compareAbs(u0, u1))
        {
            u1 = addELS(u0, u1);
        }
        else
        {
            u0 = addELS(u0, u1);
        }
        if (i == terme)
        {
            compareAbs(u0, u1) ? afficheEntierLong(u0) : afficheEntierLong(u1);
        }
    }
}