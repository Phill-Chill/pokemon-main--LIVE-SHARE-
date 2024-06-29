#include <stdio.h>
//#include <time.h> 
#include <stdlib.h>
#include "PokemonUser.h"
#include "statusPoke.h"
#include "music.h"
//DELAY


void musicbattle(){

        // Caminho para o arquivo de som MP3
    const char *soundFile = "musica/PokemonBattle.mp3";

    // Comando para tocar o som em loop usando mpg123
    char command[512];
   snprintf(command, sizeof(command), "mpg123 -q --loop -1 \"%s\" &", soundFile);

    // Executa o comando
    system(command);

    return;
}
void musicVictory(){

        // Caminho para o arquivo de som MP3
    const char *soundFile = "musica/Victory.mp3";

    // Comando para tocar o som em loop usando mpg123
    char command[512];
   snprintf(command, sizeof(command), "mpg123 -q --loop -1 \"%s\" &", soundFile);

    // Executa o comando
    system(command);

    return;
}



int main(){

    EeveeSt Eev = {55, 55, 50, 45, 65, 55, 3, 2, 2};    VictiniSt Vic = {50, 65, 40, 55, 55, 100, 3, 2, 2};  BulbasaurSt Bulba = {45, 49, 49, 45, 45, 65, 3, 2, 2};
    
    bulbasaurAttacks bulbasaurAtta[4] = {{5, 10, 1, 100}, {15, 3, 1, 85}, {12, 5, 2, 95}, {0, 10, 3, 100}}; victiniAttacks victiniAtta[4] = {{7, 5, 1, 100}, {12, 10, 2, 85}, {0, 3, 3, 60}, {15, 5, 2, 100}}; eeveeAttacks EeveeAtta[4] = {{10, 6, 1, 100}, {0, 6, 3, 100}, {15, 3, 2, 85}, {5, 10, 1, 100}};

    void clear_screen() {
        #ifdef _WIN32
         system("cls");
        #else
        system("clear");
        #endif
    } 

    clear_screen();

    music();
    char nickname[500];
    printf("Digite um nome abaixo:\n");
    scanf("%s", nickname);

   dialogoInicial(nickname); 
   //escolha do pokemon 
    int poke;
    int x;
    int vitoria = 0;
    
    printf("\n\n                                                    Escolha seu Pokemon: 1.Victini 2.Bulbasaur 3. Eevee\n");
    scanf("%d", &poke);

    clear_screen();
     musicbattle(); 

    //POKEMON USER: VICTINI
        if(poke == 1){
           //PRINTA OS POKEMONS
            eeveeFront(Eev);
            victini(&Vic);
        
            //INICIA A MECANICA DO JOGO
            for(; Eev.HP >= 1 && Vic.HP >= 1;){
               
                scanf("%d", &x); 

                if(x == 1){
                                       
                    clear_screen();
                    eeveeFront(Eev);
                    victiniATT(Vic, victiniAtta);
                    //imprime sprite                                                           
                    vicAttackSystem(&Vic, victiniAtta, &Eev, EeveeAtta, x, poke);
                    //função de ataq

                }
                else if(x == 2){
                    clear_screen();
                
                    eeveeFront(Eev);
                    victiniBAG(Vic);
                    ITEMvictini(&Vic, victiniAtta, Vic.HP, Vic.Attack, Vic.potion, Vic.PP, Vic.DMG);

                    clear_screen();
                    
                    eeveeFront(Eev);
                    victini(&Vic);

                    
                }
                clear_screen();
                eeveeFront(Eev);
                victini(&Vic);
            }
            if (Eev.HP <= 0){
            vitoria++;
            }       
        }

//POKMEON USE: BULBASAUR
        else if(poke == 2){
            victiniFront(Vic);
            bulbasaur(&Bulba);
        
            while(Vic.HP >= 1 && Bulba.HP >= 1){
                scanf("%d", &x);

                if(x == 1){

                clear_screen();
                //imprime sprite
                victiniFront(Vic);
                bulbasaurATT(Bulba, bulbasaurAtta);
                bulbaAttackSystem(&Bulba, bulbasaurAtta, &Vic, victiniAtta, x, poke);

                }
                
                else if(x == 2){
                
                    clear_screen();
                    victiniFront(Vic);
                    bulbaBAG(Bulba);          
                
                   ITEMbulbasaur(&Bulba, bulbasaurAtta);
                  clear_screen();
                    victiniFront(Vic);
                    bulbasaur(&Bulba);
                 bulbaAttackSystem(&Bulba, bulbasaurAtta, &Vic, victiniAtta, x, poke);
                    clear_screen();
                    victiniFront(Vic);
                    bulbasaur(&Bulba);  
                }             
            
                    clear_screen();
                    victiniFront(Vic);
                    bulbasaur(&Bulba);
            }
            if (Vic.HP <= 0){
            vitoria++;
            }
                clear_screen();
                victiniFront(Vic);
                bulbasaurAnimaUser(&Bulba);
                sleep_ms(1000);                         
        } 

//POKEMON USER: EEVEE
        else if(poke == 3){
            bulbasaurFront(Bulba);
            eevee(&Eev);
            
            while(Bulba.HP >= 1 && Eev.HP >= 1){
                scanf("%d", &x);

                if(x == 1){
                   
                    clear_screen();
                    //imprime sprite
                    bulbasaurFront(Bulba);
                    eeveeATT(Eev, EeveeAtta);
                    
                    //função ataque
                    eeveeAttackSystem(&Bulba, bulbasaurAtta, &Eev, EeveeAtta, x, poke);
                }
                
                else if(x == 2){
                
                    clear_screen();
                    bulbasaurFront(Bulba);
                    eeveeBAG(Eev);          
                
                    ITEMeevee(&Eev, EeveeAtta, Eev.HP, Eev.Attack, Eev.potion, Eev.PP, Eev.DMG);
                    eeveeAttackSystem(&Bulba, bulbasaurAtta, &Eev, EeveeAtta, x, poke);
                
                    clear_screen();
                    bulbasaurFront(Bulba);
                    eevee(&Eev);  
                }
                clear_screen();
                bulbasaurFront(Bulba);
                eevee(&Eev);
                
            }
                 clear_screen();
                bulbasaurAnima(&Bulba);
                eevee(&Eev);
                sleep_ms(2000); 
            if (Bulba.HP <= 0) {
            vitoria++;
            }
        }

       
    
        
        system("pkill mpg123");
        
        musicVictory();
        //sleep_ms(2000);
        dialogoFinal(vitoria, nickname);

    
    // Para a música matando o processo mpg123
    system("pkill mpg123");
 //clear_screen();
return 0;
}