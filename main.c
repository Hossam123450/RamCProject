#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct RAM{
char etat;
int debut;
int taille;
}RAM;


typedef struct nodeR{
RAM r;
struct nodeR* next;
struct nodeR* prev;
}nodeR;


typedef struct nodeP{
char signe;
int val;
struct nodeP* next;
struct nodeP* prev;
}nodeP;


nodeP* head=NULL;
nodeP* headF=NULL;
nodeR* headR=NULL;
nodeR* opp=NULL;

void ajoutFin(char s,int v){
nodeP* n=(nodeP*)malloc(sizeof(nodeP));
n->next=n->prev=NULL;
n->signe=s;
n->val=v;
if(head==NULL){
    head=n;
    return;
}
nodeP* temp=head;
while(temp->next!=NULL)
    temp=temp->next;
n->prev=temp;
temp->next=n;
}
void ajoutFinL(char s,int v){
nodeP* n=(nodeP*)malloc(sizeof(nodeP));
n->next=n->prev=NULL;
n->signe=s;
n->val=v;
if(headF==NULL){
    headF=n;
    return;
}
nodeP* temp=headF;
while(temp->next!=NULL)
    temp=temp->next;
n->prev=temp;
temp->next=n;
}
void ajoutFinR(char e,int d,int t){
nodeR* n=(nodeR*)malloc(sizeof(nodeR));
n->next=n->prev=NULL;
n->r.etat=e;
n->r.debut=d;
n->r.taille=t;
if(headR==NULL){
    headR=n;
    return;
}
nodeR* temp=headR;
while(temp->next!=NULL)
    temp=temp->next;
n->prev=temp;
temp->next=n;
}


nodeR* ajoutFinRC(nodeR* X,char e,int d,int t){
nodeR* n=(nodeR*)malloc(sizeof(nodeR));
n->next=n->prev=NULL;
n->r.etat=e;
n->r.debut=d;
n->r.taille=t;
nodeR* temp=X;
if(X==NULL){
    n->next=n->prev=n;
    X=n;}

else{
while(temp->next!=X)
    temp=temp->next;
n->next=X;
n->prev=temp;
temp->next=n;
X->prev=n;}
return X;
}




void ajoutFinRX(char e,int d,int t){
nodeR* n=(nodeR*)malloc(sizeof(nodeR));
n->next=n->prev=NULL;
n->r.etat=e;
n->r.debut=d;
n->r.taille=t;
printf("\n\n%c%d%d\n\n",e,d,t);
if(headR==NULL){
    headR=n;
    return;
}
nodeR* tempY=headR;
while(tempY->next!=NULL)
    tempY=tempY->next;
n->prev=tempY;
tempY->next=n;
}

void suppDebutR(){
nodeR* temp=headR;
if(headR!=NULL){
    headR=temp->next;
   if(temp->next!=NULL)
    temp->next->prev=NULL;

   free(temp);
}
}

nodeR* suppDebutRC(nodeR* X){//4alat tfaraj fpwh
printf("\nhoooos\n");
printf("\nopp%d\n",X->r.taille);
nodeR* temp=X->next;

if(X!=NULL){

if(temp==X){
        X=NULL;
        free(temp);}
else{
    X=temp;

    temp->next->prev=X;

   free(temp);}
}
return X;
}


void suppFinR(){
nodeR* temp;
if(headR!=NULL){
    temp=headR;
    while(temp->next!=NULL)
        temp=temp->next;
    if(temp->prev!=NULL)
        temp->prev->next=NULL;
    else
        headR=NULL;
    free(temp);
}


}

nodeR* suppFinRC(nodeR* X){
nodeR* temp;
if(X!=NULL){
        temp=X->next;
     if(temp==X){
        X=NULL;
        free(temp);
     }else{
    while(temp->next!=X)
        temp=temp->next;

        temp->prev->next=X;
        X->prev=temp->prev;

    free(temp);}}
    return X;
}





void ajoutDebutR(char e,int d,int t){
nodeR* n=(nodeR*)malloc(sizeof(nodeR));
n->next=n->prev=NULL;
n->r.etat=e;
n->r.debut=d;
n->r.taille=t;
n->next=headR;
if(headR!=NULL)
   head->prev=n;
headR=n;

}

nodeR* ajoutDebutRC(nodeR* X,char e,int d,int t){
nodeR* n=(nodeR*)malloc(sizeof(nodeR));
n->next=n->prev=NULL;
n->r.etat=e;
n->r.debut=d;
n->r.taille=t;
if(X==NULL){
   n->next=n->prev=n;
   X=n;
   }
else{
    n->next=X;
    n->prev=X->prev;
    opp->prev=n;
    n->prev->next=n;
    X=n;//momkin hna ikon mochkil
}
return X;
}




void afficher(){
nodeP* temp=head;
if(head==NULL){
    printf("liste vide\n");
    return;

}
while(temp!=NULL){
    printf("(%c%d)->",temp->signe,temp->val);
    temp=temp->next;
}
}


void afficherL(){
nodeP* temp=headF;
if(headF==NULL){
    printf("liste vide\n");
    return;

}
while(temp!=NULL){
    printf("(%c%d)->",temp->signe,temp->val);
    temp=temp->next;
}
}


void afficherR(){
nodeR* temp=headR;
if(headR==NULL){
    printf("liste vide\n");
    return;

}
while(temp!=NULL){
    printf("(%c de %d et taille %d)->",temp->r.etat,temp->r.debut,temp->r.taille);
    temp=temp->next;
}
}


void ajoutmillR(nodeR *ele,char e,int d,int t  ){//mochkil hna
nodeR* n=(nodeR*)malloc(sizeof(nodeR));
n->next=n->prev=NULL;
n->r.etat=e;
n->r.debut=d;
n->r.taille=t;
nodeR* temp=headR;
while(temp!=ele)
    temp=temp->next;
n->next=temp->next;
n->prev=temp;
if(temp->next!=NULL)
    n->next->prev=n;
temp->next=n;




}


nodeR* ajoutmillRC(nodeR* X,nodeR *ele,char e,int d,int t  ){//mochkil hna
nodeR* n=(nodeR*)malloc(sizeof(nodeR));
n->next=n->prev=NULL;
n->r.etat=e;
n->r.debut=d;
n->r.taille=t;
nodeR* temp=X;
printf("\nX%d",X->r.taille);
while(temp!=ele)
    temp=temp->next;
n->next=temp->next;
n->prev=temp;
n->next->prev=n;
temp->next=n;



return X;
}


void ajoutmillP(nodeP *ele,char s,int t  ){//mochkil hna
nodeP* n=(nodeP*)malloc(sizeof(nodeP));
n->next=n->prev=NULL;
n->signe=s;
n->val=t;
nodeP* temp=head;
while(temp!=ele)
    temp=temp->next;
n->next=temp->next;
n->prev=temp;
if(temp->next!=NULL)
    n->next->prev=n;
temp->next=n;




}


void suppMillR(nodeR *ele){
nodeR*temp=headR;
while(temp!=ele)
temp=temp->next;
   if(temp->prev!=NULL)
    temp->prev->next=temp->next;
    else
        headR=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    free(temp);


}


nodeR* suppMillRC(nodeR* X,nodeR *ele){
nodeR*temp=X;
while(temp!=ele)
temp=temp->next;

    temp->prev->next=temp->next;

    temp->next->prev=temp->prev;
    temp=NULL;
    free(temp);

return X;
}

void suppMillF(char s,int t){
nodeP*temp=headF;
while(temp->signe!=s &&temp->val!=t)
temp=temp->next;
   if(temp->prev!=NULL)
    temp->prev->next=temp->next;
    else
        headF=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    free(temp);


}


void suppMillRX(nodeR *ele){//5asha tsuprimi mn lbadia
nodeR*temp=headR,*p;
while(temp!=ele)
temp=temp->next;
   if(temp->prev!=NULL)
    temp->prev->next=temp->next;
    else
        headR=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    p=temp;
    temp=temp->next;

    free(p);
    //printf("\n\n%c%d%d\n\n",temp->r.etat,temp->r.debut,temp->r.taille);
    //printf("\n\n%c%d%d\n\n",temp->next->r.etat,temp->next->r.debut,temp->next->r.taille);

//printf("\nha suppresion dial X\n"); afficherR();printf("\n\n");
}

nodeR* suppMillRXC(nodeR* X,nodeR *ele){//5asha tsuprimi mn lbadia
nodeR*temp=X,*p;printf("\nha X%d\n",X->r.taille);
if(X!=NULL){
 if(X->next!=X){
  while(temp!=ele)
  temp=temp->next;
  if(temp==X){
temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    X=X->next;
    temp=NULL;
    free(temp);
  }else{
   temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp=NULL;
    free(temp);}}
 else{
    X=X->next;
    temp=NULL;
    free(temp);
  }

    }
 // printf("\n\n%c%d%d\n\n",temp->r.etat,temp->r.debut,temp->r.taille);
   // printf("\n\n%c%d%d\n\n",temp->next->r.etat,temp->next->r.debut,temp->next->r.taille);
return X;


//printf("\nha suppresion dial X\n"); afficherR();printf("\n\n");
}


void triparselectionR()
{
    nodeR *temp=headR , *temp2 , *pmax ;
    RAM aide ;
    while(temp->next!=NULL)
    {
        temp2=temp->next ;
        pmax=temp ;
        while(temp2!=NULL)
        {
            if(temp2->r.etat > pmax->r.etat)
            {
                pmax=temp2 ;
            }
            temp2=temp2->next ;
        }
        aide=pmax->r ;
        pmax->r=temp->r ;
        temp->r =aide ;
        temp=temp->next;
    }
}



void compactageR()
{
    nodeR*temp=headR,*p;
    int S=0, d;

    while(temp->r.etat!='L')
        temp=temp->next;

    d=temp->r.debut;
    while(temp!=NULL){

        S+=temp->r.taille;
        p=temp;
        suppMillR(p);
        temp=temp->next;
    }
    ajoutFinR('L',d,S);





}
/* int S=0, S2=0,cpt5=0,d1,d2;

void compactageRX()
{
    nodeR*tempX=headR,*p,*tempX1=headR,*tempX2=headR;


    while(tempX->r.etat!='L')
        tempX=tempX->next;
    while(tempX1->r.etat!='O')
        tempX1=tempX1->next;
    d1=tempX->r.debut;
    d2=tempX1->r.debut;


    while(tempX!=NULL){//hna kain lmochkil lboucle makatssalich

            if(tempX->r.etat=='L'){
                    if(d1>=tempX->r.debut)
                       d1=tempX->r.debut;

            S+=tempX->r.taille;

           //hna fin danit kain lmochkil
        p=tempX;
        tempX=tempX->next;
        suppMillRX(p);}
        // printf("%d\t%d\n\n",d,S);}
        else{
            if(d2>=tempX->r.debut)
                       d2=tempX->r.debut;


         S2+=tempX->r.taille;
         p=tempX;
        tempX=tempX->next;
        suppMillRX(p);
         }

    }//printf("%d\t%d\n\n",d,S);
    //lmochkil kain fajouter fin xxxxxxxx
    ajoutFinRX('O',d2,S2);
    ajoutFinRX('L',d1,S);
//printf("\nha ajout dial X\n"); afficherR();printf("\n\n");


cpt5++;

}*/

int S1=0, S3=0,cpt6=0;

void compactageRXX()
{
    nodeR*tempX=headR,*p;


    while(tempX->r.etat!='L')
        tempX=tempX->next;



    while(tempX!=NULL){//hna kain lmochkil lboucle makatssalich

            if(tempX->r.etat=='L'){

            S1+=tempX->r.taille;

           //hna fin danit kain lmochkil
        p=tempX;
        tempX=tempX->next;
        suppMillRX(p);}
        // printf("%d\t%d\n\n",d,S);}
        else{
         S3+=tempX->r.taille;
         p=tempX;
        tempX=tempX->next;
        suppMillRX(p);
         }

    }//printf("%d\t%d\n\n",d,S);
    //lmochkil kain fajouter fin xxxxxxxx
    ajoutFinRX('O',0,S3);
    ajoutFinRX('L',S3,S1);
//printf("\nha ajout dial X\n"); afficherR();printf("\n\n");


cpt6++;

}




void compactageRX()
{
    nodeR*tempX=headR,*p,*tempX1=headR,*tempX2;
    int* T;int i=0,OC=0;
    int S=0, S2=0,cpt5=0,d1,d2,S3;

   // while(tempX->r.etat!='L')
       // tempX=tempX->next;
    while(tempX1->r.etat!='O'){
        tempX1=tempX1->next;

    }
   // d1=tempX->r.debut;
    d2=tempX1->r.debut;
    S3=tempX1->r.taille;

    while(tempX!=NULL){//hna kain lmochkil lboucle makatssalich

            if(tempX->r.etat=='L'){
                    if(d1>=tempX->r.debut)
                       d1=tempX->r.debut;

            S+=tempX->r.taille;

           //hna fin danit kain lmochkil
        p=tempX;
        tempX=tempX->next;
        suppMillRX(p);printf("\n\n"); afficherR();printf("\n\n");}
        // printf("%d\t%d\n\n",d,S);}
        else{
            if(d2<=tempX->r.debut){
                       d2=tempX->r.debut;
                       S3=tempX->r.taille;

            }
            OC++;
          tempX=tempX->next;
         }

    }
    T=(int*)malloc(OC*(sizeof(int)));
    tempX2=headR;
//    T1=(int*)malloc(OC*(sizeof(int)));
    while(tempX2!=NULL||i<OC){

              T[i]=tempX2->r.taille;
              printf("\n\n%d\n\n",T[i]);
             // T1[i]=tempX2->r.debut;
              p=tempX2;
        tempX2=tempX2->next;
        suppMillRX(p);
        i++;
         printf("\nxxxx\n");afficherR();printf("\n\n");



    }
   int S7=0;
    i=0;
    //tempX2=headR;
   // ajoutFinR('O',0,T[0]);
    //printf("%d\t%d\n\n",d,S);
    //lmochkil kain fajouter fin xxxxxxxx
    //ajoutFinRX('O',d2,S2);
    while(i<OC){
        printf("\nha ajout fin\n");
        ajoutFinR('O',S7,T[i]);
        afficherR();
        S7+=T[i];
        i++;

    }
    ajoutFinRX('L',S7,S);
//printf("\nha ajout dial X\n"); afficherR();printf("\n\n");


cpt5++;

}


nodeR* compactageRXC(nodeR* X)
{
    nodeR*tempX=X,*p,*tempX1=X,*tempX2;nodeR* tempX3=X;
    int* T;int i=0,OC=0;
    int S=0, S2=0,cpt5=0,d1,d2,S3;nodeR* BB=X->prev;

   while(tempX3->r.etat!='L')
       tempX3=tempX3->next;
    d1=tempX->r.debut;
    while(tempX1->r.etat!='O'){
        tempX1=tempX1->next;

    }
   // d1=tempX->r.debut;
    d2=tempX1->r.debut;
    S3=tempX1->r.taille;


   do {//hna kain lmochkil lboucle makatssalich

            if(tempX->r.etat=='L'){
                    if(d1>=tempX->r.debut)
                       d1=tempX->r.debut;

            S+=tempX->r.taille;

           //hna fin danit kain lmochkil
        p=tempX;
        tempX=tempX->next;
        printf("\nrun\n");printf("\n\n%d\n\n",p->r.taille);
        X=suppMillRXC(X,p);printf("\n\n"); afficherRC(X);printf("\n\n");
        // printf("%d\t%d\n\n",d,S);}
}
        else{
            if(d2<=tempX->r.debut){
                       d2=tempX->r.debut;
                       S3=tempX->r.taille;

            }
            OC++;
          tempX=tempX->next;
         }

    }while(tempX!=BB);
    if(tempX->next==tempX){

        if(tempX->r.etat=='L'){
                    if(d1>=tempX->r.debut)
                       d1=tempX->r.debut;

            S+=tempX->r.taille;

           //hna fin danit kain lmochkil
        p=tempX;

        printf("\nrun\n");printf("\n\n%d\n\n",p->r.taille);
        X=suppMillRXC(X,p);printf("\n\n"); afficherRC(X);printf("\n\n");
        // printf("%d\t%d\n\n",d,S);}
}
        else{
            if(d2<=tempX->r.debut){
                       d2=tempX->r.debut;
                       S3=tempX->r.taille;

            }
            OC++;

         }




    }


  printf("\nha l3amda\n"); afficherRC(X);printf("\n\n");


    T=(int*)malloc(OC*(sizeof(int)));
    tempX2=X;
//    T1=(int*)malloc(OC*(sizeof(int)));
   do {

              T[i]=tempX2->r.taille;
              printf("\n\nha la taille%d\n\n",T[i]);
             // T1[i]=tempX2->r.debut;
              p=tempX2;
        tempX2=tempX2->next;
        X=suppMillRXC(tempX2->prev,p);afficherRC(X);
        i++;
        // printf("\nxxxx\n");afficherR();printf("\n\n");



    }while(tempX2!=BB||i<OC);
   int S7=0;
    i=0;
    //tempX2=headR;
   // ajoutFinR('O',0,T[0]);
    //printf("%d\t%d\n\n",d,S);
    //lmochkil kain fajouter fin xxxxxxxx
    //ajoutFinRX('O',d2,S2);
    while(i<OC){
        printf("\nha ajout fin\n");
        X=ajoutFinRC(X,'O',S7,T[i]);
       // afficherR();
        S7+=T[i];
        i++;

    }
    X=ajoutFinRC(X,'L',S7,S);
//printf("\nha ajout dial X\n"); afficherR();printf("\n\n");


cpt5++;
return X;
}

void afficherRC(nodeR* X){
nodeR* temp=X;
if(X==NULL){
    printf("liste vide\n");
    return;

}else{//printf("\nX%d->X1%d->X2%d\n",X->r.taille,X->next->r.taille,X->next->next->r.taille);
do{
    printf("(%c de %d et taille %d)->",temp->r.etat,temp->r.debut,temp->r.taille);
    temp=temp->next;}while(temp!=X);
    //printf("\nnnnn\n");

}
}




void main()
{
    int ch_menu1,ch_menu2;
    int taille_memoire;
    char file_data[20];
    nodeP X;

  printf("\n\n\n\n          ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
  printf("          ³                                             ³\n");
  printf("          ³                MENU                         ³\n");
  printf("          ³                                             ³\n");
  printf("          ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
  printf("          ³       1-Data                                ³\n");
  printf("          ³       2-Choix d'algorithme                  ³\n");
  printf("          ³       3-Affichage du resultas               ³\n");
  printf("          ³       4-Quitter                             ³\n");
  printf("          ³                                             ³\n");
  printf("          ³                                             ³\n");
  printf("          ³                          votre choix:");scanf("%d",&ch_menu1);
  printf("          ³                                             ³\n");
  printf("          ³                                             ³\n");
  printf("          ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n\n");
 switch(ch_menu1)
 {
 case 1:
    {




        FILE * fichierR1=NULL;
        printf("Saisisser la taille de la memoire centrale:");
        scanf("%d",&taille_memoire);
        printf("\nSaisissez le chemin source               :");
        getchar();
        gets(file_data);
        fichierR1=fopen(file_data,"r");

        while(fscanf(fichierR1,"%c%dko,",&X.signe,&X.val)!=EOF){
              ajoutFin( X.signe,X.val);
            }

       afficher();
    }
    break;
 case 2:
    {
     printf("\n\n\n\n          ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
  printf("          ³                                             ³\n");
  printf("          ³                MENU2                        ³\n");
  printf("          ³                                             ³\n");
  printf("          ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
  printf("          ³       1-FIRST FIT                           ³\n");
  printf("          ³       2-NEXT FIT                            ³\n");
  printf("          ³       3-BEST FIT                            ³\n");
  printf("          ³       4-WORST FIT                           ³\n");
  printf("          ³       5-RETOUR                              ³\n");
  printf("          ³                                             ³\n");
  printf("          ³                                             ³\n");
  printf("          ³                          votre choix:");scanf("%d",&ch_menu2);
  printf("          ³                                             ³\n");
  printf("          ³                                             ³\n");
  printf("          ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n\n");
  switch(ch_menu2)
  {
  case 1:
    {

       FILE * fichierR1=NULL;
        printf("Saisisser la taille de la memoire centrale:");
        scanf("%d",&taille_memoire);
        printf("\nSaisissez le chemin source               :");
        getchar();
        gets(file_data);
        fichierR1=fopen(file_data,"r");

        while(fscanf(fichierR1,"%c%dko,",&X.signe,&X.val)!=EOF){
              ajoutFin( X.signe,X.val);
            }
      int Y,X,boole,dif,debut_taille,debut_taille2,cmp,cmp2,cpt=0;
      nodeP* temp=head;
      char all;
      nodeR* temp2,*temp3,*temp4,*aide,*temp5;
      nodeR* init=(nodeR*)malloc(sizeof(nodeR));
      init->next=init->prev=NULL;
      init->r.etat='L';
      init->r.debut=0;
      init->r.taille=taille_memoire;
      headR=init;



      while(temp!=NULL){
            boole=0;temp2=headR;
          while(temp2!=NULL&&boole==0){

        cmp=((temp2->r.taille)-(temp->val));
        cmp2=((temp2->r.taille)-(temp->val));
        all=temp->signe;
        if(all=='-'){
            if((cmp==0)&&(temp2->r.etat=='O')){

                temp2->r.etat='L';



              /*  temp3=headR;
              while(temp3!=NULL){
                 if(temp3->r.etat=='L'){
                  printf("\n\nha lmochkil\n\n");
                 ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

                 temp4=temp3;
                 temp3=temp3->next;
                 suppMillR(temp4);

               // afficherR();
            }
              temp3=temp3->next;}*/




                boole=1;
            }/*else if((cmp>0)&&(temp2->r.etat=='O')&&(cpt5==1)){
            ajoutFinR('O',temp2->r.debut,cmp);
            ajoutFinR('L',cmp,temp->val);

            suppMillR(temp2);







            boole=1;//hna fin 4ana rwicha
            printf("\n\nha desaloc\n\n");afficherR();printf("\n\n");//compactageRXX();  printf("\n\nha mn ora compactege"); afficherR();printf("\n\n");
            }*/

            }
        else{
            if((cmp2>=0)&&(temp2->r.etat=='L')){
              if(temp2==headR){
                 if(temp2->next!=NULL){


                    suppDebutR();

                    ajoutDebutR('O',0,temp->val);



                    ajoutmillR(temp2,'L',temp->val,cmp2);//mochkil hnaxxxxx
                    printf("\nha nam\n");
                    boole=1;
                     printf("\n\na5ir mara if dial if lawla\n\n");

                }
                else{

                suppDebutR();

                ajoutDebutR('O',0,temp->val);
                ajoutFinR('L',temp->val,cmp);


                     boole=1;

                  printf("\n\na5ir mara else dial if lawla\n\n");

                }


                }
              else if(temp2->next==NULL&&temp2!=headR)
             {
               X=temp2->r.debut;

               suppFinR();
               ajoutFinR('O',X,temp->val);
               ajoutFinR('L',(X+temp->val),cmp);
                boole=1;
               printf("\n\na5ir mara elseif\n\n");

              }
              else
              {




                  Y=((temp2->prev->r.debut)+(temp2->prev->r.taille));
                  ajoutmillR(temp2,'L',Y+temp->val,cmp2);
                  ajoutmillR(temp2,'O',Y,temp->val);

                  suppMillR(temp2);
                  printf("\n\n a5ir mara else\n\n");

                   boole=1;

              }
            }/*else{
            temp3=headR;
              while(temp3!=NULL){
                 if(temp3->r.etat=='L'){
                  printf("\n\nha lmochkil\n\n");
                 ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

                 temp4=temp3;
                 temp3=temp3->next;
                 suppMillR(temp4);

               // afficherR();
            }
              temp3=temp3->next;}


}*/




        }
      temp2=temp2->next;
      }printf("\n\nha l3adi\n\n");afficherR();printf("\n\n\n\n");
       //compactage

     /* temp3=headR;

      while(temp3!=NULL){

       if((temp3->r.etat)=='L'){

        temp4=temp3->next;

        while((temp4->r.etat)!='O'||(temp4!=NULL)){
            temp4=temp4->next;
            }
        if((temp4->r.etat)=='O'){
            aide=temp4;
            temp4=temp3;
            temp3=aide;
        }


        printf("\n\nha lmochkil\n\n");

       }

       temp3=temp3->next;

      }*/


/* temp3=headR;
while(temp3!=NULL){
    if(temp3->r.etat=='L'){
         printf("\n\nha lmochkil\n\n");
        ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

        temp4=temp3;
        temp3=temp3->next;
        suppMillR(temp4);

        afficherR();
    }
    temp3=temp3->next;


}*/
//triparselectionR();
//compactageR();

     int cpt10=0;
     int* Tab;

      if(temp2==NULL){
            ajoutFinL(temp->signe,temp->val);printf("\nlist attente\n"); afficherL();printf("\n\n");
            if(cpt10==0){
                Tab=(int*)malloc(sizeof(int));
                Tab[cpt10]=temp->val;
                cpt10++;
            }else{
            Tab=(int*)realloc(Tab,(cpt10+1)*sizeof(int));
            Tab[cpt10]=temp->val;
            cpt10++;
            }






            //printf("\n\nha tab %d\n\n",cpt10);
            //printf("\n\nhaaa 9bal compactege"); afficherR();printf("\n\n");
//printf("\n\nha lmochkil\n\n");
    /* temp3=headR;
   while(temp3!=NULL){
    if(temp3->r.etat=='L'){
         //printf("\n\nha lmochkil\n\n");
        ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

        temp4=temp3;
        temp3=temp3->next;
        suppMillR(temp4);
       // printf("\n\n");
       // afficherR();
        // printf("\n\n");
    }
    temp3=temp3->next;


}printf("\n\nha affichage dial mn ora l9aziba\n\n");afficherR();printf("\n\n");*/

// compactageRX();
//a5ir affichage printf("\n\nha mn ora compactege"); afficherR();printf("\n\n");



printf("\n\nha 9bal compactege");compactageRX();  printf("\n\nha mn ora compactege"); afficherR();printf("\n\n");afficherL();printf("\n\n");

nodeP* tempL=headF,pF;
nodeR* tempR=headR,pR;
nodeP* tempX=head;
int i,j,X10=Tab[0];

 printf("\nLISTE\n");
for(i=0;i<cpt10;i++){
    if(X10>Tab[i])
        X10=Tab[i];
}printf("\n\n%d\n\n",X10);
printf("\n\n%d\n\n",tempL->val);
while(tempX!=NULL){
    if(tempX->val==X10)
        break;
    tempX=tempX->next;}
if(tempX->signe=='-'){
    while(tempR!=NULL){
            if(tempR->r.taille==X10&&tempR->r.etat=='O')
                break;
        tempR=tempR->next;}
    if(tempR->r.taille==X10&&tempR->r.etat=='O'&&tempR!=NULL){
        while(tempL!=X10){
              if(tempL->val==X10)
                break;
            tempL=tempL->next;}
        if(tempL->val==X10){
                printf("\nmn 9bl supp\n");
            suppMillF('-',X10);
            //finma ndir supression 5asni n9os mn tableau dynamique
            //free(Tab[i-1]);
           // cpt10--;
            ajoutmillP(temp,'-',X10);
             printf("\nmn ore supp\n");afficherL();printf("\n\n");
        }


    }else
    break;



} else{
    while(tempR!=NULL){
            if((tempR->r.taille>=X10)&&(tempR->r.etat=='L'))
            break;
            //printf("\n\ntaille%d\n\n",tempR->r.taille);
        tempR=tempR->next;}
   printf("\n\ntaile dial 5ona fliste%d\n\n",X10);
    if(tempR!=NULL){
             printf("\n\ntaille%d\n\n",tempR->r.taille);
        while(tempL!=X10){
                if(tempL->val==X10)
                break;
            tempL=tempL->next;}
        if(tempL->val==X10){
                printf("\nmn 9bl supp\n");
            suppMillF('+',X10);
           // cpt10--;
            ajoutmillP(temp,'+',X10);
            printf("\nmn ore supp\n");afficherL();printf("\n\n");
        }


    }else
    printf("\nhossam\n");




}

   } nodeR*XY=temp;

      printf("\nha lvaleur%c%d\n",temp->signe,temp->val);
      temp=temp->next;


    // printf("\n\n");afficherR(); printf("\n\n");
      }printf("\nlist attente\n"); afficherL();/*compactageR()*/;printf("\nha lista la5raR\n");afficherR(); printf("\n\n");nodeP*tempF=headF;nodeR*ZZ=headR;
    /*  if(headF!=NULL ){
        while(tempF!=NULL){
            ajoutFin(tempF->signe,tempF->val);
            tempF=tempF->next;
        }
        while(ZZ!=XY)
            ZZ=ZZ->next;



      }*/



        break;
    }
  case 2:
    {

              FILE * fichierR1=NULL;
        printf("Saisisser la taille de la memoire centrale:");
        scanf("%d",&taille_memoire);
        printf("\nSaisissez le chemin source               :");
        getchar();
        gets(file_data);
        fichierR1=fopen(file_data,"r");

        while(fscanf(fichierR1,"%c%dko,",&X.signe,&X.val)!=EOF){
              ajoutFin( X.signe,X.val);
            }
      int Y,X,boole,dif,debut_taille,debut_taille2,cmp,cmp2,cpt=0;
      nodeP* temp=head;
      char all;
      nodeR* temp2,*temp3,*temp4,*aide,*temp5;
      nodeR* init=(nodeR*)malloc(sizeof(nodeR));
      init->next=init->prev=NULL;
      init->r.etat='L';
      init->r.debut=0;
      init->r.taille=taille_memoire;
      headR=init;
      nodeR*opp;
      int A;int cptX=0;
      temp2=headR;
      while(temp2->next!=NULL)
        temp2=temp2->next;
      temp2->next=headR;
      headR->prev=temp2;
      opp=headR;
      afficherRC(opp);
      temp2=opp;
     // temp=head;
     // printf("\nopp%d\n",opp->next->r.taille);
     // temp2=opp->next;
     int tripleX=0;int cmp3,cmp4;
     cmp3=((temp2->r.taille)-(temp->val));
        cmp4=((temp2->r.taille)-(temp->val));

                  opp=suppDebutRC(opp);
                  // printf("\nhossam\n");afficherRC(opp);printf("\n\n");
                   opp=ajoutDebutRC(opp,'O',0,temp->val);printf("\nopp1%d\n",opp->r.taille);
                   //printf("\ndebut\n");afficherRC(opp);printf("\n xxx \n");
                   //printf("\ntemp2%d\n",opp->r.taille);
                   opp=ajoutmillRC(opp,temp2,'L',temp->val,cmp3);
                   //tripleX++;
                   //printf("\nha lblan\n");afficherRC(opp);printf("\n");
                   temp=temp->next;




      while(temp!=NULL){
            boole=0;A=0;
           /* if(temp->signe=='+'){
                if(cptX==0)
                    temp2=opp;
                else
                    temp2=opp->next;
            }

            else
                temp2=headR;*/

         temp2=opp->next;


          while(temp2!=opp&&boole==0){
               /* if(temp2==opp)
                break;*/

        cmp=((temp2->r.taille)-(temp->val));
        cmp2=((temp2->r.taille)-(temp->val));
        all=temp->signe;
        if(all=='-'){
            if((cmp==0)&&(temp2->r.etat=='O')){

                temp2->r.etat='L';



              /*  temp3=headR;
              while(temp3!=NULL){
                 if(temp3->r.etat=='L'){
                  printf("\n\nha lmochkil\n\n");
                 ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

                 temp4=temp3;
                 temp3=temp3->next;
                 suppMillR(temp4);

               // afficherR();
            }
              temp3=temp3->next;}*/




                boole=1;
                opp=temp2;A=1;printf("\ndelocation\n");
               // printf("\ntemp2 %d\n",temp2->r.taille);
            }/*else if((cmp>0)&&(temp2->r.etat=='O')&&(cpt5==1)){
            ajoutFinR('O',temp2->r.debut,cmp);
            ajoutFinR('L',cmp,temp->val);

            suppMillR(temp2);







            boole=1;//hna fin 4ana rwicha
            printf("\n\nha desaloc\n\n");afficherR();printf("\n\n");//compactageRXX();  printf("\n\nha mn ora compactege"); afficherR();printf("\n\n");
            }*/

            }
        else{
            if((cmp2>=0)&&(temp2->r.etat=='L')){
              if(opp==NULL){



                    opp=suppDebutRC(opp);

                    opp=ajoutDebutRC(opp,'O',0,temp->val);



                    opp=ajoutmillRC(opp,temp2,'L',temp->val,cmp2);//mochkil hnaxxxxx
                    printf("\nha nam\n");
                    boole=1;
                     printf("\n\na5ir mara if \n\n");opp=temp2->next;A=1;




              }



          /*    else if(temp2->next==NULL&&temp2!=headR)
             {
               X=temp2->r.debut;

               suppFinR();
               ajoutFinR('O',X,temp->val);
               ajoutFinR('L',(X+temp->val),cmp);
                boole=1;

               printf("\n\na5ir mara elseif\n\n");opp=temp2->next;A=1;

              }*/
              else
              {




                  Y=((temp2->prev->r.debut)+(temp2->prev->r.taille));
                  opp=ajoutmillRC(opp,temp2,'L',Y+temp->val,cmp2);
                  opp=ajoutmillRC(opp,temp2,'O',Y,temp->val);
                  //opp=temp2;
                 // printf("\n\n else opp %d \n\n",opp->r.taille);
                  opp=suppMillRC(opp,temp2);
                  printf("\n\n else opp %d \n\n",opp->r.taille);
                  printf("\n\n a5ir mara else\n\n");

                   boole=1;
                  opp=temp2->next;A=1;
                   printf("\n\n else opp %d \n\n",opp->r.taille);

              }
            }/*else{
            temp3=headR;
              while(temp3!=NULL){
                 if(temp3->r.etat=='L'){
                  printf("\n\nha lmochkil\n\n");
                 ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

                 temp4=temp3;
                 temp3=temp3->next;
                 suppMillR(temp4);

               // afficherR();
            }
              temp3=temp3->next;}


}*/




        }
      temp2=temp2->next;
      }printf("\n\nha l3adi\n\n");afficherRC(opp);printf("\n\n\n\n");//printf("\ntemp2%d\n",temp2->r.taille);
       //compactage

     /* temp3=headR;

      while(temp3!=NULL){

       if((temp3->r.etat)=='L'){

        temp4=temp3->next;

        while((temp4->r.etat)!='O'||(temp4!=NULL)){
            temp4=temp4->next;
            }
        if((temp4->r.etat)=='O'){
            aide=temp4;
            temp4=temp3;
            temp3=aide;
        }


        printf("\n\nha lmochkil\n\n");

       }

       temp3=temp3->next;

      }*/


/* temp3=headR;
while(temp3!=NULL){
    if(temp3->r.etat=='L'){
         printf("\n\nha lmochkil\n\n");
        ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

        temp4=temp3;
        temp3=temp3->next;
        suppMillR(temp4);

        afficherR();
    }
    temp3=temp3->next;


}*/
//triparselectionR();
//compactageR();

     int cpt10=0;
     int* Tab;
     char* Tab1;int bo;
     nodeR* XL=opp;
     //printf("\nXL%d\n",XL->r.taille);//lmochkil kain hna+-
  /*   if(temp->signe=='-'){
     while(XL!=NULL){
        if(XL->r.taille==temp->val){
        bo=1;
        break;}
        else
            bo=0;
        XL=XL->next;}}
        else{
        while(XL!=opp){
        if(XL->r.taille>=temp->val){
        bo=1;
        break;}
        else
            bo=0;
        XL=XL->next;}



        }*/

            printf("\n\nopp %d  A%d",opp->r.taille,A);


     /* if(temp2==NULL&&bo==1&&A==0){//lmochkil hna
               temp2=headR;temp=temp->prev;}
               if(A==1){
            if(temp->next->signe=='+'){
                if(opp!=NULL)
                    temp2=opp->next;
                else
                    temp2=headR;
            }
            if(temp->next->signe=='-')
                temp2=headR;}*/
              //  temp2=opp->next;
      if(A==0){
            ajoutFinL(temp->signe,temp->val);printf("\nlist attente\n"); afficherL();printf("\n\n");
            if(cpt10==0){
                Tab=(int*)malloc(sizeof(int));
                Tab[cpt10]=temp->val;
                Tab1=(char*)malloc(sizeof(char));
                Tab1[cpt10]=temp->signe;
                cpt10++;
            }else{
            Tab=(int*)realloc(Tab,(cpt10+1)*sizeof(int));
            Tab[cpt10]=temp->val;
            Tab1=(char*)realloc(Tab1,(cpt10+1)*sizeof(char));
            Tab1[cpt10]=temp->signe;
            cpt10++;
            }




int hasna;
if(opp->prev==opp)
    hasna=opp;
else
hasna=opp->prev->r.taille;//kain chi mochkil hna

            //printf("\n\nha tab %d\n\n",cpt10);
            //printf("\n\nhaaa 9bal compactege"); afficherR();printf("\n\n");
//printf("\n\nha lmochkil\n\n");
    /* temp3=headR;
   while(temp3!=NULL){
    if(temp3->r.etat=='L'){
         //printf("\n\nha lmochkil\n\n");
        ajoutFinR(temp3->r.etat,temp3->r.debut,temp3->r.taille);

        temp4=temp3;
        temp3=temp3->next;
        suppMillR(temp4);
       // printf("\n\n");
       // afficherR();
        // printf("\n\n");
    }
    temp3=temp3->next;


}printf("\n\nha affichage dial mn ora l9aziba\n\n");afficherR();printf("\n\n");*/

// compactageRX();
//a5ir affichage printf("\n\nha mn ora compactege"); afficherR();printf("\n\n");



printf("\n\nha 9bal compactege");opp=compactageRXC(opp);  printf("\n\nha mn ora compactege"); afficherRC(opp);printf("\n\n");afficherL();printf("\n\n");

nodeP* tempL=headF,pF;
nodeR* tempR=headR,pR;//tempR=opp->next;
nodeP* tempX=head;
int i,j,X10=Tab[0];

 printf("\nLISTE\n");
for(i=0;i<cpt10;i++){
    if(X10>Tab[i])
        X10=Tab[i];
}printf("\n\n%d\n\n",X10);
printf("\n\n%d\n\n",tempL->val);
while(tempX!=NULL){
    if(tempX->val==X10)
        break;
    tempX=tempX->next;}
if(tempX->signe=='-'){
    while(tempR!=NULL){
            if(tempR->r.taille==X10&&tempR->r.etat=='O')
                break;
        tempR=tempR->next;}
    if(tempR->r.taille==X10&&tempR->r.etat=='O'&&tempR!=NULL){
        while(tempL!=X10){
              if(tempL->val==X10)
                break;
            tempL=tempL->next;}
        if(tempL->val==X10){
                printf("\nmn 9bl supp\n");
            suppMillF('-',X10);
            //finma ndir supression 5asni n9os mn tableau dynamique
            //free(Tab[i-1]);
           // cpt10--;
           // ajoutmillP(temp,'-',X10);
            temp=temp->prev;
            temp2=opp->next;
             printf("\nmn ore supp\n");afficherL();printf("\n\n"); printf("\nmn ore 5edma\n");afficher();printf("\n\n");
        }


    }else{tempR=headR;
    while(tempR!=NULL){
            if(tempR->r.taille==X10&&tempR->r.etat=='O')
                break;
        tempR=tempR->next;}



    }



} else{
    while(tempR!=NULL){
            if((tempR->r.taille>=X10)&&(tempR->r.etat=='L'))
            break;
            //printf("\n\ntaille%d\n\n",tempR->r.taille);
        tempR=tempR->next;}
    //  printf("\n\ntaile dial 5ona tempR%d\n\n",tempR->r.taille);
  // printf("\n\ntaile dial 5ona fliste%d\n\n",X10);
    if(tempR!=NULL){
             printf("\n\ntaille%d\n\n",tempR->r.taille);
        while(tempL!=X10){
                if(tempL->val==X10)
                break;
            tempL=tempL->next;}
        if(tempL->val==X10){
                printf("\nopp%d\n",hasna);
                printf("\nmn 9bl supp\n");
            suppMillF('+',X10);
           // cpt10--;
           printf("\nha temp chno fiha%d\n",temp->val);
            //ajoutmillP(temp,'+',X10);
            temp=temp->prev;
            temp2=opp->next;
            printf("\nmn ore supp\n");afficherL();printf("\n\n"); printf("\nmn ore 5edma\n");afficher();printf("\n\n");
        }


    }else
    printf("\nhossam\n");




} /*temp2=headR;
while(temp2->r.taille!=hasna)
    temp2=temp2->next;//bo=0;*/
//temp2=temp2->next;
   } nodeR*XY=temp;

      printf("\nha lvaleur%c%d\n",temp->signe,temp->val);
      temp=temp->next;


    // printf("\n\n");afficherR(); printf("\n\n");
      }printf("\nlist attente\n"); afficherL();/*compactageR()*/;printf("\nha lista la5raR\n");afficherRC(opp); printf("\n\n");nodeP*tempF=headF;nodeR*ZZ=headR;
    /*  if(headF!=NULL ){
        while(tempF!=NULL){
            ajoutFin(tempF->signe,tempF->val);
            tempF=tempF->next;
        }
        while(ZZ!=XY)
            ZZ=ZZ->next;



      }*/




        break;
    }
  case 3:
    {


        FILE * fichierR1=NULL;
        printf("Saisisser la taille de la memoire centrale:");
        scanf("%d",&taille_memoire);
        printf("\nSaisissez le chemin source               :");
        getchar();
        gets(file_data);
        fichierR1=fopen(file_data,"r");

        while(fscanf(fichierR1,"%c%dko,",&X.signe,&X.val)!=EOF){
              ajoutFin( X.signe,X.val);
            }
      int Y,X,boole,dif,debut_taille,debut_taille2,cmp,cmp2,cpt=0;
      nodeP* temp=head;
      char all;
      nodeR* temp2,*temp3,*temp4,*aide,*temp5;
      nodeR* init=(nodeR*)malloc(sizeof(nodeR));
      init->next=init->prev=NULL;
      init->r.etat='L';
      init->r.debut=0;
      init->r.taille=taille_memoire;
      headR=init;


      while(temp!=NULL){
            boole=0;temp2=headR;int best;//5asni initiliziha fawl zone libre
     if(temp->signe=='+') {
        nodeR* temp10=headR;
        while(temp10!=NULL){
            if(temp10->r.etat=='L'&&(temp10->r.taille)>=(temp->val)){
                best=temp10->r.taille;
                break;}

            temp10=temp10->next;
        }printf("\nha temp10 %c%d%d\n",temp10->r.etat,temp10->r.debut,temp10->r.taille);
        printf("\nha lbest1 %d\n",best);
        temp10=headR;
      while(temp10!=NULL){
        if(temp10->r.etat=='L'){

                printf("\n temp%d\n",temp->val);
            if((best>temp10->r.taille)&&((temp10->r.taille)>=(temp->val))){//derti ila lbest kan kbar o howa 3amro aykon kbar mnha 50 o 300
                best=temp10->r.taille;
                printf("\n%c%d%d\n",temp10->r.etat,temp10->r.debut,temp10->r.taille);}
                printf("\n\nha tabet best%d\n\n",best);
        }

        temp10=temp10->next;

      }printf("\nha lbest2 %d\n",best);
      }






          while(temp2!=NULL&&boole==0){
            cmp=((temp2->r.taille)-(temp->val));
            cmp2=((temp2->r.taille)-(temp->val));

        all=temp->signe;
        if(all=='-'){
            if((cmp==0)&&(temp2->r.etat=='O')){
                printf("\nha temp2 desaloc%d\n",temp2->r.taille);
                temp2->r.etat='L';






                printf("\n\nha desaloc\n\n");afficherR();printf("\n\n");
                boole=1;
            }






           // boole=1;

            }



        else{

        if(temp2->r.taille==best){

              if(temp2==headR){
                 if(temp2->next!=NULL){


                    suppDebutR();

                    ajoutDebutR('O',0,temp->val);



                    ajoutmillR(temp2,'L',temp->val,cmp2);
                    printf("\nha nam\n");
                    boole=1;
                     printf("\n\na5ir mara if dial if lawla\n\n");

                }
                else{

                suppDebutR();

                ajoutDebutR('O',0,temp->val);
                ajoutFinR('L',temp->val,cmp);


                     boole=1;

                  printf("\n\na5ir mara else dial if lawla\n\n");

                }


                }
              else if(temp2->next==NULL&&temp2!=headR)
             {
               X=temp2->r.debut;

               suppFinR();
               ajoutFinR('O',X,temp->val);
               ajoutFinR('L',(X+temp->val),cmp);
                boole=1;
               printf("\n\na5ir mara elseif\n\n");

              }
              else
              {




                  Y=((temp2->prev->r.debut)+(temp2->prev->r.taille));
                  ajoutmillR(temp2,'L',Y+temp->val,cmp2);
                  ajoutmillR(temp2,'O',Y,temp->val);

                  suppMillR(temp2);
                  printf("\n\n a5ir mara else\n\n");

                   boole=1;

              }}




        }
      temp2=temp2->next;
      }printf("\n\nha l3adi\n\n");afficherR();printf("\n\n\n\n");


     int cpt10=0;
     int* Tab;

      if(temp2==NULL){
            ajoutFinL(temp->signe,temp->val);printf("\nlist attente\n"); afficherL();printf("\n\n");
            if(cpt10==0){
                Tab=(int*)malloc(sizeof(int));
                Tab[cpt10]=temp->val;
                cpt10++;
            }else{
            Tab=(int*)realloc(Tab,(cpt10+1)*sizeof(int));
            Tab[cpt10]=temp->val;
            cpt10++;
            }










printf("\n\nha 9bal compactege");compactageRX();  printf("\n\nha mn ora compactege"); afficherR();printf("\n\n");afficherL();printf("\n\n");

nodeP* tempL=headF,pF;
nodeR* tempR=headR,pR;
nodeP* tempX=head;
int i,j,X10=Tab[0];

 printf("\nLISTE\n");
for(i=0;i<cpt10;i++){
    if(X10>Tab[i])
        X10=Tab[i];
}printf("\n\n%d\n\n",X10);
printf("\n\n%d\n\n",tempL->val);
while(tempX!=NULL){
    if(tempX->val==X10)
        break;
    tempX=tempX->next;}
if(tempX->signe=='-'){
    while(tempR!=NULL){
            if(tempR->r.taille==X10&&tempR->r.etat=='O')
                break;
        tempR=tempR->next;}
    if(tempR->r.taille==X10&&tempR->r.etat=='O'&&tempR!=NULL){
        while(tempL!=X10){
              if(tempL->val==X10)
                break;
            tempL=tempL->next;}
        if(tempL->val==X10){
                printf("\nmn 9bl supp\n");
            suppMillF('-',X10);
            ajoutmillP(temp,'-',X10);
             printf("\nmn ore supp\n");afficherL();printf("\n\n");
        }


    }else
    break;



} else{
    while(tempR!=NULL){
            if((tempR->r.taille>=X10)&&(tempR->r.etat=='L'))
            break;
        tempR=tempR->next;}
   printf("\n\ntaile dial 5ona fliste%d\n\n",X10);
    if(tempR!=NULL){
             printf("\n\ntaille%d\n\n",tempR->r.taille);
        while(tempL!=X10){
                if(tempL->val==X10)
                break;
            tempL=tempL->next;}
        if(tempL->val==X10){
                printf("\nmn 9bl supp\n");
            suppMillF('+',X10);
            ajoutmillP(temp,'+',X10);
            printf("\nmn ore supp\n");afficherL();printf("\n\n");
        }


    }else
    printf("\nhossam\n");




}

   } nodeR*XY=temp;

      printf("\nha lvaleur%c%d\n",temp->signe,temp->val);
      temp=temp->next;



      }printf("\nlist attente\n"); afficherL();/*compactageR()*/;printf("\nha lista la5raR\n");afficherR(); printf("\n\n");nodeP*tempF=headF;nodeR*ZZ=headR;



        break;
    }
  case 4:
    exit(1);
  case 5:
    exit(1);
  default:
    printf("erreur choisissez un nombre entre 1 et 5");
  }
    }
  case 3:
    {
        break;
    }
  case 4:
    exit(1);
  default:
    printf("erreur choisissez un nombre entre 1 et 4");
 }



}









