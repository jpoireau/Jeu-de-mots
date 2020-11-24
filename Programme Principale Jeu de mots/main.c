#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Affichemenu()
{
    printf("Ce programme permet de jouer avec les mots!\n");
    printf("Menu principal: \n");
    printf("C : Conjugaison\n");
    printf("Cet outil conjugue un verbe du 1er groupe saisi, au présent, à l’imparfait et au futur \n\n");
    printf("M : Miroir\n");
    printf("Cet outil affiche le mot saisi dans l'ordre inverse, comme dans un miroir ! \n\n");
    printf("P : Palindrome\n");
    printf("Cet outil vous dit si le mot que vous avez saisi est un palindrome, ou pas !\n\n");
    printf("O : Occurrence\n");
    printf("Cet outil vous dit combien il y a d'occurence dans une lettre choisie, dans un mot donné !\n\n");
    printf("Q : Quitter\n\n");
    printf("Choisissez ce que vous voulez faire, en saisissant la lettre: ");
}

void Conjugaison()
{
    char *pronomp[18] = {"Present\n\nje", "tu", "il/elle", "nous", "vous", "ils/elles", "Imparfait\n\nje", "tu", "il/elle", "nous", "vous", "ils/elles","Futur\n\nje", "tu", "il/elle", "nous", "vous", "ils/elles"};
    char *terminaison[18] = { "e", "es", "e", "ons", "ez", "ent\n", "ais", "ais", "ait", "ions", "iez", "aient\n", "erai", "eras", "erai", "erons", "erez", "eront\n"};
    char *adresseTerminaison;
    char verbe[10];
    char rep;
    int i = 0;
    while (rep != 'N')
    {
        printf("Donner un verbe du premier groupe :\n");
        do
        {
            gets (verbe);
            adresseTerminaison = verbe + strlen(verbe) - 2;
        }
        while ( strcmp ( adresseTerminaison, "er" ));
        for ( i=0; i<18; i++ )
        {
            strcpy(adresseTerminaison, terminaison[i]);
            printf("%s %s\n", pronomp[i], verbe );
        }
        printf("Voulez-vous recommencer (O/N)\n");
        scanf(" %c", &rep);
    }
}

void Miroir()
{
   void Miroir(char *mot)
{
    int i=0;
    int j=0;
    int taille = strlen(mot);
    char MotMiroir[taille + 1];

    for (i=taille-1;i>=0;i--)
    {
        MotMiroir[j]=mot[i];
        j++;
    }
    MotMiroir[j]='\0';
    printf("\nLe mot miroir a l envers est %s \n", MotMiroir);
}

{

    char mot[100],rep;
    printf("Ce programme permet d'afficher le mot saisi a l envers, comme dans un miroir !\n");
    while (rep != 'N')
    {
        fflush(stdin);
        printf("Entrez un mot : ");
        scanf("%s", mot);
        Miroir(mot);
        printf("Voulez-vous recommencer (O/N)\n");
        scanf(" %c", &rep);
    }

}


}

void Palindrome()
{

        char mot[100],rep;
        int i,j,l,ok,res;
    printf("Menu Palindrome :\n");
    printf("Ce programme permet de vous dire si votre mot est un palindrome !\n");
	while (rep != 'N')
    {
        printf("Entrer un mot:\n");
        scanf("%s",mot);
        l=strlen(mot);
        ok=0;
        for(i=0,j=l-1;i<l,j>=0;i++,j--)
        {
            res=strncmp(&mot[i],&mot[j],1); /*La fonction "strncmp" permet de comparer un nombre defini de caracteres.*/
            if(res!=0)
            {
                break;
            }
            else
            {
                ok++;
            }
        }
        if(ok==l)
        {
            printf("Le mot est un palindrome !\n");
        }
        else
        {
            printf("Le mot n'est pas un palindrome !\n");
        }
        printf("\nVoulez-vous recommencer (O/N)\n");
        scanf(" %c", &rep);
    }

}


void Occurrence()
{
   char c, mot[15], rep;
   int i, occurrence = 0;
    printf("Ce programme calcule le nombre d'occurrences d'une lettre dans votre mot ! \n");
   while (rep != 'N')
   {
   printf("Entrez un mot de 15 lettres ou moins : ");
   scanf("%s",mot);
   printf("Choisissez le caractere dont vous voulez connaitre le nombre d'occurence: ");
   scanf("%s",&c);
   for(i = 0; mot[i] != '\0' ; ++i)
   {
       if(mot[i] == c)
           ++occurrence;        /* Permet d'ajouter 1 à occurence sans faire occurence = occurence+1 */
   }

   printf("Le nombre d’occurrence de %c dans le mot %s est : %d\n",c ,mot ,occurrence);
   printf("Voulez vous recommencer (O/N)\n");
   scanf(" %c", &rep);
   }
}



int main()
{
    char NbOption;
    printf("La Valse des mots\n\n");
    while (NbOption != 'Q')
    {
        Affichemenu();
        fflush(stdin);
        NbOption = '\0';
        scanf("%c", &NbOption);
        if (NbOption == 'C')
        {
            Conjugaison();
        }
        if (NbOption == 'M')
        {
            Miroir();
        }
        if (NbOption == 'P' )
        {
            Palindrome();
        }
        if (NbOption == 'O' )
        {
            Occurrence();
        }
    }
    return 0;
}
