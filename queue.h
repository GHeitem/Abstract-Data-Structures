#pragma once
#define MAX_Q 100
#define OK 0
#define UNDER -1
#define OVER 1
typedef void * BaseType;

class queue
{
	BaseType elements[MAX_Q];
	unsigned sizel,head,tail,N;

public:
	int error;
	queue(void);
	void init(unsigned);
	void put(BaseType);
	void get(BaseType*);
	void read(BaseType*);
	int empty();
	int full();
	~queue(void);
};

