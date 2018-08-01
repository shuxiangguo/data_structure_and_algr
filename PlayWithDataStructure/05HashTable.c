#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ´æ´¢¿Õ¼ä³õÊ¼·ÖÅäÁ¿ */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* ¶¨ÒåÉ¢ÁÐ±í³¤ÎªÊý×éµÄ³¤¶È */
#define NULLKEY -32768 

typedef int Status;	/* StatusÊÇº¯ÊýµÄÀàÐÍ,ÆäÖµÊÇº¯Êý½á¹û×´Ì¬´úÂë£¬ÈçOKµÈ */ 

typedef struct
{
   int *elem; /* Êý¾ÝÔªËØ´æ´¢»ùÖ·£¬¶¯Ì¬·ÖÅäÊý×é */
   int count; /*  µ±Ç°Êý¾ÝÔªËØ¸öÊý */
}HashTable;

int m=0; /* É¢ÁÐ±í±í³¤£¬È«¾Ö±äÁ¿ */

/* ³õÊ¼»¯É¢ÁÐ±í */
Status InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY; 
	return OK;
}

/* É¢ÁÐº¯Êý */
int Hash(int key)
{
	return key % m; /* ³ýÁôÓàÊý·¨ */
}

/* ²åÈë¹Ø¼ü×Ö½øÉ¢ÁÐ±í */
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); /* ÇóÉ¢ÁÐµØÖ· */
	while (H->elem[addr] != NULLKEY) /* Èç¹û²»Îª¿Õ£¬Ôò³åÍ» */
	{
		addr = (addr+1) % m; /* ¿ª·Å¶¨Ö··¨µÄÏßÐÔÌ½²â */
	}
	H->elem[addr] = key; /* Ö±µ½ÓÐ¿ÕÎ»ºó²åÈë¹Ø¼ü×Ö */
}

/* É¢ÁÐ±í²éÕÒ¹Ø¼ü×Ö */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  /* ÇóÉ¢ÁÐµØÖ· */
	while(H.elem[*addr] != key) /* Èç¹û²»Îª¿Õ£¬Ôò³åÍ» */
	{
		*addr = (*addr+1) % m; /* ¿ª·Å¶¨Ö··¨µÄÏßÐÔÌ½²â */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* Èç¹ûÑ­»·»Øµ½Ô­µã */
			return UNSUCCESS;	/* ÔòËµÃ÷¹Ø¼ü×Ö²»´æÔÚ */
	}
	return SUCCESS;
}

int main()
{
	int arr[HASHSIZE]={12,67,56,16,25,37,22,29,15,47,48,34};
	int i,p,key,result;
	HashTable H;

	key=39;

	InitHashTable(&H);
	for(i=0;i<m;i++)
		 InsertHash(&H,arr[i]);
	
	result=SearchHash(H,key,&p);
	if (result)
		printf("²éÕÒ %d µÄµØÖ·Îª£º%d \n",key,p);
	else
		printf("²éÕÒ %d Ê§°Ü¡£\n",key);

	for(i=0;i<m;i++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("²éÕÒ %d µÄµØÖ·Îª£º%d \n",key,p);
	}

	return 0;
}
