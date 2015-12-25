#include "queue.h"
#include <cstdlib>
#include <memory.h>

queue::queue(void)
{
	head=1;
	tail=0;
	N=0;
	error=OK;
};

void queue::init(unsigned s){
	sizel=s;
}
#define NEXT(a) (a+1)%MAX_Q
void queue::put(BaseType el){
	if (!full()&&(error!=OVER)){
		elements[tail=NEXT(tail)]=(BaseType)malloc(sizel);
		if (elements[tail]){
		memcpy(elements[tail],el,sizel);
		N++;
		};
	}else{
		error = OVER;
	};
}
void queue::read(BaseType *el){
	if (!empty()&&(error!=UNDER)){
		if(el)
			memcpy(el,elements[head],sizel);
	}
	else
	{
		error=UNDER;
	};
};
void queue::get(BaseType *el){
	if (!empty()&&(error!=UNDER)){
	read(el);
	free(elements[head]);
	head=NEXT(head);
	N--;
	}else
	{
		error=UNDER;
	};
};
int queue::empty(){
	return N==0;
};
int queue::full(){
	return N==MAX_Q-2;
};
queue::~queue(void)
{
	while(!empty()){
		get(NULL);
	};
}
