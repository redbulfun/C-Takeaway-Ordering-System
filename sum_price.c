#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

bool sumPrice(struct order* head, struct recipe* head_r,int c, double* d)
{
	head->sum_price = 0;
	while (head_r != NULL)
	{
		head->sum_price = head->sum_price + head_r->price*head_r->num*head_r->sale_discount;
		head_r = head_r->next;
	}
	head->sum_price = head->sum_price * d[c];
	return true;
}
