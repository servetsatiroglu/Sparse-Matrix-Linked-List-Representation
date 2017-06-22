/*	Kullanýlan	Matris
	|	3	5	0	|
	|	0	0	2	|
	|	0	4	0	|
	|	2	0	3	|	
*/
#include <iostream>

using namespace std;

class nodes{
public:
	int totalr;			//number of rows
	int totalc;			//number of coloumns
	int rno;			//row id
	int cno;			//coloumn id
	int value;			//node value
	
	void headf(nodes*headnode, nodes* frow, const int& tr, const int& tc, nodes* fcoloumn);
	void rheadf(nodes* rowhead, nodes* nrow, const int& nr, nodes* rnode);
	void cheadf(nodes* colhead, nodes* nnode, const int& nc, nodes* ncolounm);
	void pathf(nodes* state, const int& nr, const int& nc, const int& val, nodes* nextcolnode, nodes* nextrownode);
	void shortestpath(nodes* rhead,nodes* start,nodes* dest);

	nodes* head;		//main head node
	nodes* rhead;		//rows headers
	nodes* chead;		//coloumns headers
	nodes* nrow;		//the next node in the same row
	nodes* ncol;		//the next node in the same coloumn
};

void nodes::headf(nodes* headnode ,nodes* frow, const int& tr, const int& tc, nodes* fcoloumn){
	headnode->rhead = frow;					//first head row assignment
	headnode->totalr = tr;					//number of rows assignment
	headnode->totalc = tc;					//number of coloumns assignment
	headnode->chead = fcoloumn;				//first head coloumn assignment
}

void nodes::rheadf(nodes* rowhead,nodes* nrow, const int& nr, nodes* frnode){
	rowhead->rhead = nrow;					//the next row head
	rowhead->rno = nr;						//number of row
	rowhead->nrow = frnode;					//the first node in this row
}

void nodes::cheadf(nodes* colhead,nodes* fcnode, const int& nc, nodes* ncolounm){
	colhead->ncol = fcnode;					//The first node in this coloumn
	colhead->cno = nc;						//number of coloumn
	colhead->chead = ncolounm;				//the next coloumn head
}

void nodes::pathf(nodes* state, const int& nr, const int& nc, const int& val, nodes* nextcolnode, nodes* nextrownode){
	state->rno = nr;						//number of row
	state->cno = nc;						//number of coloumn
	state->value = val;						//value
	state->ncol = nextcolnode;				//the next of coloumn node
	state->nrow = nextrownode;				//the next of row node
}

int _tmain(int argc, _TCHAR* argv[])
{
	nodes* head		= new nodes;
	
	nodes* rowhead0 = new nodes;
	nodes* rowhead1 = new nodes;
	nodes* rowhead2 = new nodes;
	nodes* rowhead3 = new nodes;
	nodes* colhead0 = new nodes;
	nodes* colhead1 = new nodes;
	nodes* colhead2 = new nodes;

	nodes* node0 = new nodes;
	nodes* node1 = new nodes;
	nodes* node2 = new nodes;
	nodes* node3 = new nodes;
	nodes* node4 = new nodes;
	nodes* node5 = new nodes;

	nodes obj;
	
	obj.headf(head,rowhead0,4,3,colhead0);
	
	obj.rheadf(rowhead0, rowhead1, 0, node0);	//row heads definition
	obj.rheadf(rowhead1, rowhead2, 1, node2);
	obj.rheadf(rowhead2, rowhead3, 2, node3);
	obj.rheadf(rowhead3, NULL, 3, node4);

	obj.cheadf(colhead0, node0, 0, colhead1);	//column heads definition
	obj.cheadf(colhead1, node1, 1, colhead2);
	obj.cheadf(colhead2, node2, 2, NULL);

	obj.pathf(node0, 0, 0, 3, node4, node1);	//nodes definition
	obj.pathf(node1, 0, 1, 5, node3, NULL);
	obj.pathf(node2, 1, 2, 2, node5, NULL);
	obj.pathf(node3, 2, 1, 4, NULL, NULL);
	obj.pathf(node4, 3, 0, 2, NULL, node5);
	obj.pathf(node5, 3, 2, 3, NULL, NULL);

	cout << node0->nrow->ncol->value << endl;
	cout << node0->ncol->nrow->value << endl;

	return 0;
}

