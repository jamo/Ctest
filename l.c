#include <stdlib.h>
#include <stdio.h>

typedef struct dList {
  int x;
  struct dList *next;
  struct dList *prev;
} dList;


dList* insertElementD(dList *L, dList *p, int value){
  dList *newdList = malloc(sizeof(dList));
  newdList->x=value;
  if (L == NULL){
    newdList->next = NULL;
    L=newdList;
  } else {
    newdList->prev = p;
    newdList->next = p->next;
    p->next = newdList;
  }
  return L;
}

int printElementsD(dList *L){
  if (L == NULL){
    return 4;
  }
  dList *tmp;
  tmp = L;
  while (tmp != NULL){
    printf("%d\n",tmp->x );
    tmp = tmp->next;
  }
  return 0;
}
/* Value
   Previous
   Next
*/
dList* createElem(int value, dList *pr, dList *nx){
  dList *newdList = malloc(sizeof(dList));
  newdList->x = value;
  newdList->prev = pr;
  newdList->next = nx;
  return newdList;
}

dList* createElemNo(int value){
  return createElem(value, NULL,NULL);
}

dList* deleteElementD(dList *L, dList *p){
  if (L==NULL){
    return NULL;
  }
  if (L==p){
    return L->next;
  }

  if (p->prev != NULL){
    p->prev->next = p->next;
  }
  if (p->next != NULL){
    p->next->prev = p->prev;
  }
  free(p);
  return L;
}

dList* getMin(dList *L){
  dList *min = L;
  dList *tmp = L;
  while (tmp != NULL){
    if (min->x > tmp->x){
      min = tmp;
    }
    tmp = tmp->next;
  }
  return min;
}

dList* clone(dList *node){
  return createElem(node->x, node->prev, node->next);
}

void swap(dList *eka, dList *toka){
  int tmp = eka->x;
  eka->x = toka->x;
  toka->x = tmp;
}

int orderListD(dList *L){
  dList *permHead = L;
  dList *ulompi = L;
  while (ulompi != NULL){
    dList *sisempi = ulompi;
    while (sisempi!=NULL){
      if (ulompi->x > sisempi->x){
        if (ulompi== permHead){
          permHead=sisempi;
        }
        swap(ulompi,sisempi);
      }
      sisempi = sisempi->next;
    }
    ulompi = ulompi->next;
  }
  return 0;
}

dList* mergeListsD(dList *L1, dList *L2){
  dList *L3 = NULL;

  if (L1 != NULL && L2 == NULL){
    L3 = L1;
    return L3;
  }

  if (L1 == NULL && L2 != NULL){
    L3 = L2;
    return L3; //(piti tallentaa L3 kasaan)
  }
  if (L1 == NULL && L2 == NULL){
    return NULL;
  }

  if (L1 != NULL){
    L3 = L1;
  }
  if (L2 != NULL && (L2->x > L1->x)){
    L3 = L2;
  }
  if ((L1 != NULL && L2 != NULL) && ( L1->x == L2->x )){
    int sum2 = (L1->x) + (L2->x);
    L3 = createElem(sum2, NULL, NULL);
    L1=L1->next;
    L2=L2->next;
  }

  dList *permHead = L3;

  while (L1!=NULL || L2!=NULL){
    dList *tmp = NULL;
    int sum = 0;
    if (L1!=NULL){
      tmp = L1;
    }
    if( L2!=NULL && (L1!=NULL || (L2->x < L1->x))){
      tmp = L2;
    }
    if ((L1 != NULL && L2 != NULL)&&(L1->x == L2->x) ){
      sum = (L1->x) + (L2->x);
      tmp = createElem(sum, L3, NULL);
    }

    L3->next = createElem(tmp->x, tmp->prev, tmp->next);

    L3=L3->next;
    if (sum){
      L1 = L1->next;
      L2 = L2->next;
    } else if(tmp==L1){
      L1=L1->next;
    } else if (tmp == L2){
      L2 = L2->next;
    }

  }
  return permHead;
}


int main(){
  dList *root = createElemNo(3);

  insertElementD(root, root, 6);
  insertElementD(root, root, 4);
  insertElementD(root, root, 9);
  insertElementD(root, root, 19);

  dList *other = createElemNo(3);


  insertElementD(other, other, 612);
  insertElementD(other, other, 42);
  insertElementD(other, other, 91);
  insertElementD(other, other, 1);



  orderListD(root); //!
  orderListD(other); //!
  dList *asd =  mergeListsD(root,other);
  //orderListD(asd);
  printElementsD(asd);
  return 0;
}