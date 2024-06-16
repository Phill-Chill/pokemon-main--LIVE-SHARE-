#ifndef Statuspoke_H
#define Statuspoke_H
#include <stdlib.h>
    typedef struct {

        int HP;
        int Attack;
        int Defense;
        int SpAtk;
        int SpDef;
        int Speed;
        //itens
        int potion;
        int PP;
        int DMG;
    //SKILLS
        //int Covet = 60;
        //int Swift = 60; //60% de acerto
        //int Charm = 100; // eevee sempre acerta e diminui o dano de seu oponente  
    } EeveeSt, BulbasaurSt, VictiniSt;
   typedef struct{
        char nome[100];
        int damage;
        int pp;
        char type;
        char style;
        int accuracy;
   }VictiniSt, BulbasaurSt, EeveeSt;/*MESMA DECLARAÇÃO DA STARUCT ACIMA: conflito*/

   // tackle, razor_blade, swift, scratch;
    #endif
