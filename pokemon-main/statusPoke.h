#ifndef Statuspoke_H
#define Statuspoke_H
#include <stdlib.h>
typedef struct
{

    int HP;
    int Attack;
    int Defense;
    int SpAtk;
    int SpDef;
    int Speed;
    // itens
    int potion;
    int PP;
    int DMG;

} EeveeSt, BulbasaurSt, VictiniSt;
typedef struct
{
    int damage;
    int pp;
    int attackStyle;
    // Se o ataque é físico (1) especial (2) status (3)
    int accuracy;
} bulbasaurAttacks, victiniAttacks, eeveeAttacks;
// VictiniSt, BulbasaurSt, EeveeSt;/*MESMA DECLARAÇÃO DA STARUCT ACIMA: conflito*/

#endif
