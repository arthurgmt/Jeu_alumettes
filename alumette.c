#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printcredits(){
    printf("\n\t\t***************************************************\n\t\t********************* CREDITS *********************\n\t\t***************************************************\n\n");
    printf("\n\n\t\t  SEBASTIEN DEJEAN\t\tARTHUR GUILLAUMOT\n\ntouts droits réservés.\n\n");

}

void print_alumettes(int a){
    for (int i =0; i<a; i++){
        printf("! ");
    }
    printf("il reste %d alumettes\n\n", a);
}

int choix_alumette(int nbalumettes){
    for (int j=1;j<=3;j++){
        if ((nbalumettes-1) % 4 ==1){
            return j;
        }
    }
    return (1 + (rand()%3));
}

void launch_game(){

    int alumuettes;
    int turn = rand()%2;

    int ordi=0;

    int niv = 0;
    int nb =0;

    while(alumuettes < 10 || alumuettes > 40){
        printf("\n\nChoisir le nombre d'alumettes (entre 10 et 40) :");
        scanf("%d",&alumuettes);
    }

    printf("\n\nDébut de la partie \n");

    printf("\n0 - Mode multijouer\n1 - Mode ordinateur\n");
    scanf("%d",&ordi);

    if (ordi){
        printf("Choix du niveau de l'ordinateur : \n\n0 - Niveau naïf\n1 - Niveau expert\n choix du niveau : ");
        scanf("%d",&niv);


        while(alumuettes>0){
            print_alumettes(alumuettes);

            if(turn%2 == 0){
                while (nb < 1 || nb > 3){
                    printf("J1 - Nombre d'alumette à enelver : ");
                    scanf("%d",&nb);
                    printf("\n");
                }

            }else if(niv){
                nb = choix_alumette(alumuettes);
                printf("l'ordi enlève %d alumettes\n\n", nb);
            }else{
                nb = 1+(rand()%3);
                printf("l'ordi enlève %d alumettes\n\n", nb);
            }

            turn+=1;
            
            alumuettes = alumuettes - nb;
            nb=0;
        }

        if (turn%2==1){
            printf("\nVous avez perdu !\n");
        } else{
            printf("\nVous avez gagné !\n");
        }
    }else{
        while(alumuettes>0){
            print_alumettes(alumuettes);

            if(turn%2 == 0){
                while (nb < 1 || nb > 3){
                    printf("J1 - Nombre d'alumette à enelver : ");
                    scanf("%d",&nb);
                    printf("\n");
                }

            }else{
                while (nb < 1 || nb > 3){
                    printf("J2 - Nombre d'alumette à enelver : ");
                    scanf("%d",&nb);
                    printf("\n");
                }
            }

            turn+=1;
            
            alumuettes = alumuettes - nb;
            nb=0;
        }

        if (turn%2==1){
            printf("\nLe joueur 2 a gagné !\n");
        } else{
            printf("\nLe joueur 1 a gagné !\n");
        }
    }
    

}


void console(void){
    printf("\n\t\t* Jeu des alumettes *\n\n1 - Jouer\n2 - Voir les regles\n3 - Voir les crédits\n4 - Quitter\n");

    int n;
    scanf("%d",&n);

    switch(n){

        case 1:
            launch_game();
            printcredits();
            console();
            break;

        case 2:
            printf("\n\nLe but du jeu est simple:\n\nCe jeu se joue à deux. Vous avez un nombre n d'alumettes.\nA tour de role, chaque joueur enlve entre 1 et 3 alumettes. Le perdant est celui qui enlève la dernière alumette\n\nIl existe deux modes de jeu :\n1 - mode multijoueur\n2 - mode contre ordinateur\nDeux difficultés sont disponibles, naif ou expert.\n\n");
            console();
            break;

        case 3:
            printcredits();
            console();
            break;

        case 4:
            break;
        
        default:
            break;
    }
}

int main(void){
    srand(time(NULL));

    console();

    return 0;
}
