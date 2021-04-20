#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* D2NGJO;
    D2NGJO= fopen("Bordas","w");
    fprintf(D2NGJO,"Bordas David\nGazdasaginformatikus\nD2NGJO");
    fclose(D2NGJO);
    return 0;
}
