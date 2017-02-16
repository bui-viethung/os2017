#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>
#define BUFFER_SIZE 10

typedef struct{
	char type; //fried chicken : 0, french fries : 1
	int amount; //piece, weight
	char unit; //piece : 0, gram : 1
}item;

item buffer[BUFFER_SIZE];
int first =0;
int last=0;

void produce(item *i){
  while((first+1) % BUFFER_SIZE == last){	
	// do nothing -- no free buffer item
	}
	memcpy(&buffer[first],i, sizeof(item));
	first = (first+1) % BUFFER_SIZE;
}

item *consume()	{
	item *i = (item *)malloc(sizeof(item));
	while(first == last)
	{	
	// do nothing -- no free buffer item
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last+1) % BUFFER_SIZE;
	return i;
}

void prothread(void *param){
item a;
	a.type = '1';
	b.amount = 0;
	c.unit = '1';
item b;
	b.type = '1';
	b.amount = 5;
	b.unit = '1';
item c;
	c.type = '5';
	c.amount = 5;
	c.unit = '1';
  printf("item a:\n Type: %c\n Amount: %d\n Unit: %c\n", a.type, a.amount, a.unit);
	printf("item b:\n Type: %c\n Amount: %d\n Unit: %c\n", b.type, b.amount, b.unit);
	printf("item c:\n Type: %c\n Amount: %d\n Unit: %c\n", c.type, c.amount, c.unit);
  printf("Produce 3 items:\n");
	produce(&a);
	printf("Produce item a: first: %d  last: %d\n", first, last);
	produce(&b);
	printf("Produce item b: first: %d  last: %d\n", first, last);
	produce(&c);
	printf("Produce item c: first: %d  last: %d\n\n", first, last);
	return 0;
}
void conthread(void *param){
	printf("after consume an item:\n");
  consume();
  printf("Consume an item\nFirst:%d Last:%d\n",first,last );
	consume();
	printf("Consume an item\nFirst:%d Last:%d\n",first,last );
}
int main(){
	pthread_t a1,a2;
	pthread_create(&a1,NULL,prothread,NULL);
	pthread_join(a1,NULL);
	pthread_create(&a2,NULL,conthread,NULL);
	pthread_join(a2, NULL);
}

