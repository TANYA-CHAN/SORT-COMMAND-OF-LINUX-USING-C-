#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include<string.h>
#define SIZE 30
#define N 35
#define LEN 31
// USED TO SORT DATA GIVEN IN FILE NAMESORT().TXT IN ALPHABETICAL ORDER
int sort(void)
{
char name[LEN][SIZE]; /* Data records */
char hold[LEN] ;
int i,j ; /* indices of array */
int last ; /* index of last item in array */
FILE *fpPtr; /* fpPtr = sorted_file.txt pointer */
/*
copy file contents to array
*/

/* fopen opens file; exits program if file cannot be opened */
if ( ( fpPtr = fopen( /* "sorted_file.txt" */ "namesort.txt", "r" ) ) == NULL ) {
printf( "File could not be opened" );
} /* End if */

/* Read records from file */
else {
/* While not end of file */
printf("\n\nThe names in original order are\n\n"); /*{ outside loop }*/
for(i = 0 ; !feof( fpPtr ) ; i++ )
{fscanf( fpPtr, "%s", name[i] );
printf("%s", name[i]) ; /*{ inside loop }*/
} /* End while */
last = i - 1 ;
fclose( fpPtr ); /* fclose closes the file */
/*sort*/
for (i = last ; i > 0 ; i--)
for (j = 1 ; j <= i ; j++)
if (strcmp(name[j],name[j - 1]) < 0) {
strcpy(hold,name[j]) ;
strcpy(name[j],name[j - 1]) ;
strcpy(name[j - 1],hold) ;
}
/*write array to output */
printf("\n\nThe names in alphabetical order are\n\n") ;/*outerloop*/
for (i = 0 ; i <= last ; i++)
{printf("- %s",name[i]);} /* End else */
 /* Indicates that the program terminated successfully */
}
return 0;
getch();
}
// USED TO SORT DATA IN DIFFERENT COLUMNS FROM FILE SORTED.TXT AND STORE IT IN SORTEDO.TXT
int ksort()
{
int i, c, d;
FILE *fp;
float a[N];
float b[N];
float swap;
fp=fopen("sorted.txt", "r");
{
 for(i=0; i<N; i++)
  fscanf(fp,"%f %f", &a[i], &b[i]);
}
 for(c=0; c<(N-1); c++)
 {
  for(d=0; d<(N-c-1); d++)
  {
   if(a[d]>a[d+1])
   {
    swap=a[d];
    a[d]=a[d+1];
    a[d+1]=swap;
   }
   if(b[d]>b[d+1])
   {
    swap=b[d];
    b[d]=b[d+1];
    b[d+1]=swap;
   }
  }
 }
  for(c=0; c<N; c++)
  printf("%8.2f  %8.2f\n", a[c], b[c]);

fclose(fp);
return 0;
getch();
}

//USED TO SORT NUMERIC DATA ENTERED BY THE USER IN ASCENDING AND DESCENDING ORDER AND STORES IT IN RANDOM.TXT
int nrsort()                        //default function for call
{
	 FILE* fptr;

    // creating a file "random.txt" in "write" mode
    fptr = fopen("random.txt", "w");
    fopen("random.txt","r");
    int i;
    if (fptr == NULL) {
        printf("ERROR");
        exit(1);
    }
	int a[100],n;
	printf("Array size: ");
        scanf("%d",&n);
        printf("Elements: ");
      for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);/*fscanf(fptr,"%d", &a[i]);*/
    }
	for (int i = 0; i < n; i++)                     //Loop for ascending ordering
	{
		for (int j = 0; j < n; j++)             //Loop for comparing other values
		{
			if (a[j] > a[i])                //Comparing other array elements
			{
				int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;             //storing last value
			}
		}
	}
	printf("\n\nAscending : ");                     //Printing message
	for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
	{
		printf("%d ", a[i]);
		fprintf(fptr, "%d \t ",a[i]);
	}
	for (int i = 0; i < n; i++)                     //Loop for descending ordering
	{
		for (int j = 0; j < n; j++)             //Loop for comparing other values
		{
			if (a[j] < a[i])                //Comparing other array elements
			{
				int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;             //storing last value
			}
		}
	}
	printf("\n\nDescending : ");                    //Printing message
	for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
	{
        printf("%d ", a[i]);
		fprintf(fptr, "%d \t  ",a[i]);                 //Printing data
	}
    fclose(fptr);
	return 0;          //returning 0 status to system
}
// max length of a line in the file
#define NUM_NUMBERS 61
void SelectionSort(int v[], int n)
{
    int iMin;
    for(int i=0;i<n-1;i++)
    {
        iMin=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[iMin])
            {
                iMin=j;
            }
        }
        int aux=v[i];
        v[i]=v[iMin];
        v[iMin]=aux;
    }
}
//TAKES THE DATA ENTRED BY THE OTHER AND STORES IT IN A SEPERATE A THIRD FILE
int osort()
{
    FILE *f, *f2;
    int inteiros[NUM_NUMBERS], number, i=0;
    f=fopen("In1.txt", "r");
    if(f==NULL)
        printf("Error\n");

    while(i <NUM_NUMBERS && fscanf(f, "%d",&number)==1)
    {
        inteiros[i]=number;
        i++;
    }
    printf("Number are read : %d \n", i);
    fclose(f);
    SelectionSort(inteiros, NUM_NUMBERS);
    f2=fopen("In2.txt", "w");
    for(int i=0;i<NUM_NUMBERS;i++)
    {
        fprintf(f2, "%d\n", inteiros[i]);

    }
    printf("\nContents of In1.txt are sorted and copied to In2.txt\n");
    fclose(f2);
    return 0;
}
/*C Program to Reverse the Contents of a File and Print it*/
long count_characters(FILE *);
// count the total number of characters in the file that *fp points to
long count_characters(FILE *f)
{
    fseek(f, -1L, 2);
    long last_pos = ftell(f); // returns the position of the last element of the file
    last_pos++;
    return last_pos;
}
//STORES THE DATA ENTERED IN THE FILE REVERSE.TXT IN REVERSE ORDER AND SORTS IT IN THE SAME FILE ( Data can be changed and the program would still perform the same operations. )
int rsort()
{
      FILE *fp;
      char ch;
      int i,pos;
      fp=fopen("reverse.txt","r");
      if(fp==NULL)
      {
            printf("File does not exist..");
      }
      printf("The FILE has been opened...\n");
  long int cnt = count_characters(fp); // to count the total number of characters inside the source file
        fseek(fp, -1L, 2);  // makes the pointer fp1 to point at the last character of the file
        printf("Number of characters to be copied %ld\n", ftell(fp));
        printf("total number of characters inside the source file : %ld",cnt);
      fseek(fp,0,SEEK_END);
      pos=ftell(fp);
      printf("\nCurrent postion is %d\n",pos); // tells the current position of the file pointer
      i=0;
      while(i<pos)
       {
            i++;
            fseek(fp,-i,SEEK_END);
            printf("%c",fgetc(fp));
            ch=fgetc(fp);
            printf("%c",ch);
      }printf("\n\n**File copied successfully in reverse order**\n");
      return 0;
}
//USED IN USORT() FOR STRING OPERATIONS
int removeDuplicate(void)
{
    char str[100];
  	int i, j, k;

  	printf("\n Please Enter any String :  ");
  	fflush(stdin);
  	gets(str);

  	for(i = 0; i < strlen(str); i++)
  	{
  		for(j = i + 1; str[j] != '\0'; j++)
  		{
  			if(str[j] == str[i])
			{
  				for(k = j; str[k] != '\0'; k++)
				{
					str[k] = str[k + 1];
				}
 			}
		}
	}

	printf("\n The Final String after Removing All Duplicates = %s ", str);
	FILE *fp = fopen("forusort.txt","w");
	fseek(fp,0,SEEK_SET);
	fputs(str,fp);
	fclose(fp);
  	return 0;
}
//USED IN USORT() FOR INTEGER DATA OPERATIONS
int remove_duplicate_elements(void)
{
    int a[20], i, j, k, n;
    /* Input string from user */
    printf("\nEnter array size: ");
    scanf("%d", &n);

    printf("\nEnter %d array element: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nOriginal array is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }

    printf("\nNew array is: ");
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; )
        {
            if(a[j] == a[i])
            {
                for(k = j; k < n; k++)
                {
                    a[k] = a[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    FILE *fp = fopen("forusort2.txt","w"); //sorting the output
	fseek(fp,0,SEEK_SET);
	for(int z=0;z<n;z++)
	{
		fprintf(fp,"%d",a[z]);
	}
	fclose(fp);
    return 0;
}
//TO REMOVE DUPLICATE INTEGRER ENTERED BY THE USER IN AN ARRAY AND STORE THEM IN FILE FORUSORT.TXT
//TO REMOVE DUPLICATE CHARACTERS ENTERED IN A STRNG BY THE USER AND STORE THEM IN FILE FORUSORT2.TXT
int usort()
{
		removeDuplicate();
		remove_duplicate_elements();
		printf("The output is successfully saved in files :-\n 1)forusort.txt & 2)forusort2.txt\n");
		return 0;
}
// max length of a line in the file
#define SIZEE 65
void swap(int *xp, int *yp) //USED IN NSORT()
	{
	    int temp = *xp;
	    *xp = *yp;
	    *yp = temp;
	}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
           {
               swap(&arr[j], &arr[j+1]);
           }
}
//SORTS NUMERIC DATA IN THE FILES SORTED.TXT AND STORES THE RESULT IN SORTEDO.TXT USING BUBBLE SORT,( data in the file could be changed accordingly for testing and still the operations will work.)
int nsort()
{
	int arr[65], i=0, k, step=115, f_r=0,x,c;
	FILE *fp=fopen("sorted.txt","r");
	while(fscanf(fp,"%d",&x)==1)
	{
		//printf("%d ",x);
		arr[i]=x;
		i++;
		c=i;
	}
	printf("Printing unsorted numbers \n");
	for(int i=0;i<c;i++)
	{
		printf("%d\n",arr[i]);
	}
	fclose(fp);
// Sorting Routine Begins , function call
	bubbleSort(arr,c);
// Sorted Output
        printf("\nPrinting Sorted Numbers\n");
    for (k=0; k!=c;k++)
    {
        printf("%d\n", arr[k]);
    }
        printf("Total number of steps is %d", step);
        getchar();
 //Printing Output to File
    FILE *fw=fopen("sortedo.txt", "w");
    f_r=0;
        while(f_r!=c)
            {
                fprintf(fw, "%d\n", arr[f_r]);
                ++f_r;
            }

    fclose(fw);
    return 0;
    getchar();
}
/*C program to remove empty lines from a file.*/
// max length of a line in the file
#define BUFFER_SIZE 1000

/* Function declarations */
int  isEmpty(const char *str);
void removeEmptyLines(FILE *srcFile, FILE *tempFile);
void printFile(FILE *fptr);
// REMOVE EMPTY LINES FROM A FILE REMOVE-BLANKS.TXT AND TSORE THE OUTPUT IN REMOVE-BLANKS2.TXT
int bsort()
{
    FILE *srcFile;
    FILE *tempFile;

    char path[100];


    /* Input file path */
    printf("Enter file path: ");
    scanf("%s", path);


    /* Try to open file */
    srcFile  = fopen(path, "r");
    tempFile = fopen("remove-blanks2.txt", "w");


    /* Exit if file not opened successfully */
    if (srcFile == NULL || tempFile == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }
    printf("\nFile contents before removing all empty lines.\n\n");
    printFile(srcFile);
    // Move src file pointer to beginning
    rewind(srcFile);
   // Remove empty lines from file.
    removeEmptyLines(srcFile, tempFile);
    /* Close all open files */
    fclose(srcFile);
    fclose(tempFile);
    /* Delete src file and rename temp file as src */
    remove(path);
    rename("remove-blanks.txt", path);
    printf("\n\n\nFile contents after removing all empty line.\n\n");

    // Open source file and print its contents
    srcFile = fopen(path, "r");
    printFile(srcFile);
    fclose(srcFile);

    return 0;
}

/*Print contents of a file.*/
void printFile(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
        putchar(ch);
}

/*
 * Checks, whether a given string is empty or not.
 * A string is empty if it only contains white space
 * characters.
 *
 * Returns 1 if given string is empty otherwise 0.
 */
int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);

        // Check non whitespace character
        if(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}

/*Function to remove empty lines from a file. */
void removeEmptyLines(FILE *srcFile, FILE *tempFile)
{
    char buffer[BUFFER_SIZE];

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
    {
        /* If current line is not empty then write to temporary file */
        if(!isEmpty(buffer))
            fputs(buffer, tempFile);
    }
}
//algorithm
/*Open source file to remove empty lines, store its reference to a FILE pointer srcFile.
Create a temporary file remove-blanks.txt and store its reference to tempFile.
Read single line from srcFile and store to some variable say buffer.
Write line buffer to tempFile if it is not an empty line. A line is said to be empty if it contains only whitespace characters.
Repeat step 3-4 till end of source file.
Close both files to save changes.
Delete source file and rename tempFile with same name as of source file.*/

int main() // Driver code
{
    int n;
    while(1)
    {
    printf("\n::::::SORT OPERATIONS MENU:::::\n");
    printf(" 1. sort: \n 2. -n: \n 3. -nr: \n 4. -r: \n 5. -k: \n 6. -u : \n 7. -o: \n 8. -b: \n 9. Exit \n");
    printf("\nEnter your choice:");
    scanf("%d",&n);
     switch(n)
    {
        case 1: sort();
                break;
        case 2: nsort();
                break;
        case 3: nrsort();
                break;
        case 4: rsort();
                break;
        case 5: ksort();
                break;
        case 6: usort();
                break;
        case 7: osort();
                break;
        case 8: bsort();
                break;
        case 9: exit(0);
                break;
        default:printf("Sorry, wrong option!!\n");
                break;
    }
    }
    return 0;
    getch();
}
