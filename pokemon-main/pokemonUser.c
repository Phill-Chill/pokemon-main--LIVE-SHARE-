#include "PokemonUser.h"
#include <stdio.h>
#include "statusPoke.h"
    
//DIALOGOS

void dialogoInicial(void) {

    int escolha;
    printf("Treinador N: Nos encontramos de novo %s... deve ser algum tipo de destino.\nTreinador N: Entretanto, nosso encontro terá um rumo diferente desta vez, pois eu tenho a própria personificação da vitória ao meu lado...\nTreinador N: VICTINI!\n\n", nickname);
	printf("Digite 1 para falar a primeira opção e 2 para falar a segunda:\n[1] Isso acaba aqui N, pare com essa loucura!\n[2] Eu não ligo, já te venci uma vez, posso vencer de novo.\n\n");

	scanf("%d", &escolha);

	while (escolha != 1 && escolha != 2) {

		printf("Digite um número válido!\n");
		scanf("%d", &escolha);
	}

	if (escolha == 1) {

		printf("%s: Isso acaba aqui N, pare com essa loucura!\nTreinador N: Você é igual a todos eles...\nTreinador N: Vê os pokémons como escravos de batalha. Eu só quero que todos tenham a mesma visão que eu, que enxerguem eles como seres vivos e os tratem bem.\nTreinador N: Vamos cortar o papo furado? Victini se voluntariou para lutar ao meu lado, e com isso eu ganharei.\n\n", nickname);
		escolha = 0;
	
	}

	else {

		printf("%s: Eu não ligo, já te venci uma vez, posso vencer de novo.\nTreinador N: Não se ache só porque chegou longe.\nTreinador N: Seu orgulho e confiança na vitória só demonstra como você tratou mal seus pokémons.\nTreinador N: Vamos cortar o papo furado? Assim que isso acabar, irei completar meu plano, e todos os pokémons do mundo serão libertos.\n\n", nickname);
		escolha = 0;
	
	}
    
}   
    //PROTÓTIPO DE ATAQUE    
    void Hp(VictiniSt *Vic, EeveeSt *Eev, int HP, int Attack, int Defense){

       Eev -> HP -= (Vic->Attack / Eev->Defense);
        if(Eev->HP < 0){Eev->HP = 0;}
    };

    void Hpp(BulbasaurSt *Bulba, VictiniSt *Vic, int HP, int Attack, int Defense){
        Vic -> HP -= (Bulba->Attack - Vic->Defense)*-1;
         if(Vic->HP < 0){Vic->HP = 0;}
    }
    //MECANICA ITENS

    void ITEMbulbasaur(BulbasaurSt *Bulba, int HP, int Attack, int potion, int PP, int DMG){
        int escolha;
        scanf("%d", &escolha);

        if(escolha == 1 && potion > 0){
            Bulba -> potion--;
            Bulba -> HP += 20;
        }
        else if(escolha == 2 && PP > 0){
            Bulba -> PP --;
            Bulba ->; //PP do pokemon ++
        }
        else if(escolha == 3 && DMG > 0){
            Bulba -> DMG --;
            Bulba -> Attack += (Attack*0.25);
        }
        else if(escolha == 0){
           return;
        }
    }

    void ITEMvictini(VictiniSt *Vic, int HP, int Attack, int potion, int PP, int DMG){
        int escolha;
        scanf("%d", &escolha);

        if(escolha == 1 && potion > 0){
            Vic -> potion--;
            Vic -> HP += 20;
        }
        else if(escolha == 2 && PP > 0){
            Vic -> PP --;
            Vic ->;//PP do pokemon ++
        }
        else if (escolha == 3 && DMG > 0){
            Vic -> DMG --;
            Vic -> Attack += (Attack*0.25);
        }
        else if(escolha == 0){
           return;
        } 
    }

    void ITEMeevee(EeveeSt *Eev, int HP, int Attack, int potion, int PP, int DMG){
        int escolha;
        scanf("%d", &escolha);

        if(escolha == 1 && potion > 0){
            Eev -> potion--;
            Eev -> HP += 20;
        }
        else if(escolha == 2 && PP > 0){
            Eev -> PP --;
            Eev ->;//PP do pokemon ++
        }
        else if (escolha == 3 && DMG > 0){
            Eev -> DMG --;
            Eev -> Attack += (Attack*0.25);
        }

        else if(escolha == 0){
           return;
        }
    }  
   
    void victini(VictiniSt Vic){

printf("                                                              ███                                   \n");
printf("                                                             ████                                   \n");
printf("                                                           ██████                                   \n");
printf("                              ██████                     █████▓▓█                                   \n");
printf("                               ████████                 █████▓▒▓█                                   \n");
printf("                                ████████               █████▓▒▓█                                    \n");
printf("                                 █████████           ████████▒▓█                                    \n");
printf("                                   ██████████      █████████▒▓██                                    \n");
printf("                                    ███████████   ██████████▓██                                     \n");
printf("                                     ███████████████████████▓██                                     \n");
printf("                                      █████████████████████▓██                                      \n");
printf("                                       ████████████████████▓██                                      \n");
printf("                                         ████████████████████                                       \n");
printf("                                         █████████████▒▒▒▒██                                        \n");
printf("                                        ██▒▒▓███▓████▒▒▒▒▒▒██                                       \n");
printf("                                       ██▒▒▒▒███▓▓██▒▒▒▒▒▒▒▒██                                      \n");
printf("                                       ██▒▒▒█▓▒▒█▒█▒▒▒▒▒▒▒▒▒██                                      \n");
printf("                                       ██▓▒▒▒▓██▒▒▒▒▒▒▒▒▒▒▒▒██                                      \n");
printf("                                        ██▓▒▒▓██▓▒▒▒▒▒▒▒▒▒▒██                                       \n");
printf("                                         ████▒▒▒▒▒▒▒▒▒▒▒▓███                                        \n");
printf("                                      ███   ███▓▒▒▒▒▒████                                           \n");
printf("                                     ██▓▓█   ███▓▓▓▓▓███ ███                                        \n");
printf("                                   ██▓█▓▒▒██▓▓▓█▒▒▒██▒▒██▒▒███ ███                                  \n");
printf("                                  ████▓▒▓▒▒██▓██▓▓█▓███▒▒▓█▓▒█████                                  \n");
printf("                                   ███▓█▒▒▒▒▓██▒▒▒▒█▒▒▒▒▓▒▒▒██▒▓███                                 \n");
printf("                                     ██▒▒▓▒▒▒▒█▒▒█▒▒▒▒▒▒▒██▓████          |//////////////////////////////\n");
printf("                                     ███▒▒▓███▒▓▒▒█▓▓█▒▒▓▒▒████           | Victini     1.Attacks    ///\n");
printf("                                       ████▓██▒▒▒█▓▒▓▒▒▒▓███              |             2.Bag       /// \n");
printf("                                        ███▓▓▓▓██████████▓██              | HP:%03d/100             ///\n",Vic.HP);
printf("                                        ██████████████▓▓████              |//////////////////////////   \n");
printf("                                        █████        ████████                                       \n");
}

    void bulbasaur(BulbasaurSt Bulba){
        

    printf("                                      █▓▒▓▒▓█                                                       \n");
    printf("                                     █▓███▒░▒▓███           ███                                     \n");
    printf("                                     █▓▓▓▓▓░░▒▒░▒█████    ██▓░██                                    \n");
    printf("                                    █▓▒▒░░░▒▓▓░░▒▓███▓▓█▓▒▓▒░▒██                                    \n");
    printf("                                   █▓▒▒░░░░░▒▒▓▓▓▒▒▒▒▓▓▓█▓░░▒▓██                                    \n");
    printf("                                 █▓▒▒░    ░░▒▒▒▒▒██▓▒▒▒▒▓██▓▓▓███                                   \n");
    printf("                                 █▒▒▒░   ░▒▒▒▒▒▒▒▒▒▒█▓▒▒▒██▓▓▓▒▓█                                   \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒██▓▓▓▒░▓█                                  \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▒██▓▓▓▓▓▓██                                  \n");
    printf("                                 ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▓██▓▓▓▓▓▓██                                   \n");
    printf("                                  ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒███▓████████                                    \n");
    printf("                                  ██████▓▒▒▒▒▒▒█████▓▓▓▓▓▓▓▓▓██      |//////////////////////////////\n");
    printf("                                 ██▓▓▓██████████▓▓███▒░▓██▓▓▓██      | Bulbasaur   1.Attacks    /// \n");
    printf("                                 ██████████▓▓██▓▓▓▓██▓▒▒██▓▓██       |             2.Bag       ///  \n");
    printf("                                 █████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██       | HP:%02d/45               /// \n",Bulba.HP);
    printf("                                  ████████▓▓▓▓██▓▓▓▓▓▓▓██████        |//////////////////////////   \n");
    printf("                                   ███████████████████▓██                                           \n");
    }

    void eevee(EeveeSt Eev){

    printf("                                                        ██                                          \n");
    printf("                                                       █▓▓██                                        \n");
    printf("                                                      █▒▒▒▓██                                       \n");
    printf("                                                      █▓▒▒▒██                                       \n");
    printf("                                    ██▒▓██            █▓▒▓▒▒██                                      \n");
    printf("                                    ██▓▒▒▒▓▓██        █▓▓▓▓▓██                                      \n");
    printf("                                     ██▓▓▓▒▒▒▒██       ██▓▓▓██                                      \n");
    printf("                                      ██▓▓▓▓▓▓▒▒█      ██▓▓▓██                                      \n");
    printf("                                       ███▓▓▓▓▓▓▓██ ███▓██▓██                                       \n");
    printf("                               ████      █████▓▓▓█▓▓▒▓▒▒███▓▓▓█                                     \n");
    printf("                               █▒░░▒▓▓▓█     ████▒▒▒▒▒▒▒▓▓▓▓▓▒▓█                                    \n");
    printf("                                ██▒    ▒█     ██▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓██                                   \n");
    printf("                               ██▒▓▒     ▒█   ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██                                   \n");
    printf("                               █▓▒▒▒░ ░░  ░██ ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███                                  \n");
    printf("                              █▓▒▒▒▒▒▒▒▓▒░▒▒▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██                                  \n");
    printf("                              ██▒▒▒▓▓▓▓▓▓▓▒▒▒▓█░█▓▓███████▓▓▓▓▓██                                   \n");
    printf("                             ██▓▓▒▓▓▓▓▓▓▓▓▓▒▒▒▓█▓▒▒░░░░░░▒▒▒▓███                                    \n");
    printf("                             ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█░░░░░░░░░░░░░░▒▒▒▒                                  \n");
    printf("                             ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░░░░░░░▒▒                                 \n");
    printf("                             ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░▒░░░░░░░░░░░░░▒                                 \n");
    printf("                             ███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░█░▒░░░░░░░░░░░▓██                                 \n");
    printf("                              ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████▓█▒░░░░▒░░▒▓▓█                                  \n");
    printf("                               ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓███▓░▓▓██                                     ");     printf("  |//////////////////////////////\n");  
    printf("                                ██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓█████                                      ");     printf("  | Eeevee      1.Attacks    /// \n");
    printf("                                 ████▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓███                                      ");     printf("  |             2.Bag       ///  \n");
    printf("                                    ██████████▓▓▓▓▓▓▓▓▓███▓▒▒██                                     ");     printf("  | HP:%02d/55               ///   \n", Eev.HP);
    printf("                                          ████████████████████                                      ");     printf("  |//////////////////////////     \n");
    printf("                                                █████████                                           ");     printf("                                 \n");   
                                                                                                                          




  
    
    }

    void bulbasaurFront(BulbasaurSt Bulba){

 printf("                                                                                                                                                                 \n");                                
 printf("                                                                                                                                          ▓▓▓▓███                \n");                                
 printf("             ||||||||||||||||||||||||                                                                                          ▒▒▒▒▒▓▓▓▓▓▓▒▒▒▓█▓██               \n");                                
 printf("             | Bulbasaur   -------- |                                                                                       ▒▒▒▒░░░░░░░░░▒▒▒▒▒▓▓██               \n");                                
 printf("             |             -------- |                                                                        ████         ▒▒░░░░░░▒▓▓▒▒▒▒░▒▒▒▒▒▓██               \n");                                
 printf("             | HP:%02d/45           |                                                                       ▓▒░░▓██ ▓▓▓▓▓▓▓▓▓▓▓▓██▒░▒█░░░░░░▒▒▒▓▓▓█              \n", Bulba.HP);                                
 printf("             ||||||||||||||||||||||||                                                                       ▓▒░▒░▒▒▒░░░▒▒▒▒░▒▒▒▒░░░░▒█░░░░░░▒▒▒▓▓▓▓██            \n");                                
 printf("                                                                                                            ▓▓▓░░░░░░▒▓▓▓▓▒░░▒▒▒▒▒▒▒▒▓█▒░░░░▒▒▒▒▓▓▒▒██           \n");                                
 printf("                                                                                                            ▓▒░░░░░░▒▓▓▓▒░░░░▒▒▒▒▒▒▒▒▓█▒░░░▒▒▒▒▒▒▓▓▒▓██          \n");                                
 printf("                                                                                                           ▓▓▓░░░░░░░░░░░░░░░▒▒░▒▓▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓█          \n");                                
 printf("                                                                                                           █▓▓▒░░░░░░▒▓▒░░░▒▓▓▓▒ ░▓▓▓▓▓██▓▒▒▒▒▒▒▒▓▓▒▒▓█          \n");                                
 printf("                                                                                                         ▓▓▒▓▒░▒▒░░░▒▓▒▒░░▒▒▓▒▓▓▒ ▒▒▓▓▓██▓▓▒▒▒▒▒▓▓▒▒▒▓█          \n");                                
 printf("                                                                                                         ▓▓░▒▓░▒▒░░░░░░░░░▒▓█░▒▒▒ ░▒▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒██           \n");                                
 printf("                                                                                                         ▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓██           \n");                                
 printf("                                                                                                         ██▓██▓▒▒▒▒▒▒▒▓▒▒▒▒▒▒▒▒▓████▓▓▓▓▓▓▓▓█▓▓▓▓███             \n");                                
 printf("                                                                                                           █▓▒░▓▓▓▒▒▒▒▒▓▓█████▒▒▓▓▓▓▓▓▓▓▓▓▓▓███▓▓▓▓██            \n");                                
 printf("                                                                                                            ████▓▓▓▓█▓▓▒▒▒▒▓▓▓▓▓▓▓███▓▓▓▓▓▓▓▓▓▓▓▓▓▓██            \n");                                
 printf("                                                                                                                ███▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓█▓▓▓▓█▓▓▓▓██           \n");                                
 printf("                                                                                                                ▓▓▒▓▓▓██▓▓▓▓▓▓▓▓▓▒▒▒▓▓▓▓██▓▓▓▓███▓▓▓██           \n");                                
 printf("                                                                                                                 ▓▓▓▒▒▒▓███▓▓▓▓▓▓▓▒▒▒▓▓▓██▓▓▓▓███▓▓▓██           \n");                                
 printf("                                                                                                                 ▓▓▒▒▒▒▒▓▓████▓▓▒▓▓▒▒▓▓▓███▓▓▓▓▓▓▓▓██            \n");                                
 printf("                                                                                                                  ▓▓▒▒▒▒▓▓██  ▓▒▒▒▒▒▒▓██ ██▒▓▓░▓▒▒█              \n");                                
 printf("                                                                                                                 █▓▒█▓▓█▓██  █▓▒▒▒▒▒▒▓██   ███████               \n");                                
 printf("                                                                                                                   ██████    █████████                           \n");                                
 printf("                                                                                                                                                                 \n");                                
 printf("                                                                                                                                                                 \n");                                
 printf("                                                                                                                                                                 \n");                                
 printf("                                                                                                                                                                 \n");                                
                                                                           
    }                                                                       
                                                                       
    void victiniFront(VictiniSt Vic){                                                                       
                                                                       
printf("                                                                                                                                  ████             \n");                        
printf("                                                                                                                                  ████             \n");                        
printf("              ||||||||||||||||||||||||                                                                                            █▓██             \n");                        
printf("              | Victini     -------- |                                                                                           ██▓▓██            \n");                        
printf("              |             -------- |                                                                                           ██▓▓██            \n");                        
printf("              | HP:%02d/100            |                                                                                           █▓▓▓██            \n", Vic.HP);                        
printf("              ||||||||||||||||||||||||                                                                                          █▓▓▓▓██            \n");                        
printf("                                                                                                    █▓█▓▓▓█████                 █▓▓▓▓▓██           \n");                        
printf("                                                                                                     █▒▒▓▓▓▓▓▓▓███████         ██▓▓▓▓▓██           \n");                        
printf("                                                                                                       █▒   ░▓██▓▓▓▓▓▓███      █▓▓▓▓▓▓██           \n");                        
printf("                                                                                                        ██▓░ ░▒▒▒▓▓██▓▓▓▓▓▓█████▓▓▓▓▓▓██           \n");                        
printf("                                                                                                          ███▓▒▓███▓▓▓▓██▓▓▓▓▓▓█▓▓▓▓▓▓██           \n");                        
printf("                                                                                                             ██▒▒▓█████▓▓▓█▓▓▓▓▓▓▓▓▓▓██            \n");                        
printf("                                                                                                               ██▒▒▓██████▒ ▓█▓▓▓▓▓▓▓███           \n");                        
printf("                                                                                                                ███▒▒▓██░     ░▒▓▓▓▓▓▒░▒██         \n");                        
printf("                                                                                                                  ██▓▒▓   ▒▒▓█▓░ ░▓▓▓▒▒▒░██        \n");                        
printf("                                                                                                                    ██   █▒  ▓██░  ▒▓▒▒██▓▓█       \n");                        
printf("                                                                                                                    ██   █████▒▓░    ▒▓▒▒▓██       \n");                        
printf("                                                                                                                    ██   ░█▓▒▒▓▒ ▒░░▓▒░░░░▒█       \n");                        
printf("                                                                                                                ███  ██    ░▒░   ▓█▓▓█▒  ▒█        \n");                        
printf("                                                                                                         █▓▓▓█████▓█▓▓██▒░       ░▓▓▓░░▒▓█         \n");                        
printf("                                                                                                         █▓░  ▓█▓███ ░██  ██░       ▓██  ███       \n");                        
printf("                                                                                                          ██▓░ ▒████▓▒  ░▒▒▒░▒░▒▒▒▓█████▓▒▓██      \n");                        
printf("                                                                                                           █▓░▒▒▒███▓▒ ░▓▓███▓▒  ░▓█▓▒▒▒▓██████    \n");                        
printf("                                                                                                            ██▒░ ░▒▓██████ ██░▒░  ▒▓█▓░    ▒██     \n");                        
printf("                                                                                                             ██▓██▓▒▒▒██▒██░   ▓░▒░▓█▓███ ░███     \n");                        
printf("                                                                                                              ████▒▒▒█▒▒█░      ░    ░▓███████     \n");                        
printf("                                                                                                                 ███▓███▒▒░░      ░░░░▒██          \n");                        
printf("                                                                                                                      ██▓▒▒▒▒▒▒▓▓▓▒▒▒▒▒██          \n");                        
printf("                                                                                                                      ██▓█▒▒▒██████████▓██         \n");                        
printf("                                                                                                                     ████████        █████         \n");  
                                                                       
    }                                                                       
                                                                       
    void eeveeFront(EeveeSt Eev){                                                                       
                                                                       
printf("                                                                                                                                                   \n");                        
printf("                                                                                                               ▓▓▓▓                                \n");                        
printf("              ||||||||||||||||||||||||                                                                        ▓▓▒▒▓                                \n");                        
printf("              | Eevee       -------- |                                                                       ▓▓▓▓█▓█                               \n");                        
printf("              |             -------- |                                                                       ▓▓▓██▓█               ▓▓▓             \n");                        
printf("              | HP:%02d/55             |                                                                      █▓▓███▓█          ▓▓▒▒▒▒▓█             \n", Eev.HP);                        
printf("              ||||||||||||||||||||||||                                                                      █▓▓██▓█          ▓▒▒▓██▓██             \n");                        
printf("                                                                                                            █▓▓██▓█       ▓▒▒█████▓██              \n");                        
printf("                                                                                                             ███▓███    ▓▓▒▓█████▓██               \n");                        
printf("                                                                                                            ▓▓▓▓▒▒▓▒███▓▒▓█████▓▓██                \n");                        
printf("                                                                                                           ▓▓▒▒▒▒▒▒▓▒▒▓▒▓▒███▓▓██       ▓▓▓        \n");                        
printf("                                                                                                          ▓▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓███   ▓▒▒▒▒▒▒▓█        \n");                        
printf("                                                                                                         ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██    ▓▒▒░░░▒▒▓█         \n");                        
printf("                                                                                                         █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓██  ▓▓▒░░░░░░░░▒█        \n");                        
printf("                                                                                                         ███▓▒▒▒▒▒▒▓░█▒▒▓▓██  ▓▒▒░▒▒░░░░░░▒█       \n");                        
printf("                                                                                                        █▓▒▒▓▓▒▒▒▒▓███▒▓▓▓▒██▓▓▓▒▒▓▒▒▒▒░░░▒▓█      \n");                        
printf("                                                                                                         ▓▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒░░▒▓▓▓▓▓▓▓▓▓▓▒░▒▓▓█      \n");                        
printf("                                                                                                       ▒▒▒▓▓▓▒▒▓▓▒▒▒▓▓▓▓▓░░░░▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓█      \n");                        
printf("                                                                                                      ▒░░░░▒▒▒▒▓▓▓▓▓▓▓▒░░░░░▒█▓▓▓▓▓▓▓▓▓▓▓▓▓▓█      \n");                        
printf("                                                                                                      ▒░░░░░░░░░░░░░▒░░▒▒░░▒▓█▓▓▓▓▓▓▓▓▓▓▓▓▓██      \n");                        
printf("                                                                                                       ▓▒▒░░░░░░░░░░░▒░░▒░░▓██▓▓▓▓▓▓▓▓▓▓▓▓██       \n");                        
printf("                                                                                                        ██▒░░░░░░░░░▒▒░▒▒▒█▓▓▓█▓▓▓▓▓▓▓▓▓▓██        \n");                        
printf("                                                                                                          █▓▒░░░▒▒░▒█▓▒█▓▓▓▓▓▓▓██▓▓▓▓▓███          \n");                        
printf("                                                                                                           █▓▓▓▒▒▒██▓▓▓▓▓█▓▓▓▓▓████████            \n");                        
printf("                                                                                                            █▓▓█▓▓█▓█▒▒▓█▓▓▓▓▓▓██                  \n");                        
printf("                                                                                                          █▓▓▓▓▓▓███▓▒▒▒█▓▓▓▓▓██                   \n");                        
printf("                                                                                                          █▓▓▓▓████▒▒▒▒▓██████                     \n");                        
printf("                                                                                                           █████ ██▓████                           \n");                        
printf("                                                                                                                                                   \n");                        
printf("                                                                                                                                                   \n"); 
    }                                                                      

//BAG ABERTA SPRITES

    void bulbaBAG(BulbasaurSt Bulba){

    printf("                                      █▓▒▓▒▓█                                                       \n");
    printf("                                     █▓███▒░▒▓███           ███                                     \n");
    printf("                                     █▓▓▓▓▓░░▒▒░▒█████    ██▓░██                                    \n");
    printf("                                    █▓▒▒░░░▒▓▓░░▒▓███▓▓█▓▒▓▒░▒██                                    \n");
    printf("                                   █▓▒▒░░░░░▒▒▓▓▓▒▒▒▒▓▓▓█▓░░▒▓██                                    \n");
    printf("                                 █▓▒▒░    ░░▒▒▒▒▒██▓▒▒▒▒▓██▓▓▓███                                   \n");
    printf("                                 █▒▒▒░   ░▒▒▒▒▒▒▒▒▒▒█▓▒▒▒██▓▓▓▒▓█    |//////////////////////////|   \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒██▓▓▓▒░▓█   |::::::::::::::::::::::::::|   \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▒██▓▓▓▓▓▓██   |:1.POTION..............x%d:|   \n",Bulba.potion);
    printf("                                 ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▓██▓▓▓▓▓▓██    |:2.PP..................x%d:|   \n",Bulba.PP);
    printf("                                  ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒███▓████████     |:3.X ATTACK............x%d:|   \n",Bulba.DMG);
    printf("                                  ██████▓▒▒▒▒▒▒█████▓▓▓▓▓▓▓▓▓██      |::::::::::::::::::::::::::|   \n");
    printf("                                 ██▓▓▓██████████▓▓███▒░▓██▓▓▓██      |Press 0 and Enter to back!|   \n");
    printf("                                 ██████████▓▓██▓▓▓▓██▓▒▒██▓▓██       |__________________________|   \n");
    printf("                                 █████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██       | HP:%02d/45                 |   \n",Bulba.HP);
    printf("                                  ████████▓▓▓▓██▓▓▓▓▓▓▓██████        |//////////////////////////|   \n");
    printf("                                   ███████████████████▓██                                           \n");                                                               
                                                                                                    
    }                                                                               

        void victiniBAG(VictiniSt Vic){                                             
                                                                                            
printf("                                                              ███                                   \n");
printf("                                                             ████                                   \n");
printf("                                                           ██████                                   \n");
printf("                              ██████                     █████▓▓█                                   \n");
printf("                               ████████                 █████▓▒▓█                                   \n");
printf("                                ████████               █████▓▒▓█                                    \n");
printf("                                 █████████           ████████▒▓█                                    \n");
printf("                                   ██████████      █████████▒▓██                                    \n");
printf("                                    ███████████   ██████████▓██                                     \n");
printf("                                     ███████████████████████▓██                                     \n");
printf("                                      █████████████████████▓██                                      \n");
printf("                                       ████████████████████▓██                                      \n");
printf("                                         ████████████████████                                       \n");
printf("                                         █████████████▒▒▒▒██                                        \n");
printf("                                        ██▒▒▓███▓████▒▒▒▒▒▒██                                       \n");
printf("                                       ██▒▒▒▒███▓▓██▒▒▒▒▒▒▒▒██                                      \n");
printf("                                       ██▒▒▒█▓▒▒█▒█▒▒▒▒▒▒▒▒▒██                                      \n");
printf("                                       ██▓▒▒▒▓██▒▒▒▒▒▒▒▒▒▒▒▒██                                      \n");
printf("                                        ██▓▒▒▓██▓▒▒▒▒▒▒▒▒▒▒██                                       \n");
printf("                                         ████▒▒▒▒▒▒▒▒▒▒▒▓███                                        \n");
printf("                                      ███   ███▓▒▒▒▒▒████                 |//////////////////////////|\n");
printf("                                     ██▓▓█   ███▓▓▓▓▓███ ███              |::::::::::::::::::::::::::|\n");
printf("                                   ██▓█▓▒▒██▓▓▓█▒▒▒██▒▒██▒▒███ ███        |:1.POTION..............x%d:|\n", Vic.potion);
printf("                                  ████▓▒▓▒▒██▓██▓▓█▓███▒▒▓█▓▒█████        |:2.PP..................x%d:|\n", Vic.PP);
printf("                                   ███▓█▒▒▒▒▓██▒▒▒▒█▒▒▒▒▓▒▒▒██▒▓███       |:3.X ATTACK............x%d:|\n", Vic.Attack);
printf("                                     ██▒▒▓▒▒▒▒█▒▒█▒▒▒▒▒▒▒██▓████          |::::::::::::::::::::::::::|\n");
printf("                                     ███▒▒▓███▒▓▒▒█▓▓█▒▒▓▒▒████           |Press 0 and Enter to back!|\n");
printf("                                       ████▓██▒▒▒█▓▒▓▒▒▒▓███              |__________________________|\n");
printf("                                        ███▓▓▓▓██████████▓██              | HP:%02d/100               |\n",Vic.HP);
printf("                                        ██████████████▓▓████              |//////////////////////////|\n");
printf("                                        █████        ████████                                       \n");
}

void eeveeBAG(EeveeSt Eev){

    printf("                                                        ██                                          \n");
    printf("                                                       █▓▓██                                        \n");
    printf("                                                      █▒▒▒▓██                                       \n");
    printf("                                                      █▓▒▒▒██                                       \n");
    printf("                                    ██▒▓██            █▓▒▓▒▒██                                      \n");
    printf("                                    ██▓▒▒▒▓▓██        █▓▓▓▓▓██                                      \n");
    printf("                                     ██▓▓▓▒▒▒▒██       ██▓▓▓██                                      \n");
    printf("                                      ██▓▓▓▓▓▓▒▒█      ██▓▓▓██                                      \n");
    printf("                                       ███▓▓▓▓▓▓▓██ ███▓██▓██                                       \n");
    printf("                               ████      █████▓▓▓█▓▓▒▓▒▒███▓▓▓█                                     \n");
    printf("                               █▒░░▒▓▓▓█     ████▒▒▒▒▒▒▒▓▓▓▓▓▒▓█                                    \n");
    printf("                                ██▒    ▒█     ██▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓██                                   \n");
    printf("                               ██▒▓▒     ▒█   ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██                                   \n");
    printf("                               █▓▒▒▒░ ░░  ░██ ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███                                  \n");
    printf("                              █▓▒▒▒▒▒▒▒▓▒░▒▒▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██                                  \n");
    printf("                              ██▒▒▒▓▓▓▓▓▓▓▒▒▒▓█░█▓▓███████▓▓▓▓▓██                                   \n");
    printf("                             ██▓▓▒▓▓▓▓▓▓▓▓▓▒▒▒▓█▓▒▒░░░░░░▒▒▒▓███                                    \n");
    printf("                             ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█░░░░░░░░░░░░░░▒▒▒▒    |//////////////////////////|  \n");
    printf("                             ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░░░░░░░▒▒   |::::::::::::::::::::::::::|  \n");
    printf("                             ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░▒░░░░░░░░░░░░░▒   |:1.POTION..............x%d:|  \n", Eev.potion);
    printf("                             ███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░█░▒░░░░░░░░░░░▓██   |:2.PP..................x%d:|  \n", Eev.PP);
    printf("                              ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████▓█▒░░░░▒░░▒▓▓█    |:3.X ATTACK............x%d:|  \n", Eev.Attack);
    printf("                               ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓███▓░▓▓██       |::::::::::::::::::::::::::|  \n");    
    printf("                                ██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓█████        |Press 0 and Enter to back!|  \n"); 
    printf("                                 ████▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓███        |__________________________|  \n"); 
    printf("                                    ██████████▓▓▓▓▓▓▓▓▓███▓▒▒██       | HP:%02d/55                 |  \n", Eev.HP);     
    printf("                                          ████████████████████        |//////////////////////////|  \n");  
    printf("                                                █████████                                           \n");    
                                                                                                                          
    }



//ANIMAÇÃO

void eeveeAnima(EeveeSt Eev){                                                                       
                                                                       
printf("                                         \n");                        
printf("                                         \n");                        
printf("              ||||||||||||||||||||||||   \n");                        
printf("              | Eevee       -------- |   \n");                        
printf("              |             -------- |   \n");                        
printf("              | HP:%02d/55             |   \n", Eev.HP);                        
printf("              ||||||||||||||||||||||||   \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                         \n");                        
printf("                                                                                    \n");
}



void dialogoFinal(vitoria) {

    if (vitoria == 1) {
        int escolha;

		printf("Treinador N: ...\nTreinador N: Hahahaha... eu perdi, né?\nTreinador N: Nunca pensei que pokémons poderiam lutar com tanto vigor... seus pokémons não estavam sendo forçados...\nTreinador N: Eles estavam lutando por vontade própria, para defender você.\n\n");
	
		printf("Digite 1 para falar a primeira opção e 2 para falar a segunda:\n[1] Eu te disse N, nem todos os treinadores são ruins. Você deveria dar uma outra chance para o mundo.\n[2] Sua visão de mundo estava errada N, nem sempre o mundo é preto e branco, assim como mesmo com Victini ao seu lado, você perdeu.\n\n");

		scanf("%d", &escolha);

		while (escolha != 1 || escolha != 2) {

			printf("Digite um número válido!\n");
			scanf("%d", &escolha);
		}

	    if (escolha == 1) {
	
		    printf("X: Eu te disse N, nem todos os treinadores são ruins. Você deveria dar uma outra chance para o mundo.\nTreinador N: Você está certo... você me mostrou outras possibilidades, X.\nTreinador N: Que não existe só a minha realidade... um jovem sonhador que fez por merecer...\nTreinador N: E esse jovem é você. Até a próxima.\n\n");
		    escolha = 0;
	    }

	    else {
		    printf("X: Sua visão de mundo estava errada N, nem sempre o mundo é preto e branco, assim como mesmo com Victini ao seu lado, você perdeu.\nTreinador N: Tem razão, o mundo é um cinza que testa seus ideais.\nTreinador N: Vivenciei incontáveis coisas durante essa jornada...\nTreinador N: Vou viajar para bem longe e repensar minhas ideias. Se cuida X.\n\n");
		    escolha = 0;
	        }
        }

        else if (vitoria == 0) {

		    printf("Treinador N: Como eu te disse, %s... sua amizade com seus pokémons não é forte o bastante. Patético.\n");
		    printf("Digite 1 para falar a primeira opção e 2 para falar a segunda:\n[1] Eu posso ter perdido, N, mas isso não quer dizer que você esteja certo.\n[2] Impossível eu ter perdido, você trapaçeou!\n\n");

		    scanf("%d", &escolha);

		    while (escolha != 1 || escolha != 2) {

			    printf("Digite um número válido!\n");
			    scanf("%d", &escolha);
		    }
		
		    if (escolha == 1) {
		
		        printf("%s: Eu posso ter perdido, N, mas isso não quer dizer que você esteja certo.\nTreinador N: Isso quer sim que eu estou certo, meus ideais foram mais fortes, agora ninguém poderá impedir meu plano.\nTreinador N: A gente se vê por aí, %s.\n", nickname, nickname);
		
		    }
		
		    else {
		
		        printf("%s: Impossível eu ter perdido, você trapaçeou!\nTreinador N: Sério, %s? Me acusando de trapaça? Não pensei que você chegaria tão baixo... isso mostra tanto sobre você.\nTreinador N: Enfim, eu vou mudar o mundo, a gente se vê por aí, %s\n", nickname, nickname);
		
		    }
		
	    }
    
}
