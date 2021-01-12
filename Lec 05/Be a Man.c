#include<stdio.h>

int main ()
{
	int year,height,weight,age;
	scanf("%d %d %d", &year, &height ,&weight);
	age = 2020-year+1;
	float bmi =(float) ((int)( (float)weight/height/height*1000000+5 )/10)/10 ;
	printf("Age = %d\n"
	       "Height = %dcm\n"
	       "Weight = %dkg\n"
	       "BMI = %.1f\n", age, height, weight, bmi);

	if(age>36 || age < 19)
	{
		printf("Not a Draftee (age < 19 or age > 36 years old)\n");
		printf("No need to perform Military Service");
	}

	else
	{
		if(bmi>=17 && bmi<=31)
		{
			 printf("Physical Status of Regular Service Draftees\n");
			 if(year <= 1993) printf("1 year of Regular Service");
			 else printf("4 months of Regular Service");
		}

		if( (bmi<17 && bmi>=16.5) || (bmi>31 && bmi<=31.5) )
		{
			printf("Physical Status of Substitute Service Draftees\n");
			if(year <= 1993) printf("Substitute Services");
                        else printf("Replacement Service");
		}

		if(bmi<16.5 || bmi>31.5)
		{
			printf("Physical Status of Military Service Exemption\n");
			printf("Exemption from Military Service");
		}
	}

	return 0;
}
