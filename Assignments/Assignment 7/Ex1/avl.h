#ifndef avl_h
#define avl_h

#include "alist_f.h"

template<class T> class AVL;

template<class T> class avlnode
{
    friend class AVL<T>;
public:
    avlnode(T item = 0, int bal = 0, avlnode<T> *left = 0, avlnode<T> *right = 0);
    T getdata(void);
    int getbalance(void);
    avlnode<T> *getleft(void);
    avlnode<T> *getright(void);
    void setdata(T item);
    void setbalance(int bal);
    void setleft(avlnode<T> *pt);
    void setright(avlnode<T> *pt);
private:
    T data;
    int balance;
    avlnode<T> *pt_left;
    avlnode<T> *pt_right;
};

template<class T> class AVL
{
public:
    AVL(void);
    void insert(T item);
    void remove(T item);
    bool find(T item);
    void display(void);



/*************************** TODO *************************/
/*
*   Ex.1 (i) (ii) (iii)
*
*   declarations of your functions
*
*   notes:  you may need to dynamically initialize a list
*           to store the selected elements, and you don't
*           have to worry about the deallocation.
*
*           I chose AList<T> to store the elements, as the
*           provided template shows, since you are supposed
*           to be familiar with it. But in principle, you 
*           can use whichever your favoriate container is, 
*           as long as it works, such as std::vector<T>.
*
*           Besides the functions declared for you, you can 
*           write your own helper function, as long as you 
*           don't change the provided function declarations.
*/
    AList<T>* DFS(void);     
    AList<T>* BFS(void);
    AList<T>* range(T x, T y);

/************************* GOOD LUCK **********************/



private:
/**********************************************/
/*
*   you can declare your helper function here (optional):
*/
    void DFS_Helper(avlnode<T>* avl_node, AList<T>* storage);
    void BFS_find(avlnode<T>* avl_node, AList<T>* storage, int relative_height);
    int BFS_getheight(avlnode<T>* avl_node);
    int max(int a, int b);
    int judge_range(T min, T element, T max);
    
/**********************************************/
    avlnode<T> *root;
    bool mode;
    avlnode<T> *bchild;
    avlnode<T> *bgrandchild;
    /* auxiliary functions for recursive insert, delete and find */
    avlnode<T> *_insert(avlnode<T> *pt, T val);
    avlnode<T> *_delete(avlnode<T> *pt, T val);
    bool _find(avlnode<T> *pt, T val);
    /* operations for single rotations with new balance values pbal and cbal for parent and child, respectively */
    avlnode<T> *rotateleft(avlnode<T> *parent, avlnode<T> *child, int pbal, int cbal);
    avlnode<T> *rotateright(avlnode<T> *parent, avlnode<T> *child, int pbal, int cbal);
    /* auxiliary operation to find the maximum in the left successor tree, swap it with the value in the node pointed to by the first argument, delete this node and propagate balance changes upwards to the start of the search for this maximum; the second pounter is used for recursive descent  */
    avlnode<T> *findswapleft(avlnode<T> *pt_swap, avlnode<T> *here);
    /* alternatively, we can search for the minimum in the right successor tree, swap it with the value in the node pointed to by the first argument and propagate balance changes back upwards; this alternative is not implemented here */
//    avlnode<T> *findswapright(avlnode<T> *pt_swap, avlnode<T> *here);
    void _display(avlnode<T> * pt);
};

#endif /* avl_h */
