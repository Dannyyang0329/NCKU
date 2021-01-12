void add(char a[], char b[], char res[])
{
	int a_len=strlen(a)-1, b_len=strlen(b)-1, cnt=0;

	for(cnt=0;a_len>=0 || b_len>=0;a_len--,b_len--,cnt++)
	{
		if(res[cnt] != '1') res[cnt] = '0';

		int plus;

		if(a_len < 0) plus = b[b_len]-'0';
		else if(b_len < 0) plus = a[a_len]-'0';
		else plus = (a[a_len]-'0')+(b[b_len]-'0');

		if(res[cnt]+plus > '9') res[cnt]+=(plus-10), res[cnt+1]='1';
		else res[cnt]+=plus;
			
	}

	if(res[cnt] != '1') res[cnt] = '\0';
	else res[++cnt] = '\0';

	int r_len=strlen(res)-1;
	for(int i=0;i<(r_len+1)/2;i++) res[i] ^= res[r_len-i] ^= res[i] ^= res[r_len-i];
}
