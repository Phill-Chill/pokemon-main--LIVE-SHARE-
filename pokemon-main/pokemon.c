#include <stdio.h>
#include <stdlib.h>
#include "PokemonUser.h"
#include "statusPoke.h"
#include "music.h"
// DELAY

int main()
{

    EeveeSt Eev = {55, 45, 50, 45, 65, 55, 3, 2, 2};
    VictiniSt Vic = {50, 55, 40, 55, 55, 100, 3, 2, 2};
    BulbasaurSt Bulba = {45, 49, 49, 45, 45, 65, 3, 2, 2};

    bulbasaurAttacks bulbasaurAtta[4] = {{5, 10, 1, 100}, {15, 3, 1, 85}, {12, 5, 2, 95}, {0, 10, 3, 100}};
    victiniAttacks victiniAtta[4] = {{7, 5, 1, 100}, {12, 10, 2, 85}, {0, 3, 3, 60}, {15, 5, 2, 100}};
    eeveeAttacks EeveeAtta[4] = {{10, 6, 1, 100}, {10, 6, 3, 100}, {15, 3, 2, 85}, {5, 10, 1, 100}};

    void clear_screen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    clear_screen();

    music();
    char nickname[500];
    clear_screen();
    printf("                                                    Digite um nome abaixo:\n                                                    >>>>>>>>>>>>>>>>>>>>>>>\t");
    scanf(" %s", nickname);
    dialogoInicial(nickname);
    // escolha do pokemon
    int poke = 0;
    // navegação de menu
    int x;
    // verificação de vitoria
    int vitoria = 0;
    
    clear_screen();

    printf("\n\n\n                                                                   Escolha seu Pokemon:   1.Victini     2.Bulbasaur     3.Eevee\n");
    for(int num = 0;poke < 1 || poke > 3; num ++){
     scanf("%d", &poke);
     if(num == 1){
        printf("Numero invalido\n");
     }
    }
    system("pkill mpg123");

    clear_screen();
    musicbattle();
 // INICIA A MECANICA DO JOGO
    // POKEMON USER: VICTINI
    if (poke == 1)
    {
        // PRINTA OS POKEMONS
        eeveeFront(Eev);
        victini(&Vic);

       
        while (Eev.HP >= 1 && Vic.HP >= 1)
        {

            scanf("%d", &x);

            if (x == 1)
            {

                clear_screen();
                eeveeFront(Eev);
                victiniATT(Vic, victiniAtta);
                // imprime sprite
                vicAttackSystem(&Vic, victiniAtta, &Eev, EeveeAtta, x, poke);
                // função de ataq
            }
            else if (x == 2)
            {
                clear_screen();

                eeveeFront(Eev);
                victiniBAG(Vic);
                ITEMvictini(&Vic, victiniAtta, Vic.HP, Vic.Attack, Vic.potion, Vic.PP, Vic.DMG);

                clear_screen();

                eeveeFront(Eev);
                victini(&Vic);
                vicAttackSystem(&Vic, victiniAtta, &Eev, EeveeAtta, x, poke);
            }
            clear_screen();
            eeveeFront(Eev);
            victini(&Vic);
        }
        if (Eev.HP <= 0)
        {
            vitoria++;
            clear_screen();
            eeveeAnima(&Eev);
            victini(&Vic);
            sleep_ms(2000);
        }
        else{
            clear_screen();
            eeveeFront(Eev);
            victiniAnimaUser(&Vic);
            sleep_ms(2000);
        }
    }

    // POKMEON USE: BULBASAUR
    else if (poke == 2)
    {
        victiniFront(Vic);
        bulbasaur(&Bulba);

        while (Vic.HP >= 1 && Bulba.HP >= 1)
        {
            scanf("%d", &x);

            if (x == 1)
            {

                clear_screen();
                // imprime sprite
                victiniFront(Vic);
                bulbasaurATT(Bulba, bulbasaurAtta);
                // funçao de ataque
                bulbaAttackSystem(&Bulba, bulbasaurAtta, &Vic, victiniAtta, x, poke);
            }

            else if (x == 2)
            {

                clear_screen();
                // sprites
                victiniFront(Vic);
                bulbaBAG(Bulba);
                // função de itens
                ITEMbulbasaur(&Bulba, bulbasaurAtta);

                clear_screen();
                // sprites
                victiniFront(Vic);
                bulbasaur(&Bulba);
                // função de ataque (para o inimigo)
                bulbaAttackSystem(&Bulba, bulbasaurAtta, &Vic, victiniAtta, x, poke);

                clear_screen();
                // sprites
                victiniFront(Vic);
                bulbasaur(&Bulba);
            }

            clear_screen();
            victiniFront(Vic);
            bulbasaur(&Bulba);
        }
        if (Vic.HP <= 0)
        {
            vitoria++;
            clear_screen();
            victiniAnima(&Vic);
            bulbasaur(&Bulba);
            sleep_ms(2000);
        }
        else
        {
            clear_screen();
            victiniFront(Vic);
            bulbasaurAnimaUser(&Bulba);
            sleep_ms(2000);
        }
    }

    // POKEMON USER: EEVEE
    else if (poke == 3)
    {
        bulbasaurFront(Bulba);
        eevee(&Eev);

        while (Bulba.HP >= 1 && Eev.HP >= 1)
        {
            scanf("%d", &x);

            if (x == 1)
            {

                clear_screen();
                // imprime sprite
                bulbasaurFront(Bulba);
                eeveeATT(Eev, EeveeAtta);

                // função ataque
                eeveeAttackSystem(&Bulba, bulbasaurAtta, &Eev, EeveeAtta, x, poke);
            }

            else if (x == 2)
            {

                clear_screen();
                bulbasaurFront(Bulba);
                eeveeBAG(Eev);

                ITEMeevee(&Eev, EeveeAtta);

                clear_screen();
                bulbasaurFront(Bulba);
                eevee(&Eev);

                eeveeAttackSystem(&Bulba, bulbasaurAtta, &Eev, EeveeAtta, x, poke);

                clear_screen();
                bulbasaurFront(Bulba);
                eevee(&Eev);
            }
            clear_screen();
            bulbasaurFront(Bulba);
            eevee(&Eev);
        }
       
        if (Bulba.HP <= 0)
        {
            vitoria++;
            clear_screen();
            bulbasaurAnima(&Bulba);
            eevee(&Eev);
            sleep_ms(2000);
        }
        else{
            clear_screen();
            bulbasaurFront(Bulba);
            eeveeAnimaUser(&Eev);
            sleep_ms(2000);
        }
    }

    system("pkill mpg123");
    if (vitoria == 1)
    {
        musicVictory();
    }

    else
    {
        const char *soundFile = "musica/nBattle.mp3";

        // Comando para tocar o som em loop usando mpg123
        char command[512];
        snprintf(command, sizeof(command), "mpg123 -q --loop -1 \"%s\" &", soundFile);
        // Executa o comando
        system(command);
    }
    
    dialogoFinal(vitoria, nickname);

    // Para a música
    system("pkill mpg123");
    clear_screen();
    return 0;
}