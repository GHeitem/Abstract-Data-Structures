#include "stack.h"
#include <memory.h>
#include <cstdlib>

stack::stack()
{
	this->sizel=0;
	this->N=0;
	this->ptr=0;
};
void stack::init(unsigned s){
	sizel=s;
	elements[ptr]=(BaseType)calloc(1,s);
};
void stack::put(BaseType el){
	if (error!=OVER){
	this->elements[++ptr]=(BaseType)calloc(1, this->sizel);
	if (this->elements[ptr]){
		memcpy(this->elements[ptr],el,this->sizel);
		N++;
	}else
	{
		error=OVER;
	};
	};
};
void stack::get(BaseType *el){
	if (!empty()&&(error!=UNDER)){
		if(el!=NULL){
		memcpy(el,elements[ptr],sizel);
		}
		free(elements[ptr--]);
		N--;
	}else{
		error=UNDER;
	};
}
void stack::read(BaseType *el){
	if (!empty()&&(error!=UNDER)){
		memcpy(el,elements[ptr],sizel);
	}else{
		error=UNDER;
	};
}
int stack::empty(){
	return N==0;
};
stack::~stack(void)
{
	while(!empty()){
		get(NULL);
	};
}
