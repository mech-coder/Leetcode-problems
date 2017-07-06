/*******************/

#include <stdio.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

void print_list(ListNode *list)
{
    ListNode *pNode = list;

    while(pNode){
        printf("%d ", pNode->val);

        pNode = pNode->next;

        if(pNode){
            printf(" -> ");
        }else{
            printf("\n");
        }
    }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if( l1 == NULL || l2 == NULL){
        return NULL;
    }

    int num1 = 0;
    int num2 = 0;

    ListNode *tmpp = l1;
    int w = 1;

    while(tmpp){
        num1 = num1 + tmpp->val * w ;
        tmpp = tmpp->next;
        w *= 10;
    }

    tmpp = l2;
    w = 1;

    while(tmpp){
        num2 = num2 + tmpp->val * w ;
        tmpp = tmpp->next;
        w *= 10;
    }

    int sum = num1 + num2;
    int tmpi = sum;

    ListNode *result = new ListNode(tmpi % 10);
    tmpi = tmpi / 10;
    tmpp = result;

    while(tmpi){
        tmpp->next = new ListNode(tmpi % 10);
        tmpi = tmpi / 10;
        tmpp = tmpp->next;
    }

    return result;
}

int main()
{
    ListNode *L1 = new ListNode(2);
    L1->next = new ListNode(4);
    L1->next->next = new ListNode(3);

    ListNode *L2 = new ListNode(5);
    L2->next = new ListNode(6);
    L2->next->next = new ListNode(4);


    ListNode *result = addTwoNumbers(L1, L2);

    print_list(L1);
    print_list(L2);
    print_list(result);


    return 0;
}
