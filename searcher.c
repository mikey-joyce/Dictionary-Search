#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nodestruct{
	int index;
  char letter;
}Node;

//Input Function Prototypes
Node getUserInput();

//Dictionary Function Prototypes
void searchDictionary(Node *, int, char **, int, int);
void freeDictionary(char **, int);

int main(void){
  FILE *fPtr = fopen("words.txt", "r");
  int lines=0;

  //while we are not at the end of the file
  while(!feof(fPtr)){
    //read in the line and add it to total
    //at the end of the loop lines==lines of file
    int temp = fgetc(fPtr);
    if(temp=='\n'){
      lines++;
    }
  }

  //rewind file
  rewind(fPtr);

  //allocate memory for my array of strings
  char **dictionary = (char **)malloc(sizeof(char *)*lines);

  //allocate memory for my strings (none exceed 50 characters the extra 1 is for '\0'
  for(int i=0; i<lines; i++){
    dictionary[i] = (char *)malloc(sizeof(char)*51);
  }

  //read in each line into our dictionary
  for(int i=0; i<lines; i++){
    fscanf(fPtr, "%s\n", dictionary[i]);
  }

  //close file
  fclose(fPtr);
  fPtr=NULL;

  //get required data (next 13 lines of code)
  int flag=1, desiredSize=0, arraySize=0;
  Node *myList=NULL;

  while(flag==1){
    printf("Enter 1 to make an entry, enter anything else to quit:\n");
    scanf("%d", &flag);

    if(flag==1){
      printf("What is the desired size of the word?\n");
      scanf("%d", &desiredSize);

      printf("How many letters will you input?\n");
      scanf("%d", &arraySize);

      //allocate memory for my array of nodes
      myList = malloc(sizeof(Node)*arraySize);

      //populate the array of nodes
      for(int i=0; i<arraySize; i++){
        myList[i] = getUserInput();
      } 
    }

    //if myList exists
    if(myList!=NULL){
      //loop through the list of nodes and print out the data for each one
      for(int i=0; i<arraySize; i++){
        printf("%d: %c\n", myList[i].index, myList[i].letter);
      }

      //search the dictionary and free the list
      searchDictionary(myList, arraySize, dictionary, lines, desiredSize);
      free(myList);
    }
  }

  //free dictionary
  freeDictionary(dictionary, lines);
}

//Input Function
Node getUserInput(){
  int index;
  char letter;
  Node newNode;

  //get input for index and letter
  printf("Enter in the index:\n");
  scanf("%d", &index);

  printf("Enter in the letter:\n");
  scanf(" %c", &letter);

  //store input in a linked list and increment size
  newNode.index = index;
  newNode.letter = letter;

  return newNode;
}

//Dictionary Functions
void searchDictionary(Node *myList, int listSize, char **dictionary, int lines, int desiredSize){
  //count will be used as a counter to see if the nodes within myList mirror
  //the nodes within said string
  int count=0;

  //loop through the dictionary
  for(int i=0; i<lines; i++){
    //always set count to 0 on each iteration
    count=0;
    //if the length of current string is not the same as the desired length
    if((int)strlen(dictionary[i])!=desiredSize){
      //move on to the next iteration
      continue;
    }
    //loop through the list of nodes
    for(int j=0; j<listSize; j++){
      //if they are the same letter at this index (tolower because casing of the letter doesn't matter)
      if(tolower(dictionary[i][myList[j].index])==tolower(myList[j].letter)){
        //increment count because they are the same
        count++;
      }
    }
    //if count is the same size as our list of nodes
    if(count == listSize){
      //this word fits the criteria so print it out
      printf("%s\n", dictionary[i]);
    }
  }
}
//Frees the memory our dictionary holds
void freeDictionary(char **dictionary, int lines){
  //loop through dictionary
  for(int i=0; i<lines; i++){
    //free each string
    free(dictionary[i]);
  }

  //free the outer array
  free(dictionary);
}

