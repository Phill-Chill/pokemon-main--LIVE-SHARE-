#include "PokemonUser.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "statusPoke.h"
#include "music.h"

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// DIALOGOS

void dialogoInicial(char nickname[])
{

    int escolha;

    FILE *arquivo;
    clear_screen();
    char nomeArquivo[] = "dialogo/nInicial.txt"; // Nome do arquivo

    char linha[100];

    // Abre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    // Lê e imprime cada linha do arquivo
    printf("Conteúdo do arquivo %s:\n", nomeArquivo);
    while (fgets(linha, sizeof(linha), arquivo))
    {
        printf("%s", linha);
    }

    // Fecha o arquivo
    fclose(arquivo);

    scanf("%d", &escolha);

    while (escolha < 1 || escolha > 2)
    {

        printf("Digite um número válido!\n");
        scanf("%d ", &escolha);
    }

    if (escolha == 1)
    {

        printf("                                                            %s: Isso acaba aqui N, pare com essa loucura!\n\n                                                                                                Treinador N: Você é igual a todos eles...\n                                                                                                Treinador N: Vê os pokémons como escravos de batalha. Eu só quero que todos tenham a mesma visão que eu, que enxerguem eles como seres vivos e os tratem bem.\n                                                                                                Treinador N: Vamos cortar o papo furado? Victini se voluntariou para lutar ao meu lado, e com isso eu ganharei.\n", nickname);
    }

    else
    {

        printf("                                                            %s: Eu não ligo, já te venci uma vez, posso vencer de novo.\n\n                                                                                                Treinador N: Não se ache só porque chegou longe.\n                                                                                                Treinador N: Seu orgulho e confiança na vitória só demonstra como você tratou mal seus pokémons.\n                                                                                                Treinador N: Vamos cortar o papo furado? Assim que isso acabar, irei completar meu plano, e todos os pokémons do mundo serão libertos.\n\n", nickname);
    }
     //sleep_ms(6000);
     getchar();
     getchar();
    return;
}
// PROTÓTIPO DE ATAQUE

// Victini vs Eevee

void vicAttackSystem(VictiniSt *Vic, victiniAttacks victiniAtta[], EeveeSt *Eev, eeveeAttacks EeveeAtta[], int x, int poke)
{

    srand(time(0));
    int iMusic = rand() % 4;
    int i = -1;
    int g = rand() % 100;

    int chooseAttack = -1;
    int acertou = 0;
    if (x != 2)
    {
        while(chooseAttack < 1 || chooseAttack > 4){
        scanf("%d", &chooseAttack);
        }
    }
    chooseAttack--;
    int accuTempVic = victiniAtta[chooseAttack].accuracy;
    int accuTempEev = EeveeAtta[iMusic].accuracy;

    if (x != 2)
    {
        if (victiniAtta[chooseAttack].pp != 0)
        {

            if (victiniAtta[chooseAttack].attackStyle == 1)
            {

                if (accuTempVic >= g)
                {

                    Eev->HP -= (victiniAtta[chooseAttack].damage + ((Vic->Attack - Eev->Defense) * 0.25));

                    printf("                           Victini usou Thunder Punch!\n");                    
                    sleep_ms(1000);
                    Attacksound(&chooseAttack, &i, poke);

                    clear_screen();
                    eeveeAnima(Eev);
                    victini(Vic);

                    sleep_ms(500);
                    clear_screen();
                    eeveeFront(*Eev);
                    victini(Vic);
                }

                else
                {

                    printf("                           Victini errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else if (victiniAtta[chooseAttack].attackStyle == 2)
            {

                if (accuTempVic >= g)
                {

                    Eev->HP -= (victiniAtta[chooseAttack].damage + ((Vic->SpAtk - Eev->SpDef) * 0.25));
                    if (chooseAttack == 1)
                    {                      
                        printf("                           Victini usou Fire Spin!\n");
                        sleep_ms(1000); 
                        Attacksound(&chooseAttack, &i, poke);
                    }
                    else
                    {                      
                        printf("                           Victini usou Swift!\n");
                        sleep_ms(1000);
                        Attacksound(&chooseAttack, &i, poke);
                    }

                    clear_screen();
                    eeveeAnima(Eev);
                    victini(Vic);

                    sleep_ms(500);
                    clear_screen();
                    eeveeFront(*Eev);
                    victini(Vic);
                }

                else
                {

                    printf("                           Victini errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else if (victiniAtta[chooseAttack].attackStyle == 3)
            {

                if (accuTempVic >= g)
                {       
                    printf("                           Victini usou Protect e se defendeu durante esse turno!\n");
                    acertou = 1; 
                    sleep_ms(1000);
                    Attacksound(&chooseAttack, &i, poke);

                }

                else
                {
                    printf("                           Victini errou o ataque!\n");
                    sleep_ms(1000);
                }
                
            }

            victiniAtta[chooseAttack].pp--;
        }
    
        else{
            printf("                           Victini não atacou pois não tem PP suficiente neste ataque!\n");
            sleep_ms(1000);
        }
    }

    if (Vic->HP <= 0)
    {
        return;
    }
    else if (Eev->HP <= 0)
    {
        return;
    }
    
  

        int p = rand() % 100;
        i = iMusic;
        

        if (Eev->potion >= 1 && Eev->HP <= 15)
        {                       
                Eev->HP += 20;
                Eev->potion--;
                printf("                           Eevee tomou uma poção e recuperou 20 de Vida!\n");              
                sleep_ms(1000);
                musicHP();

                clear_screen();
                eeveeFront(*Eev);
                victini(Vic);
        }
        else if(Eev->PP >= 1 && EeveeAtta[i].pp == 0){
            Eev->PP--;
            EeveeAtta[i].pp ++;
            printf("                                        Eevee aumentou seu PP do ataque Shadow Ball!\n");
            sleep_ms(2000);
        }
            else
            {

                if (EeveeAtta[i].pp != 0)
                {

                    if (EeveeAtta[i].attackStyle == 1)
                    {

                        if (accuTempEev >= p)
                        {

                            if (acertou != 1)
                            {

                                if (i == 0)
                                {
                                    printf("                           Eevee usou Double Kick!\n");
                                    sleep_ms(1000);
                                    Attacksound(&chooseAttack, &i, poke);

                                    clear_screen();
                                    eeveeFront(*Eev);
                                    victiniAnimaUser(Vic);

                                    sleep_ms(500);
                                    clear_screen();
                                    eeveeFront(*Eev);
                                    victini(Vic);
                                }
                                else if (i == 3)
                                {
                                    printf("                           Eevee usou Mud-Slap!\n");
                                    sleep_ms(1000);
                                    Attacksound(&chooseAttack, &i, poke);

                                    clear_screen();
                                    eeveeFront(*Eev);
                                    victiniAnimaUser(Vic);

                                    sleep_ms(500);
                                    clear_screen();
                                    eeveeFront(*Eev);
                                    victini(Vic);
                                }
                                clear_screen();

                                Vic->HP -= (EeveeAtta[i].damage + ((Eev->Attack - Vic->Defense) * 0.25));
                            }

                            else if (acertou == 1)
                            {

                                printf("                           Victini se defendeu, então Eevee apenas gastou um ataque e não causou dano nenhum!\n");
                                sleep_ms(1000);
                                Attacksound(&chooseAttack, &i, poke);
                                return;
                            }
                        }

                        else
                        {

                            printf("                           Eevee errou o ataque!\n");
                            sleep_ms(1000);
                        }
                    }

                    else if (EeveeAtta[i].attackStyle == 2)
                    {

                        if (accuTempEev >= p)
                        {

                            if (acertou != 1)
                            {
                                Vic->HP -= (EeveeAtta[i].damage + ((Eev->SpAtk - Vic->SpDef) * 0.25));
                                printf("                           Eevee usou Shadow Ball!\n");
                                sleep_ms(1000);
                                Attacksound(&chooseAttack, &i, poke);

                                clear_screen();
                                eeveeFront(*Eev);
                                victiniAnimaUser(Vic);

                                sleep_ms(500);
                                clear_screen();
                                eeveeFront(*Eev);
                                victini(Vic);
                            }

                            else if (acertou == 1)
                            {

                                printf("                           Victini se defendeu, então Eevee apenas gastou um ataque e não causou dano nenhum!\n");
                                sleep_ms(1000);
                                Attacksound(&chooseAttack, &i, poke);
                                return;
                            }
                        }

                        else
                        {

                            printf("                           Eevee errou o ataque!\n");
                            sleep_ms(1000);
                        }
                    }

                    else
                    {

                        if (accuTempEev >= p)
                        {

                            if (acertou != 1)
                            {

                                printf("                           Eevee utilizou Sand-Attack e seu inimigo teve a precisão diminuida!\n");
                                accuTempVic -= 10;
                                sleep_ms(1000);
                                Attacksound(&chooseAttack, &i, poke);

                                clear_screen();
                                eeveeFront(*Eev);
                                victiniAnimaUser(Vic);

                                sleep_ms(500);
                                clear_screen();
                                eeveeFront(*Eev);
                                victini(Vic);
                            }

                            else if (acertou == 1)
                            {

                                printf("                           Victini se defendeu, então Eevee apenas gastou um ataque e não causou dano nenhum!\n");
                                sleep_ms(1000);
                                Attacksound(&chooseAttack, &i, poke);
                                return;
                            }
                        }

                        else
                        {

                            printf("                           Eevee errou o ataque!\n");
                            sleep_ms(1000);
                        }
                    }
                }
            
        

        else
        {

            printf("Eevee não atacou pois não tem PP suficiente neste ataque!\n");
            sleep_ms(2000);
            return;
            //////////////////////////////////////////////////////////////////////////////
        }
}
        EeveeAtta[i].pp--;
    

    return;
}

// Bulbasaur vs Victini
void bulbaAttackSystem(BulbasaurSt *Bulba, bulbasaurAttacks bulbasaurAtta[], VictiniSt *Vic, victiniAttacks victiniAtta[], int x, int poke)
{

    srand(time(0));
    int i = rand() % 4;
    int g =  rand() % 100;
    int AttackMusic = -1;
    int accuTempVic = victiniAtta[i].accuracy;
    if (x != 2)
    {
        while(AttackMusic < 1 || AttackMusic > 4){
        scanf("%d", &AttackMusic);
        }
    }
    int accuTempBulba = bulbasaurAtta[AttackMusic].accuracy;
    int chooseAttack = -1;

    int acertou = 0;

    if (Vic->HP <= 15 && Vic->potion >= 1)
    {   
            Vic->HP += 20;
            Vic->potion--;
            printf("                           Victini tomou uma poção e recuperou 20 de Vida!\n");           
            sleep_ms(1000);
            musicHP();

            clear_screen();
            victiniFront(*Vic);
            bulbasaur(Bulba);
    }
    else if(Vic->PP >= 1 && victiniAtta[i].pp == 0){
            Vic->PP--;
            victiniAtta[i].pp ++;
            printf("                                        Victini aumentou seu PP do ataque Protect!\n");
            sleep_ms(2000);
        }

    else
    {

        if (victiniAtta[i].pp != 0)
        {

            if (victiniAtta[i].attackStyle == 1)
            {

                if (accuTempVic >= g)
                {

                    Bulba->HP -= (victiniAtta[i].damage + ((Vic->Attack - Bulba->Defense) * 0.25));
                    printf("\n                                           Victini usou Thunder Punch!\n");
                    // delay
                    sleep_ms(1000);
                    // funçao de efeito sonoro
                    Attacksound(&chooseAttack, &i, poke);

                    clear_screen();
                    // sprite
                    victiniFront(*Vic);
                    bulbasaurAnimaUser(Bulba); // animação simples

                    sleep_ms(200);

                    clear_screen();
                    // sprites
                    victiniFront(*Vic);
                    bulbasaur(Bulba);
                }

                else
                {

                    printf("\n                                           Victini errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else if (victiniAtta[i].attackStyle == 2)
            {

                if (accuTempVic >= g)
                {

                    if (i == 1)
                    {
                        printf("\n                                           Victini usou Fire Spin!\n");
                        sleep_ms(1000);

                        Attacksound(&chooseAttack, &i, poke);

                        clear_screen();
                        victiniFront(*Vic);
                        bulbasaurAnimaUser(Bulba);
                        sleep_ms(200);
                        Bulba->HP -= (victiniAtta[i].damage + ((Vic->SpAtk - Bulba->SpDef) * 0.25));
                        clear_screen();
                        victiniFront(*Vic);
                        bulbasaur(Bulba);
                    }
                    else
                    {
                        printf("\n                                           Victini usou Swift!\n");
                        sleep_ms(1000);
                        Attacksound(&chooseAttack, &i, poke);
                        Bulba->HP -= (victiniAtta[i].damage + ((Vic->SpAtk - Bulba->SpDef) * 0.25));
                        clear_screen();
                        victiniFront(*Vic);
                        bulbasaurAnimaUser(Bulba);
                        sleep_ms(200);
                        clear_screen();
                        victiniFront(*Vic);
                        bulbasaur(Bulba);
                    }
                }

                else
                {

                    printf("\n                                           Victini errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else if (victiniAtta[i].attackStyle == 3)
            {

                if (accuTempVic >= g)
                {

                    printf("\n                                           Victini usou Protect e se defendeu durante esse turno!\n");
                    sleep_ms(1000);
                    Attacksound(&chooseAttack, &i, poke);

                    acertou = 1;
                }

                else
                {

                    printf("\n                                           Victini errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            victiniAtta[i].pp--;
        }

        else if (x != 2)
        {

            printf("\n                                           Victini não atacou pois não tem PP suficiente neste ataque!\n");
            sleep_ms(1000);
        }
    }

    if (Bulba->HP <= 0)
    {
        return;
    }
    else if (Vic->HP <= 0)
    {
        return;
    }

    int p = rand() % 100;
    chooseAttack = AttackMusic;

    chooseAttack--;
   
    if (chooseAttack < 0)
    {
        return;
    }

    if (bulbasaurAtta[chooseAttack].pp != 0)
    {

        if (bulbasaurAtta[chooseAttack].attackStyle == 1)
        {

            if (accuTempBulba >= p)
            {

                if (acertou != 1)
                {

                    if (chooseAttack == 0)
                    {
                        printf("\n                                           Bulbasaur usou Vine Whip!\n");
                        sleep_ms(1000);

                        Attacksound(&chooseAttack, &i, poke);
                        clear_screen();
                        victiniAnima(Vic);
                        bulbasaur(Bulba);
                        sleep_ms(200);
                        clear_screen();
                        victini(Vic);
                        bulbasaur(Bulba);
                    }
                    else if (chooseAttack == 1)
                    {
                        printf("\n                                           Bulbasaur usou Take Down!\n");
                        sleep_ms(1000);

                        Attacksound(&chooseAttack, &i, poke);

                        clear_screen();
                        victiniAnima(Vic);
                        bulbasaur(Bulba);
                        sleep_ms(200);
                        clear_screen();
                        victini(Vic);
                        bulbasaur(Bulba);
                    }
                    clear_screen();

                    Vic->HP -= (bulbasaurAtta[chooseAttack].damage + ((Bulba->Attack - Vic->Defense) * 0.25));
                }

                else if (acertou == 1)
                {
                    Attacksound(&chooseAttack, &i, poke);

                    printf("\n                                           Victini se defendeu, então você apenas gastou um ataque e não causou dano nenhum!\n");
                    sleep_ms(1000);
                    bulbasaurAtta[chooseAttack].pp--;
                    return;
                }
            }

            else
            {

                printf("\n                                           Bulbasaur errou o ataque!\n");
                sleep_ms(1000);
            }
        }

        else if (bulbasaurAtta[chooseAttack].attackStyle == 2)
        {

            if (accuTempBulba >= p)
            {

                if (victiniAtta[i].attackStyle != 3 && acertou == 0)
                {
                    Vic->HP -= (bulbasaurAtta[chooseAttack].damage + ((Bulba->SpAtk - Vic->SpDef) * 0.25));
                    printf("\n                                           Bulbasaur usou Razor Leaf!\n");
                    sleep_ms(1000);

                    Attacksound(&chooseAttack, &i, poke);

                    clear_screen();
                    victiniAnima(Vic);
                    bulbasaur(Bulba);
                    sleep_ms(200);
                    clear_screen();
                    victini(Vic);
                    bulbasaur(Bulba);
                }

                else if (victiniAtta[i].attackStyle == 3 && acertou == 1)
                {
                    Attacksound(&chooseAttack, &i, poke);

                    printf("\n                                           Victini se defendeu, então você apenas gastou um ataque e não causou dano nenhum!\n");
                    sleep_ms(1000);
                    bulbasaurAtta[chooseAttack].pp--;
                    return;
                }
            }

            else
            {

                printf("\n                                           Bulbasaur errou o ataque!\n");
                sleep_ms(1000);
            }
        }

        else
        {

            if (accuTempBulba >= p)
            {

                if (victiniAtta[i].attackStyle != 3 || acertou == 0)
                {

                    printf("\n                                           Bulbasaur usou Growl, o inimigo teve seu status de ataque reduzido!\n");
                    Vic->Attack -= Vic->Attack * 0.75;
                    sleep_ms(1000);

                    Attacksound(&chooseAttack, &i, poke);

                    clear_screen();
                    victiniAnima(Vic);
                    bulbasaur(Bulba);
                    sleep_ms(200);
                    clear_screen();
                    victini(Vic);
                    bulbasaur(Bulba);
                }

                else if (acertou == 1)
                {
                    Attacksound(&chooseAttack, &i, poke);

                    printf("\n                                           Victini se defendeu, então você apenas gastou um ataque e não causou dano nenhum!\n");
                    sleep_ms(1000);
                    bulbasaurAtta[chooseAttack].pp--;
                    return;
                }
            }

            else
            {

                printf("\n                                           Bulbasaur errou o ataque!\n");
                sleep_ms(1000);
            }
        }
    }

    else if (chooseAttack < 4)
    {

        printf("\n                                           Bulbasaur não atacou pois não tem PP suficiente neste ataque!\n");
        sleep_ms(2000);
        return;
        //////////////////////////////////////////////////////////////////////////////
    }

    bulbasaurAtta[chooseAttack].pp--;

    return;
}

// Eevee vs Bulbasaur
void eeveeAttackSystem(BulbasaurSt *Bulba, bulbasaurAttacks bulbasaurAtta[], EeveeSt *Eev, eeveeAttacks EeveeAtta[], int x, int poke)
{

    srand(time(0));
    int i = rand() % 4;
    int g = rand() % 100;
    int AttackMusic = -1; // erro de segmentaion pq não declarei o valor
    if (x != 2)
    {
        while(AttackMusic < 1 || AttackMusic > 4){
        scanf("%d", &AttackMusic);
        }
    }
    int accuTempBulba = bulbasaurAtta[i].accuracy;
    int accuTempEev = EeveeAtta[AttackMusic].accuracy;
    int chooseAttack = -1;
    
    if (Bulba->HP <= 15 && Bulba->potion >= 1)
    {
            Bulba->HP += 20;
            Bulba->potion--;           
            sleep_ms(1000);
            printf("                           Bulbasaur tomou uma poção e recuperou 20 de Vida!\n");
            musicHP();

            clear_screen();
            bulbasaurFront(*Bulba);
            eevee(Eev);          
    }

else if(Bulba->PP >= 1 && bulbasaurAtta[i].pp == 0){
            Bulba->PP--;
            bulbasaurAtta[i].pp ++;
            printf("                                        Bulbasaur aumentou seu PP do ataque Take Down!\n");
            sleep_ms(2000);
        }

    else
    {
        if (bulbasaurAtta[i].pp != 0)
        {

            if (bulbasaurAtta[i].attackStyle == 1)
            {

                if (accuTempBulba >= g)
                {
                    if (i == 0)
                    {
                        Eev->HP -= (EeveeAtta[i].damage + ((Bulba->Attack - Eev->Defense) * 0.25));
                       
                        printf(" Bulbasaur usou Vine Whipe!\n");
                        sleep_ms(1000);
                        Attacksound(&chooseAttack, &i, poke);

                        clear_screen();
                        bulbasaurFront(*Bulba);
                        eeveeAnimaUser(Eev);
                        sleep_ms(200);
                        clear_screen();
                        bulbasaurFront(*Bulba);
                        eevee(Eev);
                    }
                    else
                    {

                        Eev->HP -= (EeveeAtta[i].damage + ((Bulba->Attack - Eev->Defense) * 0.25));
                        printf(" Bulbasaur usou Take Down!\n");
                        sleep_ms(1000);
                        Attacksound(&chooseAttack, &i, poke);
                       
                        clear_screen();
                        bulbasaurFront(*Bulba);
                        eeveeAnimaUser(Eev);
                        sleep_ms(200);
                        clear_screen();
                        bulbasaurFront(*Bulba);
                        eevee(Eev);
                    }
                }

                else
                {

                    printf("                           Bulbasaur errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else if (bulbasaurAtta[i].attackStyle == 2)
            {

                if (accuTempBulba >= g)
                {

                    Eev->HP -= (bulbasaurAtta[i].damage + ((Bulba->SpAtk - Eev->SpDef) * 0.25));
                    printf("                           Bulbasaur usou Razor Leaf!\n");
                    sleep_ms(1000);
                    Attacksound(&chooseAttack, &i, poke);

                    clear_screen();
                    bulbasaurFront(*Bulba);
                    eeveeAnimaUser(Eev);
                    sleep_ms(200);
                    clear_screen();
                    bulbasaurFront(*Bulba);
                    eevee(Eev);
                }

                else
                {

                    printf("                           Bulbasaur errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else if (bulbasaurAtta[i].attackStyle == 3)
            {

                if (accuTempBulba >= g)
                {
                    Eev->Attack -= Eev->Attack * 0.75;
                    
                    printf("                           Bulbasaur usou o Growl e reduziu o dano do inimigo!\n");
                    sleep_ms(1000);
                    Attacksound(&chooseAttack, &i, poke);
                }

                else
                {

                    printf("                           Bullbasaur errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            bulbasaurAtta[i].pp--;
        }

        else if (x != 2)
        {

            printf("                           Bulbasaur não atacou pois não tem PP suficiente neste ataque!\n");
            sleep_ms(1000);
        }
    }

    if (Bulba->HP <= 0)
    {
        Bulba->HP = 0;
        return;
    }
    else if (Eev->HP <= 0)
    {
        Eev->HP = 0;
        return;
    }

    

        int p = rand() % 100;
        chooseAttack = AttackMusic;

        chooseAttack--;
    if(x != 2){
        if (EeveeAtta[chooseAttack].pp != 0)
        {

            if (EeveeAtta[chooseAttack].attackStyle == 1)
            {

                if (accuTempEev >= p)
                {

                    if (chooseAttack == 0)
                    {
                        printf("                           Eevee usou Double Kick!\n");
                        sleep_ms(1000);
                        Attacksound(&chooseAttack, &i, poke);
                        Bulba->HP -= (EeveeAtta[i].damage + ((Eev->SpAtk - Bulba->SpDef) * 0.25));

                        clear_screen();
                        bulbasaurAnima(Bulba);
                        eevee(Eev);
                        sleep_ms(200);
                        clear_screen();
                        bulbasaur(Bulba);
                        eevee(Eev);
                    }
                    else if (chooseAttack == 3)
                    {
                        printf("                           Eevee usou Mud-Slap!\n");
                        sleep_ms(1000);
                        Attacksound(&chooseAttack, &i, poke);
                        Bulba->HP -= (EeveeAtta[i].damage + ((Eev->SpAtk - Bulba->SpDef) * 0.25));

                        clear_screen();
                        bulbasaurAnima(Bulba);
                        eevee(Eev);
                        sleep_ms(200);
                        clear_screen();
                        bulbasaurFront(*Bulba);
                        eevee(Eev);
                    }
                    // clear_screen();
                }

                else
                {

                    printf("                           Eevee errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else if (EeveeAtta[chooseAttack].attackStyle == 2)
            {

                if (accuTempEev >= p)
                {
                    printf("                           Eevee usou Shadow Ball!\n");
                    sleep_ms(1000);
                    Attacksound(&chooseAttack, &i, poke);

                    Bulba->HP -= (EeveeAtta[chooseAttack].damage + ((Eev->SpAtk - Bulba->SpDef) * 0.25));

                    clear_screen();
                    bulbasaurAnima(Bulba);
                    eevee(Eev);
                    sleep_ms(500);
                    clear_screen();
                    bulbasaurFront(*Bulba);
                    eevee(Eev);
                }

                else
                {

                    printf("                           Eevee errou o ataque!\n");
                    sleep_ms(1000);
                }
            }

            else
            {

                if (accuTempBulba >= p)
                {
                    ////ATQUE DE EFEITO EEVEE

                    printf("                           Eevee usou Sand-Attack e diminuiu a precisão do Bulbasaur reduzida!\n");
                    accuTempBulba -= 10;
                    sleep_ms(1000);
                    Attacksound(&chooseAttack, &i, poke);

                    clear_screen();
                    bulbasaurAnima(Bulba);
                    eevee(Eev);
                    sleep_ms(500);
                    clear_screen();
                    bulbasaurFront(*Bulba);
                    eevee(Eev);
                }

                else
                {

                    printf("                           Eevee errou o ataque!\n");
                    sleep_ms(1000);
                }
            }
        }


        else
        {

            printf("                           Eevee não atacou pois não tem PP suficiente neste ataque!\n");
            sleep_ms(2000);
            return;
            //////////////////////////////////////////////////////////////////////////////
        }

        EeveeAtta[chooseAttack].pp--;
    }
    
    return;
}
// MECANICA ITENS

void ITEMbulbasaur(BulbasaurSt *Bulba, bulbasaurAttacks *bulbasaurAtta)
{
    int escolha;
    while (escolha != '+')
    {

        scanf("%d", &escolha);

        if (escolha == 1 && Bulba->potion > 0 && Bulba->HP < 45)
        {
            Bulba->potion--;
            Bulba->HP += 20;

            printf("                                        Bulbasaur está bebendo a poção de cura!!\n");
            musicHP();
            return;
        }
        else if (escolha == 2 && Bulba->PP > 0)
        {
            Bulba->PP--;
            bulbasaurAtta[1].pp++; // PP do pokemon ++
            printf("                                        Bulbasaur aumentou seu PP do ataque Take Donw!\n");
            sleep_ms(1000);
            return;
        }
        else if (escolha == 3 && Bulba->DMG > 0)
        {
            Bulba->DMG--;
            Bulba->Attack += (Bulba->Attack * 0.25);
            printf("                                        Bulbasaur aumentou seu dano!!\n");
            sleep_ms(1000);
            return;
        }        
    }
}

void ITEMvictini(VictiniSt *Vic, victiniAttacks *VictiniAtta, int HP, int Attack, int potion, int PP, int DMG)
{
    int escolha;
   while (escolha != '+'){
    scanf("%d", &escolha);

    if (escolha == 1 && potion > 0)
    {
        Vic->potion--;
        Vic->HP += 20;
        printf("                                        Victini está bebendo a poção de cura!!\n");
        musicHP();
        return;
    }
    else if (escolha == 2 && PP > 0)
    {
        Vic->PP--;
        VictiniAtta[2].pp++;
        printf("                                        Victini aumentou seu PP do ataque Proctect!\n");
        sleep_ms(1000);
        return;
    }
    else if (escolha == 3 && DMG > 0)
    {
        Vic->DMG--;
        Vic->Attack += (Attack * 0.25);
        printf("                                        Victini aumentou seu dano!\n");
        sleep_ms(1000);
        return;
    }
   }
}

void ITEMeevee(EeveeSt *Eev, eeveeAttacks *EeveeAtta)
{
    int escolha;
    while (escolha != '+'){
    scanf("%d", &escolha);

    if (escolha == 1 && Eev->potion > 0)
    {
        Eev->potion--;
        Eev->HP += 20;
        printf("                                        Eevee está bebendo a poção de cura!!\n");
        sleep_ms(1000);
        musicHP();
        return;
    }
    else if (escolha == 2 && Eev->PP > 0)
    {
        Eev->PP--;
        EeveeAtta[2].pp++;
        printf("                                        Eevee aumentou seu PP do ataque Shadow Ball!\n");
        sleep_ms(1000);
        return;
    }
    else if (escolha == 3 && Eev->DMG > 0)
    {
        Eev->DMG--;
        Eev->Attack += (Eev->Attack * 0.25);
        printf("                                        Eevee aumentou seu dano!\n");
        sleep_ms(1000);
        return;
    }
    }
}

void victini(VictiniSt *Vic)
{
    if (Vic->HP <= 0)
    {
        Vic->HP = 0;
    }
    if (Vic->HP > 50)
    {
        Vic->HP = 50;
    }

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
    printf("                                        ███▓▓▓▓██████████▓██              | HP:%02d/50               ///\n", Vic->HP);
    printf("                                        ██████████████▓▓████              |//////////////////////////   \n");
    printf("                                        █████        ████████                                       \n");
}

void bulbasaur(BulbasaurSt *Bulba)
{
    if (Bulba->HP <= 0)
    {
        Bulba->HP = 0;
    }
    if (Bulba->HP > 45)
    {
        Bulba->HP = 45;
    }

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
    printf("                                 █████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██       | HP:%02d/45               /// \n", Bulba->HP);
    printf("                                  ████████▓▓▓▓██▓▓▓▓▓▓▓██████        |//////////////////////////   \n");
    printf("                                   ███████████████████▓██                                           \n");
}

void eevee(EeveeSt *Eev)
{
    if (Eev->HP <= 0)
    {
        Eev->HP = 0;
    }
    if (Eev->HP > 55)
    {
        Eev->HP = 55;
    }

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
    printf("                               ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓███▓░▓▓██      |//////////////////////////////\n");
    printf("                                ██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓█████       | Eeevee      1.Attacks    /// \n");
    printf("                                 ████▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓███       |             2.Bag       ///  \n");
    printf("                                    ██████████▓▓▓▓▓▓▓▓▓███▓▒▒██      | HP:%02d/55               ///   \n", Eev->HP);
    printf("                                          ████████████████████       |//////////////////////////     \n");
    printf("                                                █████████                                           \n");
}

void bulbasaurFront(BulbasaurSt Bulba)
{
    if (Bulba.HP <= 0)
    {
        Bulba.HP = 0;
    }
    if (Bulba.HP > 45)
    {
        Bulba.HP = 45;
    }

    printf("                                                                                                                                                                 \n");
    printf("                                                                                                                                          ▓▓▓▓███                \n");
    printf("             ||||||||||||||||||||||||                                                                                          ▒▒▒▒▒▓▓▓▓▓▓▒▒▒▓█▓██               \n");
    printf("             | Bulbasaur   -------- |                                                                                       ▒▒▒▒░░░░░░░░░▒▒▒▒▒▓▓██               \n");
    printf("             |             -------- |                                                                        ████         ▒▒░░░░░░▒▓▓▒▒▒▒░▒▒▒▒▒▓██               \n");
    printf("             | HP:%02d/45             |                                                                       ▓▒░░▓██ ▓▓▓▓▓▓▓▓▓▓▓▓██▒░▒█░░░░░░▒▒▒▓▓▓█              \n", Bulba.HP);
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

void victiniFront(VictiniSt Vic)
{
    if (Vic.HP <= 0)
    {
        Vic.HP = 0;
    }
    if (Vic.HP > 50)
    {
        Vic.HP = 50;
    }

    printf("                                                                                                                                  ████             \n");
    printf("                                                                                                                                  ████             \n");
    printf("              ||||||||||||||||||||||||                                                                                            █▓██             \n");
    printf("              | Victini     -------- |                                                                                           ██▓▓██            \n");
    printf("              |             -------- |                                                                                           ██▓▓██            \n");
    printf("              | HP:%02d/50             |                                                                                           █▓▓▓██            \n", Vic.HP);
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

void eeveeFront(EeveeSt Eev)
{
    if (Eev.HP <= 0)
    {
        Eev.HP = 0;
    }
    if (Eev.HP > 55)
    {
        Eev.HP = 55;
    }

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
}

// BAG ABERTA SPRITES

void bulbaBAG(BulbasaurSt Bulba)
{

    printf("                                      █▓▒▓▒▓█                                                       \n");
    printf("                                     █▓███▒░▒▓███           ███                                     \n");
    printf("                                     █▓▓▓▓▓░░▒▒░▒█████    ██▓░██                                    \n");
    printf("                                    █▓▒▒░░░▒▓▓░░▒▓███▓▓█▓▒▓▒░▒██                                    \n");
    printf("                                   █▓▒▒░░░░░▒▒▓▓▓▒▒▒▒▓▓▓█▓░░▒▓██                                    \n");
    printf("                                 █▓▒▒░    ░░▒▒▒▒▒██▓▒▒▒▒▓██▓▓▓███                                   \n");
    printf("                                 █▒▒▒░   ░▒▒▒▒▒▒▒▒▒▒█▓▒▒▒██▓▓▓▒▓█    |//////////////////////////|   \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒██▓▓▓▒░▓█   |::::::::::::::::::::::::::|   \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▒██▓▓▓▓▓▓██   |:1.POTION..............x%d:|   \n", Bulba.potion);
    printf("                                 ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▓██▓▓▓▓▓▓██    |:2.PP..................x%d:|   \n", Bulba.PP);
    printf("                                  ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒███▓████████     |:3.X ATTACK............x%d:|   \n", Bulba.DMG);
    printf("                                  ██████▓▒▒▒▒▒▒█████▓▓▓▓▓▓▓▓▓██      |::::::::::::::::::::::::::|   \n");
    printf("                                 ██▓▓▓██████████▓▓███▒░▓██▓▓▓██      |==========================|   \n");
    printf("                                 ██████████▓▓██▓▓▓▓██▓▒▒██▓▓██       |__________________________|   \n");
    printf("                                 █████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██       | HP:%02d/45                 |   \n", Bulba.HP);
    printf("                                  ████████▓▓▓▓██▓▓▓▓▓▓▓██████        |//////////////////////////|   \n");
    printf("                                   ███████████████████▓██                                           \n");
}

void victiniBAG(VictiniSt Vic)
{

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
    printf("                                   ███▓█▒▒▒▒▓██▒▒▒▒█▒▒▒▒▓▒▒▒██▒▓███       |:3.X ATTACK............x%d:|\n", Vic.DMG);
    printf("                                     ██▒▒▓▒▒▒▒█▒▒█▒▒▒▒▒▒▒██▓████          |::::::::::::::::::::::::::|\n");
    printf("                                     ███▒▒▓███▒▓▒▒█▓▓█▒▒▓▒▒████           |==========================|\n");
    printf("                                       ████▓██▒▒▒█▓▒▓▒▒▒▓███              |__________________________|\n");
    printf("                                        ███▓▓▓▓██████████▓██              | HP:%02d/50                 |\n", Vic.HP);
    printf("                                        ██████████████▓▓████              |//////////////////////////|\n");
    printf("                                        █████        ████████                                       \n");
}

void eeveeBAG(EeveeSt Eev)
{

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
    printf("                              ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████▓█▒░░░░▒░░▒▓▓█    |:3.X ATTACK............x%d:|  \n", Eev.DMG);
    printf("                               ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓███▓░▓▓██       |::::::::::::::::::::::::::|  \n");
    printf("                                ██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓█████        |==========================|  \n");
    printf("                                 ████▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓███        |__________________________|  \n");
    printf("                                    ██████████▓▓▓▓▓▓▓▓▓███▓▒▒██       | HP:%02d/55                 |  \n", Eev.HP);
    printf("                                          ████████████████████        |//////////////////////////|  \n");
    printf("                                                █████████                                           \n");
}
// ATTACK ABERTA SPRITE

void bulbasaurATT(BulbasaurSt Bulba, bulbasaurAttacks BulbasaurAtta[])
{

    printf("                                      █▓▒▓▒▓█                                                       \n");
    printf("                                     █▓███▒░▒▓███           ███                                     \n");
    printf("                                     █▓▓▓▓▓░░▒▒░▒█████    ██▓░██                                    \n");
    printf("                                    █▓▒▒░░░▒▓▓░░▒▓███▓▓█▓▒▓▒░▒██                                    \n");
    printf("                                   █▓▒▒░░░░░▒▒▓▓▓▒▒▒▒▓▓▓█▓░░▒▓██                                    \n");
    printf("                                 █▓▒▒░    ░░▒▒▒▒▒██▓▒▒▒▒▓██▓▓▓███                                   \n");
    printf("                                 █▒▒▒░   ░▒▒▒▒▒▒▒▒▒▒█▓▒▒▒██▓▓▓▒▓█                                   \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒██▓▓▓▒░▓█                                  \n");
    printf("                                █▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▒██▓▓▓▓▓▓██   |***********************************|  \n");
    printf("                                 ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▓██▓▓▓▓▓▓██    |*# 1.Vine Whipe :: 3.Razor Leaf::#*|  \n");
    printf("                                  ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒███▓████████     |##      %02d/10   ::    %02d/05 ::::::#|  \n", BulbasaurAtta[0].pp, BulbasaurAtta[2].pp);
    printf("                                  ██████▓▒▒▒▒▒▒█████▓▓▓▓▓▓▓▓▓██      |## 2.Take Down  :: 4.Growl ::::::##|  \n");
    printf("                                 ██▓▓▓██████████▓▓███▒░▓██▓▓▓██      |##       %02d/03   :    %02d/10 :::::##|  \n", BulbasaurAtta[1].pp, BulbasaurAtta[3].pp);
    printf("                                 ██████████▓▓██▓▓▓▓██▓▒▒██▓▓██       |////////////////////////////////////  \n");
    printf("                                 █████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██       | HP:%02d/45               /////////// \n", Bulba.HP);
    printf("                                  ████████▓▓▓▓██▓▓▓▓▓▓▓██████        |//////////////////////////////////    \n");
    printf("                                   ███████████████████▓██                                           \n");
}

void victiniATT(VictiniSt Vic, victiniAttacks VictiniAtta[])
{

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
    printf("                                   ██▓█▓▒▒██▓▓▓█▒▒▒██▒▒██▒▒███ ███        |***********************************|     \n");
    printf("                                  ████▓▒▓▒▒██▓██▓▓█▓███▒▒▓█▓▒█████        |*# 1.Thunder P. :: 3.Protect ::::#*|     \n");
    printf("                                   ███▓█▒▒▒▒▓██▒▒▒▒█▒▒▒▒▓▒▒▒██▒▓███       |##      %02d/05   ::   %02d/03 :::::::#|    \n", VictiniAtta[0].pp, VictiniAtta[2].pp);
    printf("                                     ██▒▒▓▒▒▒▒█▒▒█▒▒▒▒▒▒▒██▓████          |## 2.Fire Spin  :: 4.Swift ::::::##|     \n");
    printf("                                     ███▒▒▓███▒▓▒▒█▓▓█▒▒▓▒▒████           |##      %02d/10    :   %02d/05 ::::::##|   \n", VictiniAtta[1].pp, VictiniAtta[3].pp);
    printf("                                       ████▓██▒▒▒█▓▒▓▒▒▒▓███              |////////////////////////////////////     \n");
    printf("                                        ███▓▓▓▓██████████▓██              | HP:%02d/50               ///////////     \n", Vic.HP);
    printf("                                        ██████████████▓▓████              |//////////////////////////////////      \n");
    printf("                                        █████        ████████                                       \n");
}

void eeveeATT(EeveeSt Eev, eeveeAttacks EeveeAtta[])
{

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
    printf("                             ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░▒░░░░░░░░░░░░░▒   |***********************************|     \n");
    printf("                             ███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░█░▒░░░░░░░░░░░▓██   |*# 1.Double Kick : 3.Shadow Ball #*|     \n");
    printf("                              ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████▓█▒░░░░▒░░▒▓▓█    |##      %02d/06  ::        %02d/03  ::#|\n", EeveeAtta[0].pp, EeveeAtta[2].pp);
    printf("                               ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓███▓░▓▓██       |## 2.Sand Attack : 4.Mud-Slap :::##|     \n");
    printf("                                ██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓█████        |##      %02d/06    :       %02d/10 ::##| \n", EeveeAtta[1].pp, EeveeAtta[3].pp);
    printf("                                 ████▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓███        |////////////////////////////////////     \n");
    printf("                                    ██████████▓▓▓▓▓▓▓▓▓███▓▒▒██       | HP:%02d/55               ///////////       \n", Eev.HP);
    printf("                                          ████████████████████        |//////////////////////////////////         \n");
    printf("                                                █████████                                           \n");
}

// ANIMAÇÃO

void eeveeAnima(EeveeSt *Eev)
{

    if (Eev->HP <= 0)
    {
        Eev->HP = 0;
    }
    if (Eev->HP > 55)
    {
        Eev->HP = 55;
    }

    printf("                                         \n");
    printf("                                         \n");
    printf("              ||||||||||||||||||||||||   \n");
    printf("              | Eevee       -------- |   \n");
    printf("              |             -------- |   \n");
    printf("              | HP:%02d/55             |   \n", Eev->HP);
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
}

void victiniAnima(VictiniSt *Vic)
{

    if (Vic->HP <= 0)
    {
        Vic->HP = 0;
    }
    if (Vic->HP > 50)
    {
        Vic->HP = 50;
    }

    printf("                                         \n");
    printf("                                         \n");
    printf("              ||||||||||||||||||||||||   \n");
    printf("              | Victini     -------- |   \n");
    printf("              |             -------- |   \n");
    printf("              | HP:%02d/50             |   \n", Vic->HP);
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
    printf("\n");
}

void bulbasaurAnima(BulbasaurSt *Bulba)
{

    if (Bulba->HP <= 0)
    {
        Bulba->HP = 0;
    }
    if (Bulba->HP > 45)
    {
        Bulba->HP = 45;
    }

    printf("                                         \n");
    printf("                                         \n");
    printf("             ||||||||||||||||||||||||   \n");
    printf("             | Bulbasaur   -------- |   \n");
    printf("             |             -------- |   \n");
    printf("             | HP:%02d/45             |   \n", Bulba->HP);
    printf("             ||||||||||||||||||||||||   \n");
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
}

void victiniAnimaUser(VictiniSt *Vic)
{
    if (Vic->HP <= 0)
    {
        Vic->HP = 0;
    }
    if (Vic->HP > 45)
    {
        Vic->HP = 45;
    }

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                          |//////////////////////////////\n");
    printf("                                                                          | Victini     1.Attacks    /// \n");
    printf("                                                                          |             2.Bag       ///  \n");
    printf("                                                                          | HP:%02d/50               /// \n", Vic->HP);
    printf("                                                                          |//////////////////////////    \n");
    printf("                                                                                                    \n");
}

void bulbasaurAnimaUser(BulbasaurSt *Bulba)
{
    if (Bulba->HP <= 0)
    {
        Bulba->HP = 0;
    }
    if (Bulba->HP > 45)
    {
        Bulba->HP = 45;
    }

    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                     |//////////////////////////////\n");
    printf("                                                                     | Bulbasaur   1.Attacks    /// \n");
    printf("                                                                     |             2.Bag       ///  \n");
    printf("                                                                     | HP:%02d/45               /// \n", Bulba->HP);
    printf("                                                                     |//////////////////////////   \n");
    printf("                                                                 \n");
}

void eeveeAnimaUser(EeveeSt *Eev)
{
    if (Eev->HP <= 0)
    {
        Eev->HP = 0;
    }
    if (Eev->HP > 45)
    {
        Eev->HP = 45;
    }

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                                                    \n");
    printf("                                                                     |//////////////////////////////\n");
    printf("                                                                     | Eevee       1.Attacks    /// \n");
    printf("                                                                     |             2.Bag       ///  \n");
    printf("                                                                     | HP:%02d/55               /// \n", Eev->HP);
    printf("                                                                     |//////////////////////////   \n");
    printf("                                                                 \n");
}

void dialogoFinal(int vitoria, char nickname[])
{
    int escolha;
    if (vitoria == 1)
    {
        clear_screen();
        FILE *arquivo;
        char nomeArquivo[] = "dialogo/n.txt"; // Nome do arquivo

        char linha[100];

        // Abre o arquivo para leitura
        arquivo = fopen(nomeArquivo, "r");

        // Lê e imprime cada linha do arquivo
        printf("Conteúdo do arquivo %s:\n", nomeArquivo);
        while (fgets(linha, sizeof(linha), arquivo))
        {
            printf("%s", linha);
        }

        // Fecha o arquivo
        fclose(arquivo);

        // printf("Treinador N: ...\nTreinador N: Hahahaha... eu perdi, né?\nTreinador N: Nunca pensei que pokémons poderiam lutar com tanto vigor... seus pokémons não estavam sendo forçados...\nTreinador N: Eles estavam lutando por vontade própria, para defender você.\n\n");

        // printf("Digite 1 para falar a primeira opção e 2 para falar a segunda:\n[1] Eu te disse N, nem todos os treinadores são ruins. Você deveria dar uma outra chance para o mundo.\n[2] Sua visão de mundo estava errada N, nem sempre o mundo é preto e branco, assim como mesmo com Victini ao seu lado, você perdeu.\n\n");

        scanf("%d", &escolha);

        while (escolha < 1 && escolha > 2)
        {

            printf("Digite um número válido!\n");
            scanf("%d", &escolha);
        }

        if (escolha == 1)
        {

            printf("%s: Eu te disse N, nem todos os treinadores são ruins. Você deveria dar uma outra chance para o mundo.\nTreinador N: Você está certo... você me mostrou outras possibilidades, %s.\nTreinador N: Que não existe só a minha realidade... um jovem sonhador que fez por merecer...\nTreinador N: E esse jovem é você. Até a próxima.\n\n", nickname, nickname);
            escolha = 0;
        }

        else
        {
            printf("%s: Sua visão de mundo estava errada N, nem sempre o mundo é preto e branco, assim como mesmo com Victini ao seu lado, você perdeu.\nTreinador N: Tem razão, o mundo é um cinza que testa seus ideais.\nTreinador N: Vivenciei incontáveis coisas durante essa jornada...\nTreinador N: Vou viajar para bem longe e repensar minhas ideias. Se cuida %s.\n\n", nickname, nickname);
            escolha = 0;
        }
    }

    else if (vitoria == 0)
    {

        clear_screen();
        FILE *arquivo;
        char nomeArquivo[] = "dialogo/nDefeat.txt"; // Nome do arquivo

        char linha[100];

        // Abre o arquivo para leitura
        arquivo = fopen(nomeArquivo, "r");

        // Lê e imprime cada linha do arquivo
        printf("Conteúdo do arquivo %s:\n", nomeArquivo);
        while (fgets(linha, sizeof(linha), arquivo))
        {
            printf("%s", linha);
        }

        // Fecha o arquivo
        fclose(arquivo);

        printf("													Treinador N: Como eu te disse, %s... sua amizade com seus pokémons não é forte o bastante. Patético.\n", nickname);
        printf("							  Digite 1 para falar a primeira opção e 2 para falar a segunda:\n							  [1] Eu posso ter perdido, N, mas isso não quer dizer que você esteja certo.\n							  [2] Impossível eu ter perdido, você trapaçeou!\n\n");

        scanf("%d", &escolha);

        while (escolha < 1 || escolha > 2)
        {

            printf("Digite um número válido!\n");
            scanf("%d", &escolha);
        }

        if (escolha == 1)
        {

            printf("							  %s: Eu posso ter perdido, N, mas isso não quer dizer que você esteja certo.\n\n													Treinador N: Isso quer sim que eu estou certo, meus ideais foram mais fortes, agora ninguém poderá impedir meu plano.\n												Treinador N: A gente se vê por aí, %s.\n\n", nickname, nickname);
        }

        else
        {

            printf("							  %s: Impossível eu ter perdido, você trapaçeou!\n													Treinador N: Sério, %s? Me acusando de trapaça? Não pensei que você chegaria tão baixo... isso mostra tanto sobre você.\n													Treinador N: Enfim, eu vou mudar o mundo, a gente se vê por aí, %s\n", nickname, nickname, nickname);
        }
        
    }
    getchar();
    getchar();
}
