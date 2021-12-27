#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
char predpt[6][7][10] ={ {"NT/T", "i" , "+" , "*" , "(" , ")" , "$" },
{"E" , "TD" , "err", "err", "TD" , "err", "err"},
{"D" , "err", "+TD", "err", "err", "e" , "e" },
{"T" , "FS" , "err", "err", "FS" , "err", "err"},
{"S" , "err", "e" , "*FS", "err", "e" , "e" },
{"F" , "i" , "err", "err", "(E)", "err", "err"}};
// in this e indicates epsilon and err indicates error
void main()
{
char *dataptr(char,char);
char inpstr[20],*temp,stack[25]="$E";
int tos=1,inpp=0,i,j;
printf("Enter the input string(ending with $):");
scanf("%s",inpstr);
printf("Predictive Parse LL(1) Table is:------");
for(i=0;i<6;i++)
{
printf("\n");
for(j=0;j<7;j++)
{
printf("\t%s",predpt[i][j]);
}
}
printf("\nParsing of %s using PredictiveParse LL(1)Table is :",inpstr);
printf("\n STACK\t INPUT\t OUTPUT");
printf("\n%s \t %s \t ",stack,inpstr);
do
{
if(stack[tos]==inpstr[inpp])
{
stack[tos]=' ';
tos--;
inpstr[inpp]=' ';
inpp++;
printf("\n%s \t %s \t (pop)",stack,inpstr);
}
else
{
temp=dataptr(stack[tos],inpstr[inpp]);
printf("temp=%s",temp);
if(strcmp(temp,"err")==0)
{
printf("\n\n UNSUCCESSFUL PARSING.........");
break;
}
else if(strcmp(temp,"e")==0)
{
stack[tos]=' ';
tos--;
printf("\n%s \t %s \t e",stack,inpstr);
}
else
{
strrev(temp);
tos--;
for(i=0;i<strlen(temp);i++)
{
tos++;
stack[tos]=temp[i];
}
printf("\n %s \t %s \t %s",stack,inpstr,strrev(temp));
}
}
}while((stack[tos]!='$')||(inpstr[inpp]!='$'));
if((stack[tos]=='$')&&(inpstr[inpp]=='$'))
printf("\n SUCCESSFUL PARSING.........");
else
printf("\n\n UNSUCCESSFUL PARSING.........");
}
char *dataptr(char sd,char id)
{
int i=0,j,k;
for(j=1;j<6;j++)
{
if((strchr(predpt[j][i],sd))!=0)
break;
}
for(k=1;k<6;k++)
if((strchr(predpt[i][k],id))!=0)
break;
return(predpt[j][k]);
}
