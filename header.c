#include <stdio.h>
#include <json-c/json.h>
#include <string.h>
#include "header.h"
#define FILE_NAME "planetarySystem.json"


//Quick greeting function
void greeting() {
    printf("Welcome to the Solar System!\n\n There are nine planets to be explored! \n\n");
}

//Takes user input to get the name
//Here Is where I believe my errors start.  I asked around (Erin, Aidan, Andrew, and Rian) and couldn't find a resolution.  
//Erin thought maybe an empty array of char might solve it, Aidan explained how he used malloc() and Andrew didn't respond in time...
void getName() {
    char name[10] = " ";
    printf("What's your name?");
    scanf("%s", name);
	printf("Hi there, %s! My name is Eliza, I am an old friend of Alexa", name)
    printf("Let's go on a space adventure!\n");
}

//Finds out whether the user wants a random planet or nah... Calls function accordingly
void getPlanet() {
    char YesorNo[20] = " ";
    printf("Would you like me to randomly choose a planet for you to explore? (Y or N)", &reply);
    scanf("%s", YesorNo);
    if(YesorNo == 'Y' | YesorNo == 'y') {
        randPlanet();
    }
    else if(YesorNo == 'N' | YesorNo == 'n') {
    	userPlanet();
	}
    else {
        printf("Hmmm, I didn't get that.  Let's try again.\n");
        getPlanet();
    }
}

//Gives a random planet...Had to go with a joke
void randPlanet() {
	printf("Traveling to Uranus... \n");
    printf("Ah, it is very dark here! \n");
}

//Takes user input to travel to a planet from our JSON file
void userPlanet() {
    printf("Ok you choose one.\n Name a planet you would like to visit:");
    char planet[20] = " ";
    scanf("%s", planet);
    printf("Great! Enjoy exploring %s !", planet);
}

//Variables that make up our planet all wrapped up in a structure.
struct planet {
    char *name;
    char *descrip;
};

//Thank you for the JSON parse video
void parseJson() {
    FILE *fp;

    char buffer[2048];
    struct json_object *parsed_json;
    struct json_object *name;
    fp = fopen(FILE_NAME, "r");
    fread(buffer, 2048, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "name", &name);

    printf("Thanks for visting my %s\n",json_object_get_string(name));
}