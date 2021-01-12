char* reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[])
{
    static char result[300];

    int cnt=0;

    for(int i=0;i<strlen(author);i++, cnt++) result[cnt] = author[i];
    result[cnt]=',', result[++cnt]=' ', result[++cnt]='"', cnt++;

    for(int i=0;i<strlen(title);i++, cnt++) result[cnt] = title[i];
    result[cnt]=',', result[++cnt]='"', result[++cnt]=' ', cnt++;

    for(int i=0;i<strlen(conference);i++, cnt++) result[cnt] = conference[i];
    result[cnt]=',', result[++cnt]=' ', cnt++;

    for(int i=0;i<strlen(location);i++, cnt++) result[cnt] = location[i];
    result[cnt]=',', result[++cnt]=' ', cnt++;

    for(int i=0;i<strlen(date);i++, cnt++) result[cnt] = date[i];
    result[cnt]=',', result[++cnt]=' ', cnt++;

    for(int i=0;i<strlen(ppdoi);i++, cnt++) result[cnt] = ppdoi[i];
    result[cnt]='.', result[++cnt]='\0';

    return result;
}
