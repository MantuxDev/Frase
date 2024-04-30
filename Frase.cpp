// *Frase*

// In un vettore di 100 elementi è memorizzata una frase.
// Ogni lettera della frase è contenuta in un elemento del vettore.

// *Scrivi un programma che permetta di: 
// a) memorizzare la frase nell'array
// b) stampare la frase al contrario
// c) stampare il numero di parole memorizzate nell'array
// d) stampare quante volte compare ciascuna vocale  e quale 
//    compare più spesso

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

//Colori    
#define BOLDBLUE    "\033[1m\033[34m"  /*Messaggi*/      
#define BOLDRED     "\033[1m\033[31m"  /*Errore*/ 
#define BOLDYELLOW  "\033[1m\033[33m"  /*Attenzione*/
#define BOLDGREEN   "\033[1m\033[32m"  /*Successo*/            
#define RESET   "\033[0m" 

//Dichiarazione costanti
const int e=100;

//Prototipi
int menu();
int inserisci(char frase[]);
void contrario(char frase[],int n);
int parole(char frase[],int n);
void vocali(char frase[],int n);
void avanti();

int main(){

    //Dichiarazione variabili
    int s,n,p;
    char frase[e];

    do{
        system("cls");
        s=menu();

        switch(s){

            case 1:{
                n=inserisci(frase);
                break;
            }

            case 2:{
                contrario(frase,n);
                break;
            }

            case 3:{
                p=parole(frase,n);
                cout<<BOLDBLUE<<"Il numero di parole e' "<<p+1<<RESET<<endl;
                avanti();
                break;
            }

            case 4:{
                vocali(frase,n);
                break;
            }

            case 0:{
                cout<<BOLDBLUE<<"Arrivederci!"<<RESET<<endl;
                break;
            }

            default:{
                cout<<BOLDRED<<"Scelta non valida!"<<RESET<<endl;
                break;
            }

        }// switch
    }while(s!=0);

    return 0;
}

int menu(){

    int scelta;

    cout<<BOLDBLUE<<"\t -------MENU-------\n"<<RESET;
    cout<<BOLDBLUE<<"1) "<<RESET<<"Inserisci la frase"<<endl;
    cout<<BOLDBLUE<<"2) "<<RESET<<"Stampa la frase al contrario"<<endl;
    cout<<BOLDBLUE<<"3) "<<RESET<<"Conta il numero di parole"<<endl;
    cout<<BOLDBLUE<<"4) "<<RESET<<"Controlla le vocali"<<endl;
    cout<<BOLDBLUE<<"0) "<<RESET<<"Esci"<<endl;

    cout<<"\n"<<BOLDBLUE<<"Fai una scelta: "<<RESET;
    cin>>scelta;

    return scelta;
}

// a)
int inserisci(char frase[]){

    int n;

    cout<<"\n"<<BOLDBLUE<<"Inserisci la frase: "<<RESET;
    cin.ignore();
    cin.getline(frase,e);

    cout<<BOLDGREEN<<"Frase memorizzata!"<<RESET<<endl;

    for(int i=1;i<e;i++){
        if(frase[i]!='\0'){
            n=i;
        }
        else{
            break;
        }
    }

    return n+1;
}

// b)
void contrario(char frase[],int n){
    for(int i=n-1;i>=0;i--){
        cout<<frase[i];
    }

    avanti();
}

// c)
int parole(char frase[],int n){

    int x=0;
    for(int i=0;i<n;i++){
        if(frase[i]==' '){
            x++;
        }
    }

    return x;
}

// d)
void vocali(char frase[],int n){

    int a=0,e=0,i=0,o=0,u=0;

    for(int i=0;i<n;i++){
        if(frase[i]=='a'){
            a++;
        }
        else if(frase[i]=='e'){
            e++;
        }
        else if(frase[i]=='i'){
            i++;
        }
        else if(frase[i]=='o'){
            o++;
        }
        else if(frase[i]=='u'){
            u++;
        }
    }
    cout<<BOLDBLUE<<"La frase contiene "<<a<<" vocali 'a', "<<e<<" vocali 'e', "<<i<<" vocali 'i', "<<o<<" vocali 'o', "<<u<<" vocali 'u'"<<RESET<<endl;

    avanti();
}

void avanti(){
    cout<<endl;
    cout<<BOLDBLUE<<"Premi invio per continuare..."<<RESET<<endl;
    cin.get();
    cin.ignore();
}