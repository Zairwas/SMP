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
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"

// ============================================================
// =        Prototypes                                        =
// ============================================================
bool test_converter(void);
bool test_compareAbs(void);
bool test_equality(void);

bool test_addELS(void);
bool test_subELS(void);
bool test_addEL(void);
bool test_subEL(void);
bool test_fibonacci(void);

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

    test_addEL();
    test_subEL();

    test_fibonacci();
    return 0;
}

// ============================================================
// =        Tests                                             =
// ============================================================

bool test_addELS(void) {

    // ========= Cas de Test ==========
    // - 1, 2, -1, 0, 2147483647, -2147483647 
    struct t_EntierLong test_1 = {  // 1
        .negatif = false,
        .chiffres = {0}
    };
    test_1.chiffres[0] = 1;

    struct t_EntierLong test_2 = {  // 2
        .negatif = false,
        .chiffres = {0}
    };
    test_2.chiffres[0] = 2;

    struct t_EntierLong test_0 = { // 0
        .negatif = false,
        .chiffres = {0}
    };

    struct t_EntierLong test_minus_1 = {    // -1
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_1.chiffres[0] = 1; 

    struct t_EntierLong test_minus_2 = {    // -2
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_2.chiffres[0] = 2; 

    struct t_EntierLong test_max_int = {    // 2147483647
        .negatif = false,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_double_max_int = {    // 4294967294
        .negatif = false,
        .chiffres = {4, 9, 2, 7, 6, 9, 4, 9, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    struct t_EntierLong test_min_int = {    // -2147483647
        .negatif = true,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_result;

    cout << "=====> Test Addition meme signe" << endl; 
    cout << "(Necesite le bon fonctionnement de la fonction equality(...))" << endl; 

    // Test 1 + 1
    test_result = addELS(test_1, test_1);
    cout << "1 + 1 = 2 ? " << (equality(test_result, test_2) ? "True" : "FALSE") << endl;
    
    // Test 0 + 0
    test_result = addELS(test_0, test_0);
    cout << "0 + 0 = 0 ? " << (equality(test_result, test_0) ? "True" : "FALSE") << endl;

    // Test 1 + 0
    test_result = addELS(test_1, test_0);
    cout << "1 + 0 = 1 ? " << (equality(test_result, test_1) ? "True" : "FALSE") << endl;
    
    // Test (-1) + (-1)
    test_result = addELS(test_minus_1, test_minus_1);
    cout << "(-1) + (-1) = -2 ? " << (equality(test_result, test_minus_2) ? "True" : "FALSE") << endl;
    
    // Test 2147483647 + 2147483647
    test_result = addELS(test_max_int, test_max_int);
    cout << "2147483647 + 2147483647 = 4294967294 ? " << (equality(test_result, test_double_max_int) ? "True" : "FALSE") << endl;

    return true;
}

bool test_subELS(void) {

    // ========= Cas de Test ==========
    // - 1, 2, -1, 0, 2147483647, -2147483647 
    struct t_EntierLong test_1 = {  // 1
        .negatif = false,
        .chiffres = {0}
    };
    test_1.chiffres[0] = 1;

    struct t_EntierLong test_2 = {  // 2
        .negatif = false,
        .chiffres = {0}
    };
    test_2.chiffres[0] = 2;

    struct t_EntierLong test_0 = { // 0
        .negatif = false,
        .chiffres = {0}
    };

    struct t_EntierLong test_minus_1 = {    // -1
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_1.chiffres[0] = 1; 

    struct t_EntierLong test_minus_2 = {    // -2
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_2.chiffres[0] = 2; 

    struct t_EntierLong test_max_int = {    // 2147483647
        .negatif = false,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_double_max_int = {    // 4294967294
        .negatif = false,
        .chiffres = {4, 9, 2, 7, 6, 9, 4, 9, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    struct t_EntierLong test_min_int = {    // -2147483647
        .negatif = true,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_double_min_int = {    // -4294967294
        .negatif = true,
        .chiffres = {4, 9, 2, 7, 6, 9, 4, 9, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_result;

    cout << "=====> Test Soustraction meme signe" << endl; 
    cout << "(Necesite le bon fonctionnement de la fonction equality(...))" << endl; 

    // Test 1 - 1
    test_result = subELS(test_1, test_1);
    cout << "1 - 1 = 0 ? " << (equality(test_result, test_0) ? "True" : "FALSE") << endl;
    
    // Test 0 - 0
    test_result = subELS(test_0, test_0);
    cout << "0 - 0 = 0 ? " << (equality(test_result, test_0) ? "True" : "FALSE") << endl;

    // // Test 0 - 2
    // test_result = subELS(test_0, test_2);
    // cout << "0 - 2 = -2 ? " << (equality(test_result, test_minus_2) ? "True" : "FALSE") << endl;
    
    // Test (-1) - (-1)
    test_result = subELS(test_minus_1, test_minus_1);
    cout << "(-1) - (-1) = 0 ? " << (equality(test_result, test_0) ? "True" : "FALSE") << endl;
    
    // Test (-1) - (-2)
    test_result = subELS(test_minus_1, test_minus_2);
    cout << "(-1) - (-2) = 1 ? " << (equality(test_result, test_1) ? "True" : "FALSE") << endl;

    // // Test 0 - 2147483647
    // test_result = subELS(test_0, test_max_int);
    // cout << "0 - 2147483647 = -2147483647 ? " << (equality(test_result, test_min_int) ? "True" : "FALSE") << endl;
    
    return true;

}

bool test_addEL(void) {

    // ========= Cas de Test ==========
    // - 1, 2, -1, 0, 2147483647, -2147483647 
    struct t_EntierLong test_1 = {  // 1
        .negatif = false,
        .chiffres = {0}
    };
    test_1.chiffres[0] = 1;

    struct t_EntierLong test_2 = {  // 2
        .negatif = false,
        .chiffres = {0}
    };
    test_2.chiffres[0] = 2;

    struct t_EntierLong test_0 = { // 0
        .negatif = false,
        .chiffres = {0}
    };

    struct t_EntierLong test_minus_1 = {    // -1
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_1.chiffres[0] = 1; 

    struct t_EntierLong test_minus_2 = {    // -2
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_2.chiffres[0] = 2; 

    struct t_EntierLong test_max_int = {    // 2147483647
        .negatif = false,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_double_max_int = {    // 4294967294
        .negatif = false,
        .chiffres = {4, 9, 2, 7, 6, 9, 4, 9, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    struct t_EntierLong test_min_int = {    // -2147483647
        .negatif = true,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_double_min_int = {    // -4294967294
        .negatif = true,
        .chiffres = {4, 9, 2, 7, 6, 9, 4, 9, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_result;

    cout << "=====> Test Additions signes differents" << endl; 
    cout << "(Necesite le bon fonctionnement de la fonction equality(...))" << endl; 

    // Test 1 + (-1)
    test_result = addEL(test_1, test_minus_1);
    cout << "1 + (-1) = 0 ? " << (equality(test_result, test_0) ? "True" : "FALSE") << endl;
    
    // Test 0 + (-2)
    test_result = addEL(test_0, test_minus_2);
    cout << "0 + (-2) = -2 ? " << (equality(test_result, test_minus_2) ? "True" : "FALSE") << endl;

    // Test (-1) + 2
    test_result = addEL(test_minus_1, test_2);
    cout << "(-1) + 2 = 1 ? " << (equality(test_result, test_1) ? "True" : "FALSE") << endl;
    
    // Test 4294967294 + (-2147483647)
    test_result = addEL(test_double_max_int, test_min_int);
    cout << "4294967294 + (-2147483647) = 2147483647 ? " << (equality(test_result, test_max_int) ? "True" : "FALSE") << endl;

    return true;

}

bool test_subEL(void) {

    // ========= Cas de Test ==========
    // - 1, 2, -1, 0, 2147483647, -2147483647 
    struct t_EntierLong test_1 = {  // 1
        .negatif = false,
        .chiffres = {0}
    };
    test_1.chiffres[0] = 1;

    struct t_EntierLong test_2 = {  // 2
        .negatif = false,
        .chiffres = {0}
    };
    test_2.chiffres[0] = 2;

    struct t_EntierLong test_0 = { // 0
        .negatif = false,
        .chiffres = {0}
    };

    struct t_EntierLong test_minus_1 = {    // -1
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_1.chiffres[0] = 1; 

    struct t_EntierLong test_minus_2 = {    // -2
        .negatif = true,
        .chiffres = {0}
    };
    test_minus_2.chiffres[0] = 2; 

    struct t_EntierLong test_max_int = {    // 2147483647
        .negatif = false,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_double_max_int = {    // 4294967294
        .negatif = false,
        .chiffres = {4, 9, 2, 7, 6, 9, 4, 9, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    struct t_EntierLong test_min_int = {    // -2147483647
        .negatif = true,
        .chiffres = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_double_min_int = {    // -4294967294
        .negatif = true,
        .chiffres = {4, 9, 2, 7, 6, 9, 4, 9, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct t_EntierLong test_result;

    cout << "=====> Test Soustraction signe different" << endl; 
    cout << "(Necesite le bon fonctionnement de la fonction equality(...))" << endl; 

    // Test 1 - (-1)
    test_result = subEL(test_1, test_minus_1);
    cout << "1 - (-1) = 2 ? " << (equality(test_result, test_2) ? "True" : "FALSE") << endl;
    
    // Test 0 - (-2)
    test_result = subEL(test_0, test_minus_2);
    cout << "0 - (-2) = 2 ? " << (equality(test_result, test_2) ? "True" : "FALSE") << endl;

    // Test (-1) + 2
    test_result = subEL(test_minus_1, test_2);
    cout << "(-1) - 1 = -2 ? " << (equality(test_result, test_minus_2) ? "True" : "FALSE") << endl;
    
    // Test 2147483647 - (-2147483647)
    test_result = subEL(test_max_int, test_min_int);
    cout << "2147483647 - (-2147483647) = 4294967294 ? " << (equality(test_result, test_double_max_int) ? "True" : "FALSE") << endl;

    return true;
}

bool test_converter(void) {
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
        .chiffres = {0}
    };
    test_minus_1.chiffres[0] = 1; 

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
        .chiffres = {0}
    };
    test_minus_1.chiffres[0] = 1; 

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
        .chiffres = {0}
    };
    test_minus_1.chiffres[0] = 1; 

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

void fibonacci(int terme)
{
    t_EntierLong u0 = {false, {0}};
    t_EntierLong u1 = {false, {0}};
    u1.chiffres[0] = 1;

    for (int i = 2; i <= terme; i++)
    {
        t_EntierLong tmp = addELS(u0, u1);  // Calcul du prochain terme
        
        if (i == terme)
        {
            if (compareAbs(u0, u1))
            {
                cout << "U" << terme - 2 << ": ";
                afficheEntierLong(u1);
                cout << "U" << terme - 1 << ": ";
                afficheEntierLong(u0);
            }
            else
            {
                cout << "U" << terme - 2 << " = ";
                afficheEntierLong(u0);
                cout << "U" << terme - 1 << " = ";
                afficheEntierLong(u1);
            }
            cout << "U" << terme << " = ";
            afficheEntierLong(tmp);

        }
        u0 = u1;
        u1 = tmp;
        
    }
}

bool test_fibonacci(void) {
    cout << "Fibonacci de 10" << endl;
    fibonacci(10);
    cout << "Fibonacci de 20" << endl;
    fibonacci(20);
    cout << "Fibonacci de 30" << endl;
    fibonacci(30);
    cout << "Fibonacci de 40" << endl;
    fibonacci(40);
    cout << "Fibonacci de 20 000" << endl;
    fibonacci(20000);
    return true;
}