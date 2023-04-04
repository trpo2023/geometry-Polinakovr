#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checking(char circle1[], int* p)
{
    int z = *p;

    char str2[13] = "-.0123456789";

    while (circle1[z] == ' ') {
        z++;
    }

    if (circle1[z] == '0') {
        if (circle1[z + 1] != '.') {
            printf("Error \n");
            return 0;
        }
    }

    if (strchr(str2, circle1[z]) == NULL) {
        printf("Error \n");
        return 0;
    }

    while (strchr(str2, circle1[z]) != NULL) {
        z++;
    }

    if (circle1[z] != ' ') {
        printf("Error \n");
        return 0;
    }

    while (circle1[z] == ' ') {
        z++;
    }

    if (circle1[z] == '0') {
        if (circle1[z + 1] != '.' && strchr(str2, circle1[z + 1]) != NULL) {
            printf("Error \n");
            return 0;
        }
    }

    if (strchr(str2, circle1[z]) == NULL) {
        printf("Error \n");
        return 0;
    }

    while (strchr(str2, circle1[z]) != NULL) {
        z++;
    }
	z++;
    while (circle1[z] == ' ') {
        z++;
    }
	while (strchr(str2, circle1[z]) != NULL) {
        z++;
    }

    z++;
    *p = z;
    return 1;
}
struct variables {
	float x;
	float y;
};

struct WKT {
	struct variables point;
	float radius;
};

int main() 
{
	FILE *file;
	file = fopen("circle.txt", "r");
	if (!file) { return 0;}
	char *type;
	char draw[100];
	char draw1[100];
	int z = 7;
	struct WKT j;
	while ((fgets(draw, 100, file)) != 0) 
    {
		strcpy(draw1, draw);
    		type = strtok(draw1, "(");
			if (checking(draw, &z) == 0) 
            {
       			return 0;
			}
    		if (strcmp(type, "circle") == 0) 
            {
      			if ((sscanf(draw, "circle(%f %f, %f)", &j.point.x, &j.point.y, &j.radius)) == 3)
        			printf("circle(%f %f, %f)\n", j.point.x, j.point.y, j.radius);
      			
    		}   
  		}
        
  return 0;
}
