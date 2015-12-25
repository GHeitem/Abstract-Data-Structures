#pragma once
#define MAX 100
typedef void * BaseType;
typedef BaseType stackMem[MAX];
typedef unsigned ptrel;
#define OK 0
#define UNDER -1
#define OVER 1
class stack
{private:
	stackMem elements;
	unsigned N,sizel;
	ptrel ptr;

public:
	int error;
	stack();
	void init(unsigned);
	void put(BaseType);
	void get(BaseType *);
	void read(BaseType *);
	int empty();
	~stack(void);
};

