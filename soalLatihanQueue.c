/*
	Nama  : Ramdan Syaripudin
	NIM   : 1701507
	Prodi : Pendidikan Ilmu Komputer
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	int nomeja;
	int nopesanan;
	char nama[20];
	char pesanan[50];
}dataPesanan;

typedef struct elm *alamatelmt;
typedef struct elm{
	dataPesanan elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

void createEmpty(queue *Q){
	(*Q).first=NULL;
	(*Q).last=NULL;
}

int isEmpty(queue Q){
	int hasil=0;
	if(Q.first==NULL){
		hasil=1;
	}
	
	return hasil;
}

int countElement(queue Q){
	int hasil=0;
	
	if(Q.first!=NULL){
		elemen *elmt;
		elmt=Q.first;
		
		while(elmt!=NULL){
			hasil+=1;
			elmt=elmt->next;
		}
	}
	return hasil;
}

void add(int nomeja, int nopesanan, char nama[], char pesanan[], queue *Q){
	elemen *elmt;
	elmt=(elemen *) malloc(sizeof(elemen));
	
	elmt->elmt.nomeja=nomeja;
	elmt->elmt.nopesanan=nopesanan;
	strcpy(elmt->elmt.nama,nama);
	strcpy(elmt->elmt.pesanan,pesanan);
	elmt->next=NULL;
	
	if((*Q).first==NULL){
		(*Q).first=elmt;
	}
	else{
		(*Q).last->next=elmt;
	}
	
	(*Q).last=elmt;
	elmt=NULL;
}

void del(queue *Q){
	if((*Q).first!=0){
		elemen *elmt=(*Q).first;
		(*Q).first=(*Q).first->next;
		elmt->next=NULL;
		free(elmt);
	}
}

void printQueue(queue Q){
	if(Q.first!=NULL){
		printf("------- isi Queue -------\n");
		elemen *elmt=Q.first;
		
		int i=1;
		while(elmt!=NULL){
			printf("=========================\n");
			printf("elemen ke    : %d\n",i);
			printf("No Meja      : %d\n",elmt->elmt.nomeja);
			printf("No Pesanan   : %d\n",elmt->elmt.nopesanan);
			printf("Nama Pemesan : %s\n",elmt->elmt.nama);
			printf("Pesanan      : %s\n\n",elmt->elmt.pesanan);
			
			elmt=elmt->next;
			i+=1;
		}
		printf("-----------------------\n");
		
	}
	else{
		printf("queue kosong !!!");
	}
}

int main(int argc, char *argv[]){
	queue Q;
	createEmpty(&Q);
	printf("=========================\n");
	add(10,1,"Muhammad","Cilok Durian",&Q);
	add(12,2,"Ramdan","Cilok Kacang",&Q);
	add(7,3,"Syaripudin","Cilok Kuah",&Q);
	printQueue(Q);
	printf("=========================\n");
	del(&Q);
	del(&Q);
	printQueue(Q);
	printf("=========================\n");
	return 0;
}
