#include "stive.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void verificareparanteze(char paranteze[],Node *stack_top)
{int i,parantezedeschise=0, parantezeinchise=0;
 for(i=0;i<strlen(paranteze);i++)
  {
      push(&stack_top,i);
      if (paranteze[i]=='(')
            parantezedeschise++;
      else if (paranteze[i]==')')
        parantezeinchise++;

      if (parantezeinchise>0 && parantezeinchise<=parantezedeschise)
       {pop(&stack_top), pop(&stack_top);
       parantezedeschise--;
       parantezeinchise--;
  }

  if (parantezeinchise > parantezedeschise)
    printf("%d ",pop(&stack_top)), parantezeinchise--;

}
while(!isEmpty(stack_top))
        printf("%d ",pop(&stack_top));
}

int main()
{
    Node *stack_top=NULL;
 char paranteze[]=")))(";

  verificareparanteze(paranteze,stack_top);

    return 0;
}
