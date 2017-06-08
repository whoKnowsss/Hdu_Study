#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char *ch;
    int length;
}HString;
int StrAssign(HString *T, char *chars)   //生成一个其值等于chars的串
{
    if(T->ch)
    	{
    	//	free(T->ch);
    		T->ch=NULL;
    		T->length=0;
    	}
    if(!chars) return 0;
    if (!(T->ch=(char*)malloc((strlen(chars)+1)*sizeof(char)))) return 0;
    strcpy(T->ch,chars);
    T->length=strlen(chars);
    return 1;
}
int StrLength(HString S)    //返回S的元素个数，称为串的长度
{
    return S.length;
}
int StrCompare(HString S, HString T)
//若s>t,则返回值>0;若想等，=0；若s<t,返回<0
{
    int i;
    for(i = 0; i < S.length && i < T.length; i++)
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;

}
int ClearString(HString *S)
{
    //将s清为空串
    if (S->ch)
    {
        free(S->ch);
        S->ch = NULL;
    }
    S->length = 0;
    return 1;
}
int Concat(HString *T, HString s1, HString s2)
{
    //用T返回s1和s2联结而成的新串
    if (T->ch!=NULL)
        free(T->ch);  //释放旧空间
    if (!(T->ch = (char *)malloc((s1.length + s2.length) * sizeof(char))))
        exit (0);
    T->length = s1.length + s2.length;
    int i = 0;
    for(i = 0; i < s1.length; i++)
        *(T->ch + i) = s1.ch[i];
    for(i; i - s1.length < s2.length; i++)
        *(T->ch + i) = s2.ch[i - s1.length];
    return 1;

}


int SubString(HString *sub, HString s, int pos, int len)
{
    //用sub返回串s的第pos个字符起长度为len的字串
    // 其中，1<=pos<=StrLength(s)且0<=len<=StrLength(s)-pos+1
    if (pos < 1 || StrLength(s) < pos || len < 0 || StrLength(s) - pos + 1 < len)
        return 0;
    if(sub->ch)
        free(sub->ch);
    if(!len)
    {
        sub->ch = NULL;
        sub->length = 0;
    }
    sub->ch=(char*)malloc(sizeof(char)*(len+1));
    for (int i = 0; i < len; ++i)
    {
        /* code */
       sub->ch[i] = s.ch[pos - 1 + i];
    }
    sub->ch[len]='\0';
    sub->length = len;
    return 1;
}
void printStr(HString s)
{
  printf("%s\n",s.ch );
}
int main()
{
    HString s1,s2,s3;
    char s[]="12345";
    StrAssign(&s1, s);
    SubString(&s2,s1,2,2);
    printStr(s1);printStr(s2);
    printf("%d\n", StrLength(s2) );
}

