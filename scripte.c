#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//_________________________| * definie des nouveaux variable * |____________________//


typedef struct employer employer;// un variable employer qui definier les neauds de la liste cheenie

//_________________________| * pointeur fichier * |____________________________________//


FILE *fichier = NULL; // creation d'un pointeur (fichier) globale qui pointie sur le fichier employer.txt

 
//__________________________| * les strecture * |_______________________________________//


typedef struct employer{
    /*______________________________________________
      ______________________________________________
      
    les information des employer !!*/
    
    char nom[15]; // le nome 
    char pren[15]; // le prenom
    float saler; // le saler
    
    /*___________________________________________
      ___________________________________________
      
    la partie de strecture que pointie sur la strecture suivant*/
    employer *next;
    /*_____________________________________________*/
}employer;


//___________________________________| * declaration des fonction * |_____________________________//


employer *ajouter(employer *);//ajouter un employer
void menu(employer *); // le menu de ce programme
void afficher(employer *); // afficher les employer
void rechercher(employer *); //recherche par le nom et afficher les employer de meme nom
employer *remplir(employer *);//remplire le contenue de fichier dans la strecture
employer *suprimer(employer *head);//fonction pour suprimer tous le contenue de la list chainie

//_________________________________| * les variable globale * |_______________________//

int remp=0;// ce variable est ajouter pour remplire la liste chenie un seul fois

//________________________| * la fonction menu * |___________________________________//


void menu(employer *head){
    if (remp == 0){
        head = remplir(head); // apeuler la fonction remplir pour remplire le contenue de fichier dans la liste chainie
        remp=1;
    }
    int n, k=0;
    char d;
    /*
            les varible:
                    k: un entier ontrons par l'utilisateur pour chois numero de service
                    n: un contoure pour ajoute plusieur employer
    */
    printf("\t[*_*]. Welcome to the worker management program .[*_*]\n\n");// definies l'utilisation de cette fonction a l'utilisatuer
    
    printf("\t\t [!]. to see all the workers press 1.\n\t\t [!]. To add a new worker press 2.\n\t\t [!]. To searsh a worker press 3.\n\t\t [!]. To exit the program press 4.\n\n\t\t\t>>>>>>> "); // afficher tous les service de programme
    scanf("%s", &d);
    system("clear"); // aprer de lire le nombre de service en clearer le terminal
    k = ((int) d) - 48; // conver le char to int pour ivider les erreur de ce programme
    switch(k){
        case 1:
            afficher(head); // afficher tous les employer qui existe sur la list 
            break;
        case 2:
                ajout: // point d'arriver si l'utilisateur need to ajoute un autre employer
                n=0; // fixer un contour sur 0
                head = ajouter(head); // appeler la fonction d'affichage qui retourne le debut de la list
                printf("[!]. To add another worker click 1: ");// question a l'utilisateur si nous vodrant a ajout un autre employer
                scanf("%s", &d); // changer la valeur de contoure
                n = ((int) d) - 48;
            if ( n==1 ){    // |
                goto ajout; // | --> si l'utilisateur est taper 1 en aller à la point de d'arriver (ajout)
            }               // |
            system("clear");// piusque nous nous voudrons n'ajote pas l'employer en suprimer le terminale
            menu(head); // afficher la fonction menu
            break;
        case 3:
            rechercher(head); // appeler de la fonction qui rechercher un employer
            break;
        case 4:
            system("clear"); // suprimer le terminal
            printf("\t\t[^_^]. thinks for use our programme.\n\n"); // afficher le missage de remerci a l'utilisateur
            break;
        default :
            system("clear"); // suprimer le terminal
            printf("[!]. Service Unavailable. \n"); // affiche un message d'erreur
            menu(head); // afficher le menu
    }
}

//_______________________________| * la foction remplire  * |____________________________//

employer *remplir(employer *head){
    employer *noEl, *elptr;   // craetion des deux pointeur qui pointie sur la list chainie
    fichier = fopen("employer.txt","r"); // ouvre le fichier en red mode
    
    if (fichier == NULL){
        printf("the file not existe"); // gestion des erreur
    } else {
        while (!feof(fichier)){ // pour lire tous le contenue de fichier dans notre list
        
            noEl = (employer *)malloc(sizeof(employer)); // alloction dinamique de memoire pour le nouvell element
            fscanf(fichier, "%s", noEl->nom);//le nom prendre la premier ensemple des caracter
            fscanf(fichier, "%s", noEl->pren);//le prenom prendre le deuxiemme chaine de caracter 
            fscanf(fichier, "%f", &noEl->saler); // le saler prendre le 3eme char qui est sou forme de float par defeau
            
            noEl->next=NULL; // le nouvelle element pointie sur NULL care en le ajoute à la fine de list chaine 
            //___________________________________
            if(head==NULL){                     //
                head = noEl;                    //
            } else {                            //
                elptr = head;                   //
                while(elptr->next != NULL){     // ajouter le nouvelle element a la fin de la list chaine
                    elptr = elptr->next;        //
                }                               //
                elptr->next = noEl;             //
            }                                   //
            //___________________________________
        }
        
    }
    fclose(fichier);
    return head;
}

//___________________________| * fonction suprimer * |___________________________//

employer *suprimer(employer *head){
    employer *ptr; // un pointeur qui pointie sur le premier element
    if(head != NULL){
        ptr = head; //le pointeur ptr prendre le premier element
        head = head->next; // le head est pointie sur le deuxieme element
        free(ptr); //libirer la memoir
    }
    return head; // return le premier valeur de la list qui été le deuxieme de la list
}
 

//___________________| * fonction pour afficher la list chainee * |______________//


void afficher(employer *head){
    printf("\t| ** |. tous les employer qui existe .| ** |\n\n");// message a l'utilisateur que la fonction est afficher tous les employer
    employer *ptr; // creation d'un pointer qui pointie sur le strecture employer
    ptr = head; // le pointer prendre aux premier fois le premier strectere de la liste
    if( ptr != NULL ){
    /*    si le ptr est pas null ou d'autre face le pointer est plen en entre dans le boucle */
        while (ptr->next != NULL){
            printf("The last name is: %s\nthe first name is: %s\nthe salery is: %f\n", ptr->nom, ptr->pren, ptr->saler ); // affichage de la partie que admet les information de l'employer
            ptr = ptr->next; // le pointeur est pointer sur l'address de la strecture suivant
            printf("\n=====================================\n");
        }
    } else {
        printf("[!]. the list is NULL\n\n");// gestion des erreur si la liste est vide
    }
    menu(head); // revien a la menu
}



//___________________________| * la onction pour ajouter des emploiyer * |_______________//

employer *ajouter(employer *head){
    system("clear");
    printf("\t\t| ** | add a new worker | ** |\n\n");
    char nom[9], prenom[9];
    float saler;
    /*
        les variable:
            nom[9]: le nom de l'employer qui nous vedrant de le ajouter sur la liste
            prenom[9]: le prenom de l'employer qui vedrant de le ajouter sur la list
            saler: le saler de l'employer qui en ajouter
    */
    employer *noEl, *temp;
    /*
        les pointer de type employer:
                            noEl: (nouveauEmployer) qui prendre les information de l'employer
                            temp: un pointeur qui prendre les informaion de l'employer pour chercher le dernier empoyer
    */
    
    noEl = (employer *)malloc(sizeof(employer)); // l'allocation denamice de la memoire
    
    fichier = fopen("employer.txt","a");
    //ouverture de la fichier employer employer pour ajouter les nouvelle information à la fine de fichier
    
    printf("[+]. the last name: ");
    scanf("%s", &nom);
    //^ lire le nom de l'employer
    printf("[+]. the first name: ");
    scanf("%s", &prenom);
    //^ lire le prenom de l'employer
    printf("[+]. worker salery: ");
    scanf("%f", &saler);
    //saler lire le nom de l'employer
    // ajouter les information de le nouvelle employer en fichier employer.txt
    if ( fichier == NULL ){
        printf("[!]. the file \"employer.txt\" is not exist .[!]"); // gestion des erreur
    } else {
        fprintf(fichier, "%s %s %f\n", nom, prenom, saler);//remplire dons le fichier
    }
    fclose(fichier);// close the file
    //_____________________________
    while(head->next = NULL){     //
        head = suprimer(head);    //    supimer tous les contenue de la liste chainie
    }                             //
    //_____________________________|
    system("clear");
    remp = 0; // donner le variable remplire 0 pour que en complet l'ajoute des employer en remplire un autre fois le fichier
    return head; // en retourne le premier strecture de la listr
}

//_______| * la fonction recherche pour rechercher des employer si existe * |_________________//


void rechercher(employer *head){
    system("clear");
    printf("\n\t\t| ** | searsh for a worker | ** |\n\n");
    char nom[9]; // prend le nom d'employer 
    printf("[!]. the last name of the worker: ");
    scanf("%s", &nom); 
    system("clear");
    employer *element; // creation d'un element empoyer qui pointie sur notre list des employer
    element = head; // le poineur element est pointie sur la premier dtrecture de la list
    if ( element == NULL ){
        printf("[!]. the file is NULL."); // gestion des erreur si la list est null
    } else {
        // vois tous la list
        while ( element != NULL ){
            if ( strcmp(element->nom, nom)==0){ // tester si le nom qui entre l'utilisateur est le meme le nom qui est dans la list en afficher tous les info dans la list
                printf("last name: %s\nfirst name: %s\nsalery: %f\n", element->nom, element->pren, element->saler);
                printf("\n=====================================\n");
            }
            element = element->next; // le pointer est point sur le next strecture
        }
    }
    menu(head);
    
}


//___________________________________| * la fonction principale * |___________________________//


void main(void){
    employer *emp;
    system("clear");
    menu(emp);
}

