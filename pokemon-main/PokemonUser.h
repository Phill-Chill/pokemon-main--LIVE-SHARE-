#ifndef PokemonUSER_H
#define PokemonUSER_H
#include "statusPoke.h"
    void victini(VictiniSt Vic);
    void bulbasaur(BulbasaurSt Bulba);
    void eevee(EeveeSt Eev);
    //FRENTE
    void victiniFront(VictiniSt Vic);
    void bulbasaurFront(BulbasaurSt Bulba);
    void eeveeFront(EeveeSt Eev);
    //MECANICA ATAQUE
    void Hp(VictiniSt *Vic, EeveeSt *Eev, int HP, int Attack, int Defense);
    void Hpp(BulbasaurSt *Bulba, VictiniSt *Vic, int HP, int Attack, int Defense);
    //MECANICA BAG
    void ITEMvictini(VictiniSt *Vic, int HP, int Attack, int potion, int PP, int DMG);
    void ITEMbulbasaur(BulbasaurSt *Bulba, Attbulbasaur ATKbulba[], int HP, int Attack, int potion, int PP, int DMG);
    void ITEMeevee(EeveeSt *Eev, int HP, int Attack, int potion, int PP, int DMG);
    //BAG SPRITES
    void bulbaBAG(BulbasaurSt Bulba);
    void victiniBAG(VictiniSt Vic);
    void eeveeBAG(EeveeSt Eev);
    //ATTACK SPRITES
    void bulbasaurATT(BulbasaurSt Bulba, Attbulbasaur ATKbulba[]);
    //ANIMAÇÃO
    void eeveeAnima(EeveeSt Eev);
    //DIALOGO
    void dialogoInicial(char nickname []);
    void dialogoFinal(int vitoria, char nickname[]);
#endif