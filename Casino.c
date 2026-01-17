//Este código está imcompleto,é apenas um teste de um casino
//TO DO:
	//regras slots
	//Roleta e as regras dela
//Feito:
	//slots
	//Blackjack
	//menu
	//regras do blackjack
	//Saldo acessivel atraves do menu(1000$)
#include<stdio.h>
#include<locale.h>
main()
{
setlocale(LC_ALL,"Portuguese");
srand(time(NULL));

int opcao = 0;
int saldo=1000;
int aposta;
//cartas minhas
int p1,p2,p3;
//cartas dealer
int d1,d2,d3;
//soma cartas minhas e dealer
int playertotal,dealertotal;
//total de ases meus e dealer
int playeraces,dealeraces;
//rolos
int r1,r2,r3;
char escolha,p;
//roleta
char corescolhida;
int numero,cor,escolha1,numeroescolhido;
while(opcao!=6)
{
    system("cls");
    printf("===== CASINO =====\n");
    printf("1 - Play Blackjack\n");
    printf("2 - Play Slots\n");
    printf("3 - Play Roulette\n");
    printf("4 - Check balance\n");
    printf("5 - Rules\n");
    printf("6 - Quit\n");
    
    scanf("%d",&opcao);

    switch(opcao){

    case 1:{
        playeraces=0;
        dealeraces=0;

        p1=rand()%13+1;
        if(p1>10) p1=10;
        if(p1==1){ p1=11;playeraces++; }

        p2=rand()%13+1;
        if(p2>10) p2=10;
        if(p2==1){ p2=11;playeraces++; }

        playertotal=p1+p2;

        d1=rand()%13+1;
        if(d1>10) d1=10;
        if(d1==1){ d1=11;dealeraces++; }

        d2=rand()%13+1;
        if(d2>10) d2=10;
        if(d2==1){ d2=11;dealeraces++; }

        dealertotal=d1+d2;

        system("cls");

        printf("How much do you want to bet?:");
        scanf("%d",&aposta);

        if(aposta>saldo){
            printf("You dont have enough money.\n");
            printf("\nPress Enter to return to the menu...");
            getchar();
            getchar();
            continue;
        }
        else{
            saldo=saldo-aposta;
        }

        printf("--------------------\nBLACKJACK\n--------------------\nYour cards:%d and %d\n",p1,p2);
        printf("Total:%d\n",playertotal);
        printf("Dealer's visible card:%d\n",d1);

        printf("Hit or Stand?(h/s): ");
        scanf(" %c",&escolha);

        if(escolha=='h')
        {
            p3=rand()%13+1;
            if(p3>10) p3=10;
            if(p3==1){ p3=11; playeraces++; }

            printf("You pulled:%d\n",p3);
            playertotal=playertotal+p3;

            if(playertotal>21 && playeraces>0){
                playertotal=playertotal-10;
                playeraces--;
            }

            printf("Your new total:%d\n",playertotal);
        }

        do
        {
            d3=rand()%13+1;
            if(d3>10) d3=10;
            if(d3==1){ d3=11; dealeraces++; }

            dealertotal=dealertotal+d3;

            if(dealertotal>21 && dealeraces>0){
                dealertotal=dealertotal-10;
                dealeraces--;
            }

        } while(dealertotal<17);

        printf("\nThe dealer had:%d and %d\n",d1,d2);
        printf("Dealer's total:%d\n",dealertotal);
        printf("Your total:%d\n",playertotal);

        if(playertotal==21){
            printf("Blackjack!!!");
            saldo=saldo+(2*aposta);
        }
        else if(playertotal>21){
            printf("Busted!\n");
            printf("Current balance:%d$",saldo);
        }
        else if(dealertotal>21){
            printf("You win!!!Dealer busts\n");
            saldo=saldo+(2*aposta);
        }
        else if(playertotal==dealertotal){
            printf("Push.\n");
            saldo=saldo+aposta;
        }
        else if(playertotal>dealertotal){
            printf("You win!!!\n");
            saldo=saldo+(2*aposta);
        }
        else{
            printf("You lost.Better luck next time!\n");
            printf("Current balance:%d$",saldo);
        }

        printf("\nPress Enter to return to the menu...");
        getchar();
        getchar();

    }break;

    case 2:{
        r1=rand()%7+1;
        r2=rand()%7+1;
        r3=rand()%7+1;

        system("cls");
        printf("How much do you want to bet?:");
        scanf("%d",&aposta);

        if(aposta>saldo){
            printf("You dont have enough money.\n");
            printf("\nPress Enter to return to the menu...");
            getchar();
            getchar();
            continue;
        }

        if(aposta <= 0){
            printf("Invalid bet amount.\n");
            printf("\nPress Enter to return to the menu...");
            getchar();
            getchar();
            continue;
        }

        saldo=saldo-aposta;

        printf("--------------------\nSLOTS\n--------------------\n");
        printf("Press 'p' to play:");
        scanf(" %c",&p);

        system("cls");
        printf("--------------------\nSLOTS\n--------------------\n");

        if(p=='p'||p=='P'){

            switch(r1){
                case 1:printf("[Cherry]");break;
                case 2:printf("[Lemon]");break;
                case 3:printf("[Bell]");break;
                case 4:printf("[7]");break;
                case 5:printf("[Diamond]");break;
                case 6:printf("[Star]");break;
                case 7:printf("[Heart]");break;
            }

            switch(r2){
                case 1:printf("[Cherry]");break;
                case 2:printf("[Lemon]");break;
                case 3:printf("[Bell]");break;
                case 4:printf("[7]");break;
                case 5:printf("[Diamond]");break;
                case 6:printf("[Star]");break;
                case 7:printf("[Heart]");break;
            }

            switch(r3){
                case 1:printf("[Cherry]\n");break;
                case 2:printf("[Lemon]\n");break;
                case 3:printf("[Bell]\n");break;
                case 4:printf("[7]\n");break;
                case 5:printf("[Diamond]\n");break;
                case 6:printf("[Star]\n");break;
                case 7:printf("[Heart]\n");break;
            }
        }

        if(r1==r2 && r2==r3){
            printf("JACKPOT!!!\n");
            saldo=saldo+(2*aposta);
        }
        else if(r1==r2||r2==r3||r3==r1){
            int premio=(aposta*3)/2;
            printf("You won %d$!\n",premio);
            saldo=saldo+premio;
        }
        else{
            printf("Better luck next time!\n");
        }

        printf("Current balance: %d$\n",saldo);
        printf("\nPress Enter to return to the menu...");
        getchar();
        getchar();

    }break;

    case 3:{
        system("cls");
        printf("===== ROULETTE =====\nBalance: %d$\n\n1 - Bet on a number\n2 - Bet on a color\n",saldo);
        scanf("%d",&escolha1);

        switch(escolha1)
        {
            case 1:{
                system("cls");
                printf("How much do you want to bet?(balance:%d):",saldo);
                scanf("%d",&aposta);

                if(aposta>saldo){
                    printf("You dont have enough money.\n");
                    getchar();
                    getchar();
                    continue;
                }
                saldo=saldo-aposta;
                printf("Choose a number between 0 and 36: ");
                scanf("%d",&numeroescolhido);
                numero=rand()%37;
                system("cls");
			    printf("Spinning the wheel...\n");
			    printf("Press Enter to continue...");
			    getchar();
			    getchar();
			    system("cls");
                printf("The winning number is: %d\n", numero);
                if(numeroescolhido==numero){
                    printf("Congratulations! You guessed the correct number!\n");
                    saldo=saldo+(aposta*35);
                }
                else{
                    printf("Better luck next time!\n");
                }
                printf("Current balance: %d$\n", saldo);
                printf("Press Enter to continue...");
                getchar();
                getchar();
            }break;
            case 2:{
                system("cls");
                printf("How much do you want to bet?(balance:%d):",saldo);
                scanf("%d",&aposta);
                saldo=saldo-aposta;
                system("cls");
                printf("Choose a color(r-Red/b-Black): ");
                scanf(" %c",&corescolhida);
                system("cls");
			    printf("Spinning the wheel...\n");
			    printf("Press Enter to continue...");
			    getchar();
			    getchar();
			    system("cls");
                numero=rand()%37;
                if(numero==0){
        			printf("The winning number is: 0\n");
        			printf("Number 0 has no color. You lose this round.\n");
   							 }
   				else if(numero==1||numero==3||numero==5||numero==7||numero==9||numero==12 || numero==14 || numero==16 || numero==18 ||numero==19 || numero==21 || numero==23 || numero==25 ||numero==27 || numero==30 || numero==32 || numero==34 || numero==36){
        			printf("The winning number is: %d\n",numero);
        			printf("Winning color: Red\n");
        		if(corescolhida=='r'||corescolhida=='R'){
            		printf("You guessed the correct color!\n");
            		saldo=saldo+(2*aposta);
        		} else {
            		printf("Better luck next time.\n");
        	}
    }
    else{
        printf("The winning number is: %d\n", numero);
        printf("Winning color: Black\n");
        if(corescolhida=='b'||corescolhida=='B'){
            printf("You guessed the correct color!\n");
            saldo=saldo+(2 * aposta);
        } else {
            printf("Better luck next time.\n");
        }
    }
    printf("Current balance: %d$\n",saldo);
    printf("\nPress Enter to return to the menu...");
    getchar();
    getchar();
            }break;
        }
    }break; 
    case 4:{
        system("cls");
        printf("Your balance is:%d$\n\n",saldo);
        printf("Press Enter to return to menu...");
        getchar();
        getchar();
    }break;
    case 5:{
        system("cls");
        printf("BLACKJACK RULES:\n");
        printf("1. Try to get a total of 21 or as close as possible.\n");
        printf("2. Number cards = their value, face cards = 10, Ace = 1 or 11.\n");
        printf("3. You play first, dealer plays after.\n");
        printf("4. If your total > 21, you bust and lose.\n");
        printf("5. If dealer busts, you win.\n");
        printf("6. Higher total wins. If tied, it's a push (tie).\n");
        printf("7. You can choose to hit (get another card) or stand.\n");
        printf("SLOTS RULES:\n");
		printf("1. Place a bet.\n");
		printf("2. Press 'p' to spin.\n");
		printf("3. 3 equal symbols = Jackpot.\n");
		printf("4. 2 equal symbols = Small win.\n");
		printf("5. No matches = You lose.\n");
        printf("ROULETTE RULES:\n");
		printf("1. Bet on a number or a color.\n");
		printf("2. Numbers go from 0 to 36.\n");
		printf("3. Correct number pays 35x.\n");
		printf("4. Correct color pays 2x.\n");
		printf("5. Number 0 has no color.\n");
        
        getchar();
        getchar();
    }break;
    }
}
getch();
}

