#include <stdio.h>
#include <stdlib.h>

int main()
{
    //BUT : faire la conversion des chiffres arabes en chiffres romains et vice-versa
    //ENTREES : un entier ou une chaine de caracteres saisis par l'utilisateur
    //SORTIES : la conversion

    //--- DECLARATION ET INITIALISATION DES VARIABLES ---//
    char cTbChiffreRomain[8] = "MDCLXVI";
    int cTbChiffreArabe[8] = {1000, 500, 100, 50, 10, 5, 1};
    char cChiffreRom[30];
    int nNbre = 0;
    int cpt = 0;
    int res = 0;
    int dernierChiffre = 0;
    int nChoix = 0;

    //--- CHOIX DE L'UTILISATEUR SUR LA CONVERSION ---//
    printf("Bonjour, veuillez taper 1 pour la conversion chiffres arabes vers chiffres romains et 2 pour le contraire : ");
    scanf("%d", &nChoix);


    //--- CHIFFRES ARABES VERS CHIFFRES ROMAINS ---//
    if(nChoix==1){
        fflush(stdin);
        printf("Veuillez rentrer votre nombre : ");
        scanf("%d", &nNbre);
        printf("Le nombre choisi est : ");

        while(cpt<7){ //tant que cpt est supérieur à 7
            if ((nNbre%cTbChiffreArabe[cpt])>=(cTbChiffreArabe[cpt+1]*4) && cpt<6){ //si nNbre modulo la valeur cpt du tableau cTbChiffreArabe est supérieur ou égal à la valeut cpt+1*4 du tableau cTbChiffreArabe ET que cpt est inférieur à 6
                printf("%c", cTbChiffreRomain[cpt+1]); //alors écrire la valeur cpt+1 du tableau cTbChiffreRomain
                nNbre+=cTbChiffreArabe[cpt+1]; //nNbre prend la valeur lui-même+la valeur cpt+1 du tableau cTbChiffreArabe
                cpt = 0;
                continue;
            }
            while(nNbre>=cTbChiffreArabe[cpt]){ //tant que nNbre est supérieur ou égal à la valeur cpt du tableau cTbChiffreArabe
                printf("%c", cTbChiffreRomain[cpt]); //écrire la valeur cpt du tableau cTbChiffreRomain
                nNbre-=cTbChiffreArabe[cpt]; //nNbre prend la valeur lui-même moins la valeur cpt du tableau cTbChiffreArabe
            }
        cpt++; //cpt prend lui-même + 1
        }
    }


    //--- CHIFFRES ROMAINS VERS CHIFFRES ARABES ---//
    else if(nChoix==2){
        fflush(stdin);
        printf("Veuillez rentrer votre chiffre romain en lettres majuscules : ");
        scanf("%s", &cChiffreRom);
        printf("Le chiffre romain choisi est : ");

        while(cChiffreRom[cpt]){
            nNbre=0;
            while(cTbChiffreRomain[nNbre]){
                if(cChiffreRom[cpt]==cTbChiffreRomain[nNbre]){ //si la valeur de cpt du tableau cChiffreRom est égale à la valeur nNbre du tableau cTbChiffreRomain
                    res=res+cTbChiffreArabe[nNbre]; //alors res prend lui-même + la valeur nNbre du tableau cTbChiffreArabe
                    if (dernierChiffre<cTbChiffreArabe[nNbre]){ //si dernierChiffre< à la valeur nNbre du tableau cTbChiffreArabe
                        res=res-dernierChiffre*2; //res prend lui-même moins dernierChiffre*2
                    }
                    dernierChiffre=cTbChiffreArabe[nNbre]; //dernierCHiffre prend la valeur en cpt du tableau cTbChiffreArabe
                }
                nNbre++; //nNbre prend lui-même + 1
            }

            cpt++; //cpt prend lui-même + 1
        }
        printf("%d", res);
    }
    else{
        printf("Vous etes un monstre");
    }

    return 0;
}
