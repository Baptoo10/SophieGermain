#include <stdio.h>
#include <stdlib.h>
#include <gmp.h> // pour calculer avec de grands nombres

#include "config.h"


void SophieGermain_prime(mpz_t SGprime) {
 
    gmp_randstate_t gmp_state;
    int checks;

    // Check si le nombre de bits est correct
    if (Bits / 16 > 8) {
        checks = Bits / 16;
    } else {
        checks = 8;
    }

    // Init du generateur aleatoire
    gmp_randinit_default(gmp_state);
    gmp_randseed_ui(gmp_state, time(NULL));

    while (1) {
        // Genere un nombre premier aleatoire SGprime de taille 'Bits - 1'
        mpz_urandomb(SGprime, gmp_state, Bits - 1);
        mpz_nextprime(SGprime, SGprime);

        // SGprime = 2 * SGprime + 1
        mpz_mul_ui(SGprime, SGprime, 2);
        mpz_add_ui(SGprime, SGprime, 1);

        // Test de primalité sur SGprime
        if (mpz_probab_prime_p(SGprime, checks) > 0) {
            break;
        }
    }

    gmp_randclear(gmp_state);
}

int main() {

    mpz_t SGprime;
    mpz_init(SGprime);

    SophieGermain_prime(SGprime);

    gmp_printf("Sophie Germain prime number: %Zd\n", SGprime);

    mpz_clear(SGprime);

    return 0;
}
