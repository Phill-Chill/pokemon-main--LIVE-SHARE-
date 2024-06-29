#ifndef PokemonUSER_H
#define PokemonUSER_H
#include "statusPoke.h"
void victini(VictiniSt *Vic);
void bulbasaur(BulbasaurSt *Bulba);
void eevee(EeveeSt *Eev);
// FRENTE
void victiniFront(VictiniSt Vic);
void bulbasaurFront(BulbasaurSt Bulba);
void eeveeFront(EeveeSt Eev);
// MECANICA ATAQUE
void bulbaAttackSystem(BulbasaurSt *Bulba, bulbasaurAttacks bulbasaurAtta[], VictiniSt *Vic, victiniAttacks victiniAtta[], int x, int poke);
void vicAttackSystem(VictiniSt *Vic, victiniAttacks victiniAtta[], EeveeSt *Eev, eeveeAttacks EeveeAtta[], int x, int poke);
void eeveeAttackSystem(BulbasaurSt *Bulba, bulbasaurAttacks bulbasaurAtta[], EeveeSt *Eev, eeveeAttacks EeveeAtta[], int x, int poke);

// MECANICA BAG
void ITEMvictini(VictiniSt *Vic, victiniAttacks *victiniAtta, int HP, int Attack, int potion, int PP, int DMG);
void ITEMbulbasaur(BulbasaurSt *Bulba, bulbasaurAttacks *bulbasaurAtta);
void ITEMeevee(EeveeSt *Eev, eeveeAttacks *EeveeAtta);
// BAG SPRITES
void bulbaBAG(BulbasaurSt Bulba);
void victiniBAG(VictiniSt Vic);
void eeveeBAG(EeveeSt Eev);
// ATTACK SPRITES
void bulbasaurATT(BulbasaurSt Bulba, bulbasaurAttacks bulbasaurAtta[]);
void victiniATT(VictiniSt Vic, victiniAttacks victiniAtta[]);
void eeveeATT(EeveeSt Eev, eeveeAttacks eeveeAtta[]);
// ANIMAÇÃO

void victiniAnima(VictiniSt *Vic);
void eeveeAnima(EeveeSt *Eev);
void bulbasaurAnima(BulbasaurSt *Bulba);
void bulbasaurAnimaUser(BulbasaurSt *Bulba);
void eeveeAnimaUser(EeveeSt *Eev);
void victiniAnimaUser(VictiniSt *Vic);
// DIALOGO
void dialogoInicial(char nickname[]);
void dialogoFinal(int vitoria, char nickname[]);
#endif