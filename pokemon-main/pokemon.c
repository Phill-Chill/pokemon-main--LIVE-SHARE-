#include <stdio.h>
//#include <time.h> 
#include <stdlib.h>
#include "PokemonUser.h"
#include "statusPoke.h"
#include "music.h"
//DELAY


void musicbattle(){

        // Caminho para o arquivo de som MP3
    const char *soundFile = "/mnt/c/Users/USER/Downloads/pokemon-mainn/pokemon-main/musica/Trainer Battle - Pokémon Red & Blue Extended.mp3";

    // Comando para tocar o som em loop usando mpg123
    char command[512];
   snprintf(command, sizeof(command), "mpg123 -q --loop -1 \"%s\" &", soundFile);

    // Executa o comando
    system(command);

    return;
}




int main(){

    EeveeSt Eev = {55, 55, 50, 45, 65, 55, 3, 2, 2};    VictiniSt Vic = {100, 100, 100, 100, 100, 100, 3, 2, 2};  BulbasaurSt Bulba = {45, 49, 49, 45, 45, 65, 3, 2, 2};
                                                                                                                  Attbulbasaur ATKbulba[3] ={{3}, {3}, {3}};

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
            victini(Vic);
        
            //INICIA A MECANICA DO JOGO
            for(; Eev.HP > 0 || Vic.HP > 0;){
               
                scanf("%d", &x); 

                if(x == 1){
                                       
                    clear_screen();

                    eeveeAnima(Eev);
                    victini(Vic);
                    
                    sleep_ms(300);
                                       
                    clear_screen();
                    
                    eeveeFront(Eev);
                    victini(Vic);
                    
                 
                  
                }
                else if(x == 2){
                    clear_screen();
                
                    eeveeFront(Eev);
                    victiniBAG(Vic);
                    ITEMvictini(&Vic, Vic.HP, Vic.Attack, Vic.potion, Vic.PP, Vic.DMG);

                    clear_screen();
                    
                    eeveeFront(Eev);
                    victini(Vic);

                    
                }
            }
        
       
        
        }

        if (Eev.HP == 0){
            vitoria++;
        }


//POKMEON USE: BULBASAUR
        else if(poke == 2){
            victiniFront(Vic);
            bulbasaur(Bulba);
        
            while(Vic.HP > 0 || Bulba.HP > 0){
                scanf("%d", &x);

                if(x == 1){

                    //Hpp(&Bulba, &Vic, Vic.HP, Bulba.Attack, Vic.Defense);
                

                clear_screen();
                victiniFront(Vic);
                bulbasaurATT(Bulba, ATKbulba);
                }
                
                else if(x == 2){
                
                    clear_screen();
                    victiniFront(Vic);
                    bulbaBAG(Bulba);          
                
                   ITEMbulbasaur(&Bulba, ATKbulba, Bulba.HP, Bulba.Attack, Bulba.potion, Bulba.PP, Bulba.DMG);
                
                    clear_screen();
                    victiniFront(Vic);
                    bulbasaur(Bulba);  
                }
             
            }  
               
                
        } 
       

        if (Vic.HP == 0) {
            vitoria++;
        }

        if (Vic.HP == 0) {
            vitoria++;
        }
//POKEMON USER: EEVEE
        else if(poke == 3){
            bulbasaurFront(Bulba);
            eevee(Eev);
            
            while(Bulba.HP > 0 || Eev.HP > 0){
                scanf("%d", &x);

                if(x == 1){

                    Hpp(&Eev, &Bulba, Eev.HP, Eev.Attack, Eev.Defense);
                

                clear_screen();
                bulbasaurFront(Bulba);
                eevee(Eev);
                }
                
                else if(x == 2){
                
                    clear_screen();
                    bulbasaurFront(Bulba);
                    eeveeBAG(Eev);          
                
                   ITEMeevee(&Eev, Eev.HP, Eev.Attack, Eev.potion, Eev.PP, Eev.DMG);
                
                    clear_screen();
                    bulbasaurFront(Bulba);
                    eevee(Eev);  
                }
             
            }     
        }

        if (Bulba.HP == 0) {
            vitoria++;
        }

        dialogoFinal(vitoria, nickname);

    
    // Para a música matando o processo mpg123
    system("pkill mpg123");
 //clear_screen();
return 0;
}