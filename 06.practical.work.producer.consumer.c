#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10


typedef struct
{
	char type; //fried chicken : 0, french fries : 1
	int amount; //piece, weight
	char unit; //piece : 0, gram : 1
}item;

item buffer[BUFFER_SIZE];
int first =0;
int last=0;

void produce(item *i){

	while((first+1) % BUFFER_SIZE == last)
	{	
	// do nothing -- no free buffer item
	}

	memcpy(&buffer[first],i, sizeof(item));
	first = (first+1) % BUFFER_SIZE;
}

item *consume()	
{
	item *i = (item *)malloc(sizeof(item));
	while(first == last)
	{	
	// do nothing -- no free buffer item
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last+1) % BUFFER_SIZE;
	return i;
}

int main(){
        item a;
        a.type = '1';
        a.amount = '0';
        a.unit = '1';
        item b;
        b.type = '0';
        b.amount = '1';
        b.unit = '0';
        printf("Item a: type=%c amount=%d unit=%c\n",a.type,a.amount,a.unit);
        produce(&a);
        printf("first=%d, last=%d\n, first,last");
        printf("Item b: type=%c amount=%d unit=%c\n",b.type,b.amount,b.unit);
        produce(&b);
        printf("first=%d, last=%d\n, first,last");
        consume();
        printf("item consumed:\n first %d last : %d\n", first, last);
}
        
        
        
