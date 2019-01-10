/* 
            PROGETTO: PROGRAMMA PER LA GESTIONE DI UNA FESTA DI LAUREA
                            DI: SALVATORE NITOPI
*/

#include <stdio.h>
#include <stdlib.h>

#define max_persona 100

int cont_persona = 0; 
int cont_regalo = 0;
int cont_tavolo = 0;

int p1,p2,p3,p4,p5,p6,p7;                                // Variabili per permettere scelta persone      

float regali_dec [200];                
float regali_cre [200];

struct persona {
        int codice_p;
        char nome [12];
        char cognome [12];
        int eta;
        int sesso;                             // 0 = maschio, 1 = femmina
        int tipo;                              // 0 = amico, 1 = parente
        };

struct nodo_persona {                        //Struttura nodo per lista invitati
       struct persona inf;
       struct nodo_persona * next;
};

struct nodo_persona *testa_p;

/////////////////////////////////////////

struct regalo {
       int codice_r;
        char tipo [20];
        float prezzo;
        int info;                              // 0 = Non gradito, 1 = gradito
        };
        
struct nodo_regalo {
       struct regalo inf;
       struct nodo_regalo * next;
       };
       
struct nodo_regalo *testa_r;


//////////////////////////////////////////


struct simpatia {
       
       struct persona inf_p1;
       struct persona inf_p2;
       float valore;
       };
       
       
struct nodo_simpatia {
       
       struct simpatia inf;
       struct nodo_simpatia *next;
       
       };
       
struct nodo_simpatia *testa_s;

///////////////////////////////////////////

struct tavolo {
       
       int codice_t;
       struct persona inf_p1;
       struct persona inf_p2;
       struct persona inf_p3;
       struct persona inf_p4;
       struct persona inf_p5;
       float valore;
       };
       
       
struct nodo_tavolo {
       
       struct tavolo inf;
       struct nodo_tavolo *next;
       
       };
       
struct nodo_tavolo *testa_t;




//prototipi funzioni
void messaggio_attenzione (char mess [100]);
void messaggio_errore (char mess [100]);

void inizializza ();

void inserisci_persona ();
void visualizza_persona ();
int visualizza_persona_se ();
struct persona trova_persona (int id);

void inserisci_regalo ();

void Ordina_Regali ();
float Calc_Val_Regali ();
struct regalo Calc_Max_Regali ();
void stampa_regali_dec ();
int n_regali_minimo (float b);                                                 

void inserisci_simpatia (int id_persona_1,int id_persona_2, float valore);
float verifica_simpatia (int id_persona_1, int id_persona_2);
int verifica_conoscenza (int id_persona_1);
int verifica_antipatia_sesso (int id_persona_1, int sesso);
int verifica_piu_simpatico (int id_persona_1);
int simpatia_doppia_numero (int id_persona_1, int id_persona_2);

char simpatia_doppia_nomi (int id_persona_1, int id_persona_2);                  // (PASSARE STRING)
int verifica_antipatia_doppia (int id_persona_1, int id_persona_2);              

int tutti_conoscenti (int id_persona_1, int id_persona_2, int id_persona_3);
int triangolo_simpatico (int id_persona_1, int id_persona_2, int id_persona_3);
int conta_triangoli_simpatici ();               

void inserisci_tavolo ();        
void visualizza_tavolo ();
struct tavolo trova_tavolo (int id);
int tipo_tavolo(int id_tavolo);
int verifica_sostituzione_tavolo (int id_tavolo, int id_persona_1);
int Amici_Casuali (int id_tavolo);

int main (){
    
    inizializza ();
    menu ();
    
}



menu (){
     
     struct nodo_persona *lista_persone = NULL;
     
     int scelta = 0;
     
     printf ("\n\t\t\t\t   MENU'");
     printf ("\n_______________________________________________________________________________\n");
     
     printf ("\n\t     PERSONE\t\t\t\t     REGALI");
     printf ("\n---------------------------------\t---------------------------------");
     printf ("\n1)  Inserisci persona\t\t\t20) Inserici regalo");
     printf ("\n2)  Visualizza invitati\t\t\t21) Valore totale regali");
     printf ("\n3)  Inserisci simpatia\t\t\t22) Regalo piu' costoso");
     printf ("\n4)  Ver. simpatia\t\t\t23) N. Regali Min.");
     printf ("\n5)  Ver. conoscenza\t\t\t24) Regali dec");
     printf ("\n6)  Ver. antipatia sesso\t\t");
     printf ("\n7)  Persona piu' simpatica\t\t");
     printf ("\n8)  N. per. simpatiche a 2 per.\t\t\t     TAVOLI");
     printf ("\n9)  N. per. antipatiche a 2 per.\t--------------------------------");
     printf ("\n10) Triangolo conoscenti\t\t30) Inserisci tavolo");
     printf ("\n11) Triangolo simpatico\t\t\t31) Definizione tipo tavolo");
     printf ("\n12) Conta triangoli simpatici\t\t32) Verifica sostituzione");
     printf ("\n\t\t\t\t\t33) Amici_Casuali");
          
     printf ("\n\n0)Esci");
     printf ("\n\t\t\t\t\t    Salvatore Nitopi e Dario Quagliata");
     
     printf ("\n______________________________________________________________________________\nScegli un opzione: "); 
     scanf ("%d",&scelta);
     
if (((scelta >= 0) && (scelta <= 12)) || ((scelta >= 20) && (scelta <= 24)) || ((scelta >= 30) && (scelta <= 33)) || (scelta == 55)){
                 
                 switch (scelta) {
                        
                        case 0:
                            printf ("\a");
                            system("cls");  
                            
                                messaggio_attenzione ("\n\n\n\n\n\t\t\t Sei sicuro di volere uscire?");
                                exit(1);
                                        
                             break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////                 
                        case 1:                  
                             printf ("\a");
                             system("cls");
                             
                                 if (cont_persona <= max_persona) {                 
                                    inserisci_persona ();
                                    }
                                    
                                    else {
                                         messaggio_errore ("\t\t     E' stato raggiunto il limite di persone");
                                         }
                             
                             system("cls");
                             menu ();
                             break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////            
                        case 2:                  //Stampa dati persona
                             printf ("\a");
                             system("cls");
                             
                                 visualizza_persona ();   
                
                             system("cls");
                             menu ();
                             break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////                  
                        case 3:                    //Inserisce simpatia tra due persone
                             printf ("\a");
                             system("cls");
                                           
                                           
                                if (cont_persona > 1){ 
                                                   struct persona temp_persona_1;
                                                   struct persona temp_persona_2;
                                                   float val_simpatia = 0;
                                     
                                                   visualizza_persona_se ();
                                     
                                            printf ("\n\n");
                                            printf ("\nInserisci l'id della prima persona: "); scanf ("%d",&p1);
                                            printf ("\nInserisci l'id della seconda persona: "); scanf ("%d",&p2);
                                            
                                            if (p1 == p2){
                                               messaggio_errore ("\t\t      E' stata inserita la stessa persona");
                                               }
                                            
                                            else {
                                            
                                                    temp_persona_1 = trova_persona (p1);          
                                                    temp_persona_2 = trova_persona (p2);
                                                    
                                                                                                
                                                                
                                                    system ("cls");
                                                    
                    
                                                          
                                                    printf ("\nIl grado di simpatia puo' essere esprsso nell'intervallo [-1 ; 1]");
                                                    printf ("\n\nDove per 1 si intende SIMPATIA ASSOLUTA e per -1 ANTIPATIA ASSOLUTA \n");
                                                    printf ("\n\n\t\t%s %s -------> %s %s\n",temp_persona_1.nome,temp_persona_1.cognome,temp_persona_2.nome,temp_persona_2.cognome);
                                                    printf ("\n\nInserisci quanto %s %s prova simpatia verso %s %s: ",temp_persona_1.nome,temp_persona_1.cognome,temp_persona_2.nome,temp_persona_2.cognome); scanf ("%f",&val_simpatia);
                                                           
                                                           
                                                           inserisci_simpatia (p1,p2,val_simpatia);
                                         
                                         }
                                  }  
                                  
                                     else {
                                         messaggio_errore ("\t\t      Devono esserci almeno due persone");
                                         }
                
                             system("cls");
                             menu ();
                             break;                 
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////                  
                        case 4:                    //Verifica simpatia tra due persone
                             printf ("\a");
                             system("cls");
                             
                                 if (visualizza_persona_se () != 0) { 
                             
                                 printf ("\n\n\nInserisci l'id della prima persona: "); scanf ("%d",&p1);
                                 printf ("\nInserisci l'id della prima persona: "); scanf ("%d",&p2);
                                
                                 
                                 if (p1 == p2){
                                               messaggio_errore ("\t\t      E' stata inserita la stessa persona");
                                               }
                                            
                                            else {
            
                                 
                                                 float simpatia_2_persone = verifica_simpatia (p1,p2);
                                 
                                                 
                             
                                 printf ("\n\nValore simpatia: %f ", simpatia_2_persone);
                                 getch ();
                                 
                                 }
                                 }
                             system("cls");
                             menu ();
                             break;                 
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////                                
                       case 5:                      //Verifica quante persone conosce
                             printf ("\a");
                             system("cls");
                             
                                 if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                                           
                                     printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                    
                                     
                                     int n_persone_non_conosciute = verifica_conoscenza (p1);
                                 
                                     system ("cls");
                                     printf ("\n\nNumero persone non conosciute: %d ", n_persone_non_conosciute);
                                     getch ();
                                 }
                                 
                                 getch ();
                
                             system("cls");
                             menu ();
                             break;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                       case 6:                      //Verifica antipatia per sesso
                             printf ("\a");
                             system("cls");
                             
                                 if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                     
                                     int sesso_p;                                         // 0 Maschi, 1 Femmine, inizializzo a 2 per scelta
                                                           
                                     printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                     
                                     do{
                                         printf ("\nSesso: \t\tPremi 0 per uomo\n\t\tPremi 1 per donna\n\t\t  Scelta: "); scanf ("%d",&sesso_p);
                                                if (sesso_p != 0 && sesso_p != 1){
                                                                    printf ("\n\n\tERRORE: %d NON E' UN VALORE VALIDO !!\n",sesso_p);
                                                                    } 
                                    } while (sesso_p != 0 && sesso_p != 1);
                                                              
                                     int n_persone_antipatiche = verifica_antipatia_sesso (p1,sesso_p);
                                 
                                     system ("cls");
                                     
                                            if (sesso_p == 1)
                                               printf ("\nPersone di sesso femminile ");
                                               
                                               else
                                                   printf ("\nPersone di sesso maschile ");
                                     
                                     printf ("antipatiche: %d ", n_persone_antipatiche);
                                     getch ();
                                 }
                                 
                                 getch ();
                
                             system("cls");
                             menu ();
                             break;                 
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                        case 7:                      //Trova persona più antipatica
                             printf ("\a");
                             system("cls");
                             
                                 if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                     
                                     int id_p_s;
                                     struct persona persona_piu_simpatica;
                                     
                                     printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                     
                                            if (verifica_piu_simpatico (p1) > 0){
                                            
                                                 id_p_s = verifica_piu_simpatico (p1);
                                                 
                                                 persona_piu_simpatica = trova_persona (id_p_s);
                                                 
                                                 printf ("\nLa persona piu' simpatica e' %s %s.", persona_piu_simpatica.nome, persona_piu_simpatica.cognome);
                                                 }
                                     
                                     else {
                                            
                                            system("cls");
                                            printf ("\nNON PROVA SIMPATIA PER NESSUNO");
                                            
                                            }
                                 }
                                 
                                 getch ();
            
                             system("cls");
                             menu ();
                             break;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                        case 8:                      //Verifica quante persone conosce
                             printf ("\a");
                             system("cls");
                             
                                 if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                                           
                                     printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                     printf ("\n\nInserisci l'id della persona: "); scanf ("%d",&p2);
                                     
                                     int n_persone_doppiamente_simpatiche = simpatia_doppia_numero (p1,p2);
                                 
                                     system ("cls");
                                     printf ("\n\nStanno simpatiche a entrabi %d persone ", n_persone_doppiamente_simpatiche);
                                     getch ();
                                 }
                                 
                                 getch ();
                
                             system("cls");
                             menu ();
                             break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      case 9:                      //Verifica quante persone conosce
                             printf ("\a");
                             system("cls");
                             
                                    if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                             
                                                                   
                                             printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                             printf ("\n\nInserisci l'id della persona: "); scanf ("%d",&p2);
                                             
                                                                      
                                             int n_persone_antipatiche = verifica_antipatia_doppia (p1,p2);
                                         
                                             system ("cls");
                                             
                                             printf ("Antipatiche: %d ", n_persone_antipatiche);
                                             getch ();
                                         }
                
                             system("cls");
                             menu ();
                             break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                       case 10:                      //Verifica quante persone conosce
                             printf ("\a");
                             system("cls");
                             
                                    if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                             
                                                                   
                                             printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                             printf ("\n\nInserisci l'id della persona: "); scanf ("%d",&p2);
                                             printf ("\n\nInserisci l'id della persona: "); scanf ("%d",&p3);
                                            
                                             system("cls");
                                                                      
                                             int val = tutti_conoscenti (p1,p2,p3);
                                         
                                             if (val == 0)
                                                printf ("Le tre persone non si conosco fra loro");
                                                
                                                else
                                                    printf ("Le tre persone si conoscono fra loro");
            
                                             getch ();
                                         }
                
                             system("cls");
                             menu ();
                             break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                       case 11:                      //Triangolo simpatico
                             printf ("\a");
                             system("cls");
                             
                                    if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                             
                                                                   
                                             printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                             printf ("\n\nInserisci l'id della persona: "); scanf ("%d",&p2);
                                             printf ("\n\nInserisci l'id della persona: "); scanf ("%d",&p3);
                                            
                                             system("cls");
                                                                      
                                             int val = triangolo_simpatico (p1,p2,p3);
                                         
                                             if (val == 0)
                                                printf ("Le tre persone non formano un triangolo simpatico");
                                                
                                                else
                                                    printf ("Le tre persone formano un triangolo simpatico");
            
                                             getch ();
                                         }
                
                             system("cls");
                             menu ();
                             break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                       case 12:                      //Verifica quante persone conosce
                             printf ("\a");
                             system("cls");
                                           
                                           conta_triangoli_simpatici ();
                                    int possibili_triangoli_simpatici = conta_triangoli_simpatici ();
                                    
                                                    printf ("TRIANGOLI possibili (senza ripetizione elementi): %d",possibili_triangoli_simpatici);
                                                    printf ("\nTRIANGOLI possibili (con ripetizione elementi): %d",possibili_triangoli_simpatici*6);
                                             getch ();
                                         
                
                             system("cls");
                             menu ();
                             break;                   
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                             /*case 13:                      //Nomi
                             printf ("\a");
                             system("cls");
                             
                                    if (visualizza_persona_se () != 0) {                     //Stampa output a video oltre che a verificare
                                             
                                                                   
                                             printf ("\n\n\nInserisci l'id della persona: "); scanf ("%d",&p1);
                                             printf ("\n\nInserisci l'id della persona: "); scanf ("%d",&p2);
                                             
                                            
                                                                      
                                             //char elenco_nomi [max_persona*25]; 
                                             //strcpy (elenco_nomi, simpatia_doppia_nomi(p1,p2));
                                         
                                             //system ("cls");
                                             
                                                    
                                             //simpatia_doppia_nomi(p1,p2);
                                             //printf ("Nomi: %s ",simpatia_doppia_nomi(p1,p2) );
                                             //getch ();
                                         }
                
                             system("cls");
                             menu ();
                             break; */                            
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        case 20:                  //Inserisci regalo
                             printf ("\a");
                             system("cls");
                             
                                 inserisci_regalo ();
                             
                             system("cls");
                             menu ();
                             break;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                        case 21:                  //Calcola val totale regali
                             printf ("\a");
                             system("cls");
                             
                                 float valore;
                                 valore = Calc_Val_Regali ();
                                 printf ("Il valore totale dei regali e' di: %f euro.", valore);
                                 getch ();
                
                             system("cls");
                             menu ();
                             break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////                  
                        case 22:                  //Stampa regalo più costoso
                             printf ("\a");
                             system("cls");
                             
                                 struct regalo costoso;
                                 costoso = Calc_Max_Regali ();
            
                                 
                                 printf ("Il regalo piu' costoso e' %s, e vale %f euro.",costoso.tipo,costoso.prezzo);
                                 getch ();
                
                             system("cls");
                             menu ();
                             break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                             case 23:                     
                             printf ("\a");
                             system("cls");
                                           
                                           
                                           float prezzo_min = 0;
                                           
                                           printf ("Inserisci l'importo da totalizzare: "); scanf ("%f",&prezzo_min);
                                           
                                           int n_regali = n_regali_minimo (prezzo_min);
                                           
                                           if (n_regali != -1){
                                              printf ("Numero di regali necessari: %d",n_regali);
                                              getch ();
                                              }
                                              
                                              else {
                                                   messaggio_errore ("\t\tL'importo e' superiore al valore totale dei regali");
                                                   }
                                           
                                             
                             system("cls");
                             menu ();
                             break;                    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        case 24:                     
                             printf ("\a");
                             system("cls");
                                           void Ordina_Regali ();
                                           stampa_regali_dec ();
                                             
                             system("cls");
                             menu ();
                             break;                      
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        case 30:                      //Inserisci tavolo
                             printf ("\a");
                             system("cls");
                                           
                                           inserisci_tavolo ();
                                          
                                               
                             system("cls");
                             menu ();
                             break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        case 31:                     
                             printf ("\a");
                             system("cls");
                                           
                                           int cod_tavolo = 0;
                                           int tipo = 0;
                                           
                                           visualizza_tavolo ();
                                           
                                           printf ("\nInserisci codice tavolo: "); scanf ("%d",&cod_tavolo);
                                           
                                           tipo = tipo_tavolo (cod_tavolo);
                                           
                                           system("cls");
                                           
                                                if (tipo == 2){
                                                   printf("\n TAVOLO ASSOLUTAMENTE PARIFICO");}
                                                   
                                                   else{
                                                   
                                                           if (tipo == 1){
                                                              printf("\n TAVOLO PARIFICO");
                                                              }
                                                              
                                                              else{
                                                              
                                                              if (tipo == 0)
                                                                 printf("\n TAVOLO LITIGIOSO");
                                                                 
                                                                 }
                                                         
                                                         }    
                                          getch ();
                                          
                                               
                             system("cls");
                             menu ();
                             break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        case 32:                     
                             printf ("\a");
                             system("cls");
                                           
                                           visualizza_tavolo ();
                                           
                                           printf ("\nInserisci codice tavolo: "); scanf ("%d",&cod_tavolo);
                                           
                                           system("cls");
                                           
                                           visualizza_persona_se ();
                                           
                                           printf ("\nInserisci codice persona: "); scanf ("%d",&p1);
                                           
                                           tipo = verifica_sostituzione_tavolo (cod_tavolo,p1);
                                           
                                           system("cls");
                                           
                                                if (tipo == 1){
                                                   printf("\n E' possibile eseguire la sostituzione");
                                                   }
                                                   
                                                   else{
                                                        printf("\n Non e' possibile eseguire la sostituzione");
                                                         }    
                                          getch ();
                                          
                                               
                             system("cls");
                             menu ();
                             break;                                                                       
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        case 33:                     
                             printf ("\a");
                             system("cls");
                                           
                                           visualizza_tavolo ();
                                            
                                           printf ("\nInserisci codice tavolo: "); scanf ("%d",&cod_tavolo);
                                           
                                           int ritorno = Amici_Casuali (cod_tavolo);
                                           
                                           system("cls");
                                           
                                               if (ritorno == 1){
                                                   printf ("Almeno una coppia di persone sedute al tavolo cod: %d, conosce un altra persona.",cod_tavolo);
                                                   }
                                                   
                                                   else{
                                                       printf ("Nessuna coppia di persone sedute al tavolo cod: %d, consce un altra persona.",cod_tavolo);
                                                       }
                                          
                                           
                                           getch ();
                                             
                             system("cls");
                             menu ();
                             break;
            
                 } // FINE SWITCH
            }// FINE IF
            
            else {
                 system("cls");
                 menu ();
                 }
            
}           // FINE FUNZIONE

void messaggio_attenzione (char mess [100]){
               
               int scelta;
               
               do{
                 printf ("\a\a\a\a");
                 system("cls");
                 printf ("\n\n\n\n\n\t\t\t\t ATTENZIONE");
                 printf ("%s",mess);
                 printf ("\n\n\n\n\t\t\tSI = 1\t\t\tNO = 0");
                 printf ("\n\n\n\t\t\t_______________________________");
                 printf ("\n\n\t\t\t\tScelta: "); scanf ("%d",&scelta);
               }while (scelta != 0 && scelta != 1);
                 
                 if (scelta == 0){
                            system("cls");
                            menu ();}
                            
                            else
                            system("cls");
             
}

void messaggio_errore (char mess [100]){
               
               system("cls");

                 printf ("\a\a\a\a");
                 printf ("\n\n\n");
                 printf ("\t ------------------------------------------------------------- ");
                 printf ("\n\n\t\t\t\t    ERRORE\n\n\n");
                 printf ("%s",mess);
                 printf ("\n\n\t ------------------------------------------------------------- ");
                 printf ("\n\n\n\t\t      Premere un tasto per continuare...\n\n\n");
                 getch ();
             
}



void inizializza (){
     testa_p = NULL; 
     testa_r = NULL; 
     testa_s = NULL;
     testa_t = NULL; 
     }



void inserisci_persona () {                                                     
     
     struct persona temp_inf;
     struct nodo_persona *nuovo, *prec, *temp;
     

       printf ("\n\n-----------------------------------------");
       cont_persona = cont_persona + 1;
       temp_inf.codice_p = cont_persona;       
       printf ("\nInvitato codice: %d\n\n",temp_inf.codice_p);
       printf ("Nome: \t\t"); scanf ("%s",&temp_inf.nome);
       printf ("Cognome: \t"); scanf ("%s",&temp_inf.cognome);
       printf ("Eta': \t\t"); scanf ("%d",&temp_inf.eta);
                                    
              do{
         printf ("\nSesso: \t\tPremi 0 per uomo\n\t\tPremi 1 per donna\n\t\t  Scelta: "); scanf ("%d",&temp_inf.sesso);
                if (temp_inf.sesso != 0 && temp_inf.sesso != 1){
                                    printf ("\n\n\tERRORE: %d NON E' UN VALORE VALIDO !!\n",temp_inf.sesso);
                                    }
                }while (temp_inf.sesso != 0 && temp_inf.sesso != 1);
                                    
                                   
              do{
         printf ("\nTipo: \t\tPremi 0 per amico\n\t\tPremi 1 per parente\n\t\t  Scelta: "); scanf ("%d",&temp_inf.tipo);
                if (temp_inf.tipo != 0 && temp_inf.tipo != 1){
                                    printf ("\n\n\tERRORE: %d NON E' UN VALORE VALIDO !!\n",temp_inf.tipo);
                                    }
                }while (temp_inf.tipo != 0 && temp_inf.tipo != 1);              
              
              nuovo = (struct nodo_persona *) malloc (sizeof (struct nodo_persona));
              
              nuovo -> inf = temp_inf;
              
              nuovo -> next = NULL;
              
              
              if (testa_p == NULL) {
                          testa_p = nuovo;}
                         
                 
                 else {
                      
                      temp = testa_p;
                      
                      while (temp != NULL){
                            prec = temp;
                            temp = temp -> next;
                            
                            }
                            
                      nuovo -> next = temp;
                      prec -> next = nuovo;

                      }
              
}



void visualizza_persona (){
       
       int tab;
       struct persona temp;              //Stuttura dati temporanea
       
       struct nodo_persona *p;
       
       p = testa_p;            
         
       printf ("Lista invitati\n______________________________________________________________________________\n");
                                
       printf ("ID\tNome\t\tCognome\t\t\tEta'\tSesso\tTipo\n");
       
       
       
       if (p == NULL) {
                 messaggio_errore ("\t\t\t  Nessun elemento nella lista");
                }
                
       else {
            
               while(p != NULL) {
                          temp = p -> inf;
                          
                          printf ("\n%d)\t%s",temp.codice_p,temp.nome);
                                 
                                 tab = strlen(temp.nome);
                                          
                                              if (tab > 7)                   
                                                  printf ("\t");
                                                      else                  
                                                            printf ("\t\t");
                                                            
                                                                   if (tab == 12)                   
                                                                      printf ("\t\t\t");
                                       
                          
                                       printf  ("%s\t",temp.cognome);                              
                                               
                                               tab = strlen(temp.cognome);
                                          
                                              if (tab > 7)                   
                                                  printf ("\t");
                                                      else                  
                                                            printf ("\t\t");
                                                            
                                                                   if (tab == 12)                   
                                                                      printf ("\t\t\t");
                                                       
                                                       printf ("%d",temp.eta);
                                            
                             
                                 if (temp.sesso == 0)
                                                printf ("\tM");
                                                else
                                                    printf ("\tF");
                                                    
                                 if (temp.tipo == 0)
                                                printf ("\tAmico");
                                                else
                                                    printf ("\tParente");
                                 
                          
              p = p ->next ;
           }
     } 
      getch ();             
}



int visualizza_persona_se (){
       
       int tab;
       struct persona temp;              //Stuttura dati temporanea
       
       struct nodo_persona *p;
       
       p = testa_p;            
         
       printf ("Lista invitati rapida\n______________________________________________________________________________\n");
                                
       printf ("ID\tNome\t\tCognome\t\tID\tNome\t\tCognome\t\t\n");
       
       if (p == NULL) {
                messaggio_errore ("\t\t\t  Nessun elemento nella lista");
                 
                 return 0;
                }
                
       else {
            
               while(p != NULL) {
                          temp = p -> inf;
                          
                          printf ("%d)\t%s",temp.codice_p,temp.nome);
                                 
                                 tab = strlen(temp.nome);
                                          
                                              if (tab > 7)                   
                                                  printf ("\t");
                                                      else                  
                                                            printf ("\t\t");
                                                            
                                                                   if (tab == 12)                   
                                                                      printf ("\t\t\t");
                                       
                          
                                       printf  ("%s\t",temp.cognome);                              
                                               
                                               tab = strlen(temp.cognome);
                                          
                                              if (tab < 8)                   
                                                  printf ("\t");
                                                                                                                 
                                                                   if (tab == 12)                   
                                                                      printf ("\t\t");
                                                                 
              p = p ->next ;
           }
     } 
     
     printf ("\n\n\nPeremere un tasto per continuare...\n");
      getch ();
      return 1;             
}


void inserisci_regalo (){

            struct regalo temp_inf;
            struct nodo_regalo *nuovo, *prec, *temp;
            
         
       printf ("\n\n-----------------------------------------");
       cont_regalo = cont_regalo + 1;
       temp_inf.codice_r = cont_regalo;       
       printf ("\nRegalo codice: %d\n\n",temp_inf.codice_r);
       printf ("Tipo: \t\t"); scanf ("%s",&temp_inf.tipo);
       printf ("Prezzo: \t"); scanf ("%f",&temp_inf.prezzo);
       
              do{
         printf ("\nSesso: \t\tPremi 0: non gradito\n\t\tPremi 1: gradito\n\t\t  Scelta: "); scanf ("%d",&temp_inf.info);
                if (temp_inf.info != 0 && temp_inf.info != 1){
                                    printf ("\n\n\tERRORE: %d NON E' UN VALORE VALIDO !!\n",temp_inf.info);
                                    }
                }while (temp_inf.info != 0 && temp_inf.info != 1);
                 
         
         nuovo = (struct nodo_regalo *) malloc (sizeof (struct nodo_regalo));
              
              nuovo -> inf = temp_inf;
              
              nuovo -> next = NULL;
              
              if (testa_r == NULL) {
                          testa_r = nuovo;
                          }
                         
                 
                 else {
                      
                      temp = testa_r;
                      
                      while (temp != NULL){
                            prec = temp;
                            temp = temp -> next;
                            
                            }
                            
                      nuovo -> next = temp;
                      prec -> next = nuovo;
                      
                  }
              
}



float Calc_Val_Regali (){                                                                                                     
                
       struct regalo temp_inf;              //Stuttura dati temporanea
       
       float tot_val_regali = 0;
       struct nodo_regalo *p;
       
       p = testa_r;
         
                if (p == NULL) {
                      messaggio_errore ("\t\t\t  Nessun elemento nella lista");
                           return 0;
                           }
                
                else {
                     
                     while(p != NULL) {
                             
                          temp_inf = p -> inf;
                          
                          tot_val_regali = tot_val_regali + temp_inf.prezzo;
                          p = p ->next;
                      }
                     
                }
                          
         return (tot_val_regali);
}


struct regalo Calc_Max_Regali (){                                                                                                     
                
                struct regalo temp_inf;
                struct regalo max;
                
                max.prezzo = 0;                       // Inizializzo Var max.prezzo
                
                struct nodo_regalo *p;
                
                p = testa_r;             

                
                if (p == NULL) {
                           messaggio_errore ("\t\t\t  Nessun elemento nella lista");
                           }
                
                else {
                     
                     while(p != NULL) {
                          temp_inf = p -> inf;
                          
                          
                          if (max.prezzo < temp_inf.prezzo){
                             
                             max = temp_inf;
                          
                          }
                          p = p->next;
                      }
                }
                
                return max;
}


void Ordina_Regali (){                                                                                                     
                
                int y;
                          
          for (y = 0; y < 201 ; y++){
              regali_dec [y] = 0;
              regali_cre [y] = 0;
              }
                
                struct regalo temp_inf;
                int cont = 0;
                float j,i;
                
                struct nodo_regalo *p;
                
                p = testa_r;             

                
                if (p == NULL) {
                           messaggio_errore ("\t\t\t  Nessun elemento nella lista");
                           }
                
                        else {
                             
                             while(p != NULL) {
                                  temp_inf = p -> inf;
                                  
                                  regali_dec [cont] = temp_inf.prezzo;
                                  regali_cre [cont] = temp_inf.prezzo;

                                  cont = cont + 1;
                                  
                                  p = p->next;
                              }
                        }
                        
                   
                   // ORDINO REGALI  
                   
                   
                      
          
          int a,b,c = 0;

                   
                   for (a = (200-1); a > 0; a--){
                       for (b = 1;b <= a; b++){
                           
                              if (regali_dec [b-1] > regali_dec [b]){ 
                                             
                                             c = regali_dec [b-1];
                                             regali_dec [b-1] = regali_dec [b];
                                             regali_dec [b] = c;
                                             
                                             }
                                             
                               if (regali_cre [b-1] < regali_cre [b]){ 
                                             
                                             c = regali_cre [b-1];
                                             regali_cre [b-1] = regali_cre [b];
                                             regali_cre [b] = c;
                                             
                                             }         
                                             
                           }
                      }          
                
                
}

void stampa_regali_dec (){
     
     Ordina_Regali ();
     
     printf ("\nRegali in ordine decrescente: \n");
     int i = 0;
     
     for (i=0; i < 200; i++){
         
         if (regali_dec [i] > 0)
             printf ("\nValore regalo: %f", regali_dec [i]);
         
         }
         
         
      printf ("\n");            
      getch ();           

}


int n_regali_minimo (float a){  
    
    
    Ordina_Regali ();

    float tot = Calc_Val_Regali ();
    
    float temp1 = 0;
    int n_regali = 0;
    int i = 200;
     
     if (a<=tot){
     
             for (i=200; i >= 0; i--){
                 
                 if (regali_cre [i] != 0){
        
                             temp1 = temp1 + regali_cre [i];    

                                   n_regali = n_regali + 1; 

                             if (temp1 >= a){
                                         i = 0;     
                                      }
                         }            
                 }
                 return n_regali;
         }    
         
              else
              return -1;

         
}
         
struct persona trova_persona (int id) {
       
       struct persona temp_inf;
       struct persona dato;
                
       struct nodo_persona *p;
                
                p = testa_p;             

                
                if (p == NULL) {
                           messaggio_errore ("\t\t\t  Nessun elemento nella lista");
                           }
                           
                else {
                     
                     while(p != NULL) {
                          temp_inf = p -> inf;
                          
                          
                          if (temp_inf.codice_p == id){
                             
                             dato = temp_inf;
                          
                          }
                          p = p->next;
                          }
                          
                          
                          }
                return dato;
}



void inserisci_simpatia (int id_persona_1,int id_persona_2, float valore) {
     
     struct simpatia temp_inf;
     
     struct persona temp_persona_1;
     struct persona temp_persona_2;

     struct nodo_simpatia *nuovo, *prec, *temp;
     
     
            if (testa_p == NULL){
                       printf ("ERRORE, NESSUNA PERSONA");
                       }
                       
                        else {
                              
                              temp_persona_1 = trova_persona (id_persona_1);          
                              temp_persona_2 = trova_persona (id_persona_2);
                              
                              
                              temp_inf.inf_p1 = temp_persona_1;
                              temp_inf.inf_p2 = temp_persona_2;
                              
                                        
                             if ((valore < -1) || (valore > 1)){
                                                        printf ("\n\n\n\tERRORE: %f NON E' UN VALORE VALIDO !!\n",valore);
                                                        }
                                                        
                                else {
                                
                                                 
                                            
                                            temp_inf.valore = valore; 
                                                    
                                            
                                    
                                              
                                              nuovo = (struct nodo_simpatia *) malloc (sizeof (struct nodo_simpatia));
                                              
                                              nuovo -> inf = temp_inf;
                                              
                                              nuovo -> next = NULL;
                                              
                                              
                                              if (testa_s == NULL) {
                                                          testa_s = nuovo;}
                                                 
                                                 else {
                                                      
                                                      temp = testa_s;
                                                      
                                                      while (temp != NULL){
                                                            prec = temp;
                                                            temp = temp -> next;
                                                            
                                                            }
                                                            
                                                      nuovo -> next = temp;
                                                      prec -> next = nuovo;
                                                      
                                                      }
                                          
                                                       printf ("\nFATTO");
                                          
                                          }
                         
                         }
                         
                 
    getch ();
         
}



float verifica_simpatia (int id_persona_1, int id_persona_2) {

     float valore_simpatia = 0;                //valore di ritorno

     struct simpatia temp;
            
     struct nodo_simpatia *p;
                
                p = testa_s;
                
                if (p == NULL){
                   printf ("\n\nERRORE NESSUNA RELAZIONE DI SIMPATIA\n\n");
                   return 0;
                   }
                   
                else {    
                                         
                     while(p != NULL) {
                             
                             temp = p -> inf;
                             
                             if ((temp.inf_p1.codice_p == id_persona_1) && (temp.inf_p2.codice_p == id_persona_2)) {
                                                           valore_simpatia = temp.valore;
                                                           }

                              
                              p = p -> next; 
                              
                              }
                }
     
     return valore_simpatia;
     
     
}



int verifica_conoscenza (int id_persona_1) {

     int persone_conosciute = 0;                
     int tot_persone_non_conosciute = 0;            //valore di ritorno
     
     struct simpatia temp;
            
     struct nodo_simpatia *p;
                
                p = testa_s;
                
                if (p == NULL)
                   printf ("NESSUNA RELAZIONE DI SIMPATIA");
                   
                else {    
                                         
                     while(p != NULL) {
                             
                             temp = p -> inf;
                             
                             if (temp.inf_p1.codice_p == id_persona_1) {
                                                                       
                                                           if (temp.valore != 0){        // se è 0 non si conoscono
                                                                           
                                                                      persone_conosciute = persone_conosciute + 1;  
                                                                      }    
                                                                                
                                                           
                                                           }
                              
                              p = p -> next; 
                              
                              }
                }
     
     tot_persone_non_conosciute = cont_persona - persone_conosciute - 1;             // - se stesso
     
     return tot_persone_non_conosciute;
}
                                              
                                              
int verifica_antipatia_sesso (int id_persona_1, int sesso) {                                             

     int tot_persone_antipatiche = 0;                          //valore di ritorno
     
     struct simpatia temp;
            
     struct nodo_simpatia *p;
     
     
                
                p = testa_s;
                
                if (p == NULL)
                   printf ("NESSUNA RELAZIONE DI SIMPATIA");
                   
                else {    
                                         
                     while(p != NULL) {
                             
                             temp = p -> inf;
                             
                             if (temp.inf_p1.codice_p == id_persona_1) {
                                                                       
                                                           if (temp.valore < 0 && temp.inf_p2.sesso == sesso){        // sesso femminile
                                                                           
                                                                      tot_persone_antipatiche = tot_persone_antipatiche + 1;  
                                                                      }    
                                                                                
                                                           
                                                           }
                              
                              p = p -> next; 
                              
                              }
                }
     
     
     return tot_persone_antipatiche;
}       
                     
                     
int verifica_piu_simpatico (int id_persona_1){
    
    int piu_simpatico = -1;                                // Inizializzo a -1
        
    struct simpatia attuale;
    
    struct simpatia temp;
    
    struct nodo_simpatia *p;
    
    attuale.valore = 0;

           p = testa_s;
                
                if (p == NULL)
                   printf ("NESSUNA RELAZIONE DI SIMPATIA");                         
                   
                else {    
                                         
                     while(p != NULL) {
                             
                             temp = p -> inf;
                                  
                                  if (temp.valore > attuale.valore && temp.valore > 0) {
                                  
                                     attuale = temp;
                                     
                                     }
                             p = p -> next;
                     }

              }
              
              if (attuale.valore == 0){
              
                 return -1;
                 }
                 
                 else{
                      piu_simpatico = attuale.inf_p2.codice_p;
                      }

return piu_simpatico;                
}                                     
           
     

int simpatia_doppia_numero (int id_persona_1, int id_persona_2) {                                             

     int tot_persone_simpatiche = 0;            //valore di ritorno
     
     struct simpatia temp_a;
     struct simpatia temp_b;
            
     struct nodo_simpatia *p1;
     struct nodo_simpatia *p2;
                
                p1 = testa_s;
                p2 = testa_s;
                
                if (p1 == NULL)
                   printf ("NESSUNA RELAZIONE DI SIMPATIA");                        
                   
         else {    
                   
                     while(p2 != NULL) {                    // 1 while
                              
                           
                           temp_a = p2 -> inf;  
                             
                                        while(p1 != NULL) {       // 2 while
                                         
                                                 temp_b = p1 -> inf;
                                                 
                                                     if ((temp_a.inf_p1.codice_p == id_persona_1) && (temp_b.inf_p1.codice_p == id_persona_2)) {
                                                                                               
                                                          if ((temp_a.valore > 0) && (temp_b.valore > 0))  {        
                                                                                                   
                                                              tot_persone_simpatiche = tot_persone_simpatiche + 1;  
                                                              }
                                                     }
                    
                                                  
                                                  p1 = p1 -> next; 
                                           }                                // Fine 2 while
                            p2 = p2 -> next; 
                        }                                                   // Fine 3 while 
                        
        }
return tot_persone_simpatiche;

}     


char simpatia_doppia_nomi (int id_persona_1, int id_persona_2) {                                             

     char nomi [max_persona*25];            //valore di ritorno
     
     struct simpatia temp_a;
     struct simpatia temp_b;
            
     struct nodo_simpatia *p1;
     struct nodo_simpatia *p2;
                
                p1 = testa_s;
                p2 = testa_s;
                
                if (p1 == NULL)
                   printf ("NESSUNA RELAZIONE DI SIMPATIA");
                   
         else {    
                   
                     while(p2 != NULL) {                    // 1 while
                              
                           
                           temp_a = p2 -> inf;  
                             
                                        while(p1 != NULL) {       // 2 while
                                         
                                                 temp_b = p1 -> inf;
                                                 
                                                 
                                                     if ((temp_a.inf_p1.codice_p == id_persona_1) && (temp_b.inf_p1.codice_p == id_persona_2)) {
                                                                                               
                                                          if ((temp_a.valore > 0) && (temp_b.valore > 0))  {        
                                                              
                                                              strcpy(nomi, temp_a.inf_p2.nome);
                                                              strcat(nomi, " " );
                                                              
                                                              strcat(nomi, temp_a.inf_p2.cognome);
                                                              strcat(nomi, ", " );
                                  
                                                             
                                                              }
                                                     }
                    
                                                  
                                                  p1 = p1 -> next; 
                                           }                                // Fine 2 while
                            p2 = p2 -> next; 
                        }                                                   // Fine 3 while 
                        
        }
        
return nomi [max_persona*25];

}     




int verifica_antipatia_doppia (int id_persona_1, int id_persona_2) {

                 
     int tot_persone_antipatiche = 0;            //valore di ritorno
     int a = 0;
     float val_a = 0;
     float val_b = 0;
     
     for (a = 1; a <= cont_persona; a++){
         
         val_a = verifica_simpatia (id_persona_1, a);
         val_b = verifica_simpatia (id_persona_2, a);
         
         if ((val_a < 0) && (val_b < 0)){
                    tot_persone_antipatiche = tot_persone_antipatiche + 1;
                    }
                    
                    else {
                         
                                     if ((val_a < 0) || (val_b < 0)){
                                tot_persone_antipatiche = tot_persone_antipatiche + 1;
                                }
                      }
}


return tot_persone_antipatiche;

} 



int tutti_conoscenti (int id_persona_1, int id_persona_2, int id_persona_3){          
    
     int val = 0;
     
     if (verifica_simpatia (id_persona_1,id_persona_2) !=0) {
                           
         if (verifica_simpatia (id_persona_1,id_persona_3) !=0) {
                                                 
             if (verifica_simpatia (id_persona_2,id_persona_1) !=0) {
                                                                       
                 if (verifica_simpatia (id_persona_2,id_persona_3) !=0) {
                                                                                             
                     if (verifica_simpatia (id_persona_3,id_persona_1) !=0) {
                                                                                                                
                         if (verifica_simpatia (id_persona_3,id_persona_2) !=0) {
                                                                                                                                   
                             val = 1;
                                                                                                                                   

                                                                                                               
                             }
                         }
                     }
                 }
             }
         }
          return val;
          
          
}     


int triangolo_simpatico (int id_persona_1, int id_persona_2, int id_persona_3){          
    
     int val = 0;

     if (verifica_simpatia (id_persona_1,id_persona_2) > 0) {
                           
         if (verifica_simpatia (id_persona_1,id_persona_3) > 0) {
                                                 
             if (verifica_simpatia (id_persona_2,id_persona_1) > 0) {
                                                                       
                 if (verifica_simpatia (id_persona_2,id_persona_3) > 0) {
                                                                                             
                     if (verifica_simpatia (id_persona_3,id_persona_1) > 0) {
                                                                                                                
                         if (verifica_simpatia (id_persona_3,id_persona_2) > 0) {
                                                                                                                                   
                             val = 1;
                                                                                                                                   

                                                                                                               
                             }
                         }
                     }
                 }
             }
         }
          return val;
          
          
} 


int conta_triangoli_simpatici (){
    
    int possibili_triangoli_simpatici = 0;
    int val = 0;
    int a,b,c;
    
        for (a = 1; a <= cont_persona; a++){
            for (b = 1; b <= cont_persona; b++){
                for (c = 1; c <= cont_persona; c++){
                         
                         
                         val = 0;
                         val = triangolo_simpatico (a,b,c);
                         
                             
                                 if (val == 1){
                                    
                                    possibili_triangoli_simpatici = possibili_triangoli_simpatici + 1;
                                    }
            
                    }           
                }
            }
            
            
            possibili_triangoli_simpatici = possibili_triangoli_simpatici / 6;
return possibili_triangoli_simpatici;
 
}


void inserisci_tavolo () {
     
     struct tavolo temp_inf;
     
     int id_persona_1;
     int id_persona_2;
     int id_persona_3;
     int id_persona_4;
     int id_persona_5;     
     
     struct persona temp_persona_1;
     struct persona temp_persona_2;
     struct persona temp_persona_3;
     struct persona temp_persona_4;
     struct persona temp_persona_5;
     
     
     
     struct nodo_tavolo *nuovo, *prec, *temp;
     
     
            if (testa_p == NULL){
                       printf ("ERRORE, NESSUNA PERSONA");
                       getch ();
                       }
                       
                       else {
                        
                            visualizza_persona_se ();
                     
                            
                            printf ("\n\n-----------------------------------------");
                            
                            cont_tavolo = cont_tavolo + 1;
                            temp_inf.codice_t = cont_tavolo;
                             
                            printf ("\nTavolo codice: %d\n\n",temp_inf.codice_t);
                            printf ("\nInserisci l'id della prima persona: "); scanf ("%d",&id_persona_1);
                            printf ("\nInserisci l'id della seconda persona: "); scanf ("%d",&id_persona_2);
                            printf ("\nInserisci l'id della terza persona: "); scanf ("%d",&id_persona_3);
                            printf ("\nInserisci l'id della quarta persona: "); scanf ("%d",&id_persona_4);
                            printf ("\nInserisci l'id della quinta persona: "); scanf ("%d",&id_persona_5);
                            
                            
                            if (id_persona_1 != id_persona_2 != id_persona_3 != id_persona_4 != id_persona_5){
                                             
                                    temp_persona_1 = trova_persona (id_persona_1);          
                                    temp_persona_2 = trova_persona (id_persona_2);
                                    temp_persona_3 = trova_persona (id_persona_3);
                                    temp_persona_4 = trova_persona (id_persona_4);
                                    temp_persona_5 = trova_persona (id_persona_5);
                                    
                                    temp_inf.inf_p1 = temp_persona_1;
                                    temp_inf.inf_p2 = temp_persona_2;
                                    temp_inf.inf_p3 = temp_persona_3;
                                    temp_inf.inf_p4 = temp_persona_4;
                                    temp_inf.inf_p5 = temp_persona_5;
                                                
                                                
                            
                                      nuovo = (struct nodo_tavolo *) malloc (sizeof (struct nodo_tavolo));
                                      
                                      nuovo -> inf = temp_inf;
                                      
                                      nuovo -> next = NULL;
                                      
                                      
                                                      if (testa_t == NULL) {
                                                                  testa_t = nuovo;
                                                                  printf ("\nFATTO");
                                                                  }
                                                         
                                                             else {
                                                                  
                                                                  temp = testa_t;
                                                                  
                                                                  while (temp != NULL){
                                                                        prec = temp;
                                                                        temp = temp -> next;
                                                                        
                                                                        }
                                                                    
                                                              nuovo -> next = temp;
                                                              prec -> next = nuovo;
                                                              
                                                              
                                                              
                                                              printf ("\nFATTO");
                                                              }
                                              
                                              }
                                              
                                                  else {
                                                       printf ("\nHai inserito almeno una volta la stessa paersona");
                                                      }
                                              
                                              
                                            
                 }   
                 
    getch ();
         
}


void visualizza_tavolo (){
       
       int tab;
       struct tavolo temp;              //Stuttura dati temporanea
       
       struct nodo_tavolo *p;
       
       p = testa_t;            
         
       printf ("Lista tavoli\n______________________________________________________________________________\n");
                                
              
       
       
       if (p == NULL) {
                 printf ("\n\n\n\n\n\n\n\t\t\a\a\a\a   ATTENZIONE: Nessun elemento nella lista");
                }
                
       else {
            
               while(p != NULL) {
                          temp = p -> inf;
                          
                          printf ("\nCodice Tavolo:\t %d)",temp.codice_t);
                          printf ("\n\t\t\t %s %s",temp.inf_p1.nome,temp.inf_p1.cognome);
                          printf ("\n\t\t\t %s %s",temp.inf_p2.nome,temp.inf_p2.cognome);
                          printf ("\n\t\t\t %s %s",temp.inf_p3.nome,temp.inf_p3.cognome);
                          printf ("\n\t\t\t %s %s",temp.inf_p4.nome,temp.inf_p5.cognome);
                          printf ("\n\t\t\t %s %s",temp.inf_p5.nome,temp.inf_p5.cognome);
                          printf ("\n");
                                 
                                 
                          
              p = p ->next ;
           }
     } 
     
     printf ("\n\nPremi un tasto per continuare...\n\n");
      getch ();             
}


struct tavolo trova_tavolo (int id) {
       
       struct tavolo temp_inf;
       struct tavolo dato;
                
       struct nodo_tavolo *p;
                
                p = testa_t;             

                
                if (p == NULL) {
                           printf ("ERRORE\n");
                           }
                           
                else {
                     
                     while(p != NULL) {
                          temp_inf = p -> inf;
                          
                          
                          if (temp_inf.codice_t == id){
                             
                             dato = temp_inf;
                          
                          }
                          p = p->next;
                          }
                          
                          
                          }
                return dato;
}


int tipo_tavolo(int id_tavolo) {
    
    struct tavolo temp;
    
    int persone [4];
 
    int a,b = 0;
      
    float valore;
     
    int simpatici = 0;
    int non_conoscenti = 0;
    int antipatici = 0;
                   
        
           temp = trova_tavolo (id_tavolo);
           
           
           
           persone [0] = temp.inf_p1.codice_p;
           persone [1] = temp.inf_p2.codice_p;
           persone [2] = temp.inf_p3.codice_p;
           persone [3] = temp.inf_p4.codice_p;
           persone [4] = temp.inf_p5.codice_p;
           
           
                   for (a = 0; a < 5; a++){
                       for (b = 0; b < 5; b++){
                           
                                   
                                           if (persone [a] != persone [b]){
                                                       
                                               valore = verifica_simpatia (persone [a],persone [b]);
                                               
                                               
                                               
                                               if (valore < 0){
                                                  antipatici = antipatici + 1;
                                                  }
                                                                 
                                                  if (valore == 0){
                                                     non_conoscenti = non_conoscenti + 1;
                                                     }
                                                                    
                                                     if (valore > 0){
                                                        simpatici = simpatici + 1;
                                                        }
                                             }                                              
                       }
                 }
                 
           
                                         if ((non_conoscenti == 25) || (antipatici == 0))                     //Assultamente pacifico
                                                        return 2;
                                         
                                             else
                                                        
                                                 if ((simpatici + non_conoscenti) > (antipatici))           // Pacifico
                                                                return 1;
                                                        
                                                     else
                                                        
                                                           return 0;                                            // Tavolo Litigioso  
               
}



int verifica_sostituzione_tavolo (int id_tavolo, int id_persona_1) {
    
    struct tavolo temp;
    
    int persone [4];
 
    int a,b = 0;
      
    float valore = 0;
    float valore_p = 0;
     
    int simpatici = 0;
    int non_conoscenti = 0;
    int antipatici = 0;
    
    int simpatia_p = 0;               
        
           temp = trova_tavolo (id_tavolo);
           
           
           
           persone [0] = temp.inf_p1.codice_p;
           persone [1] = temp.inf_p2.codice_p;
           persone [2] = temp.inf_p3.codice_p;
           persone [3] = temp.inf_p4.codice_p;
           persone [4] = temp.inf_p5.codice_p;
           
           
                   for (a = 0; a < 5; a++){
                       for (b = 0; b < 5; b++){
                           
                                   
                                           if (persone [a] != persone [b]){
                                                       
                                               valore = verifica_simpatia (persone [a],persone [b]);
                                               
                                               
                                               
                                               if (valore < 0){
                                                  antipatici = antipatici + 1;
                                                  }
                                                                 
                                                  if (valore == 0){
                                                     non_conoscenti = non_conoscenti + 1;
                                                     }
                                                                    
                                                     if (valore > 0){
                                                        simpatici = simpatici + 1;
                                                        }
                                             }
                                             
                                             
                                                 if (persone [a] != id_persona_1){
                                                             
                                                    valore_p = verifica_simpatia (persone [a],id_persona_1);
                                                    
                                                    if (valore_p >= 0){
                                                                        
                                                                        simpatia_p = simpatia_p + 1;
                                                                        }
                                                                        
                                                    valore_p = verifica_simpatia (id_persona_1,persone [a]);
                                                             
                                                             if (valore_p >= 0){
                                                                        
                                                                        simpatia_p = simpatia_p + 1;
                                                                        }
                                                           
                                             }
                                                                                                                                      
                       }
                 }

                 
                 if ((simpatia_p == 50) && (antipatici > 0)){
                    return 1;
                    }
                    
                    else {
                         return 0;
                         }
                                                    // Tavolo Litigioso  
               
}



int Amici_Casuali (int id_tavolo){

    struct tavolo temp;
    
    int persone [4];
 
    int a,b,c,d = 0;
    
    float valore = 0;  
    
    float valore_a = 0;
    float valore_b = 0;
    
    int ritorno = 0; 

           temp = trova_tavolo (id_tavolo);
           
           
           
           persone [0] = temp.inf_p1.codice_p;
           persone [1] = temp.inf_p2.codice_p;
           persone [2] = temp.inf_p3.codice_p;
           persone [3] = temp.inf_p4.codice_p;
           persone [4] = temp.inf_p5.codice_p;
           
           
                   for (a = 0; a < 5; a++){
                       for (b = 0; b < 5; b++){
                           
                           if (persone [a] != persone [b]){
                           
                                  valore = verifica_simpatia (persone [a],persone [b]);
                                               
                                                      if (valore == 0){
                                                                 
                                                                 for (c = 0; c < 5; c++){
                
                                                                 
                                                                         if ((c != a)&&(c != b)){
                                                                            valore_a = verifica_simpatia (persone [a],persone [c]);
                                                                            valore_b = verifica_simpatia (persone [b],persone [c]);
                                                                            }
                                                                            
                                                                            
                                                                         printf ("\nA: %f, B: %f, (%d, %d, %d)",valore_a,valore_b,a,b,c);
                                                                         
                                                                         if ((valore_a != 0) && (valore_b != 0)){
                                                                            
                                                                            return 1;
                                                                            }
                                                                  }   
                
                                                                        
                                                       }
                                 }                      
                              }
                           }
             
                               
                        return -1;
                
}            

                            
                               
