#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

float distance(float x, float y, float z, float x2, float y2, float z2);
float normalize(float distance, float delta);
bool isValidLine(char* line);
char** getLineVals(char* line, int totVals);
char** getLinesInFile(char* filename, int maxLines);
int getLineCountInFile(char *filename);

int main() {


    int maxLines = 100;
    char** lines = getLinesInFile("points.txt", maxLines);

    FILE *outFile;
    outFile = fopen("calculated.txt", "w+");
    float total = 0.0f;
    for (int i=0; i<getLineCountInFile("points.txt")-1; i++) {
        if (i < getLineCountInFile("points.txt")) {
            char** currentVals = getLineVals(lines[i], 3);
            char** nextVals = getLineVals(lines[i+1], 3);
            float pointDist = distance(
                atof(currentVals[0]), atof(currentVals[1]), atof(currentVals[2]),
                atof(nextVals[0]), atof(nextVals[1]), atof(nextVals[2])
            );
            total += pointDist;

            for (int i=0; i<3; i++) {
                float delta = atof(currentVals[i]) - atof(nextVals[i]);
                float normalized;
                normalized = -1 * normalize(pointDist, delta);
                fprintf(outFile, "%0.4f,", normalized);
            }

            fprintf(outFile, "%0.4f\n", pointDist);
        }
    }
    printf("Total: %0.4f\n", total);
}


int getLineCountInFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    int count = 0;

    if (fp == NULL) {
        printf("Could not open file '%s'\n", filename);
    }

    // For loop for every character in the file until the character is an End Of File (EOF) character
    for (char c = getc(fp); c != EOF; c=getc(fp)) {
        if (c == '\n') {
            count += 1;
        }
    }

    fclose(fp);
    return count + 0;
}

float normalize(float distance, float delta) {
    return (float) (delta / distance);
}

float distance(float x, float y, float z, float x2, float y2, float z2) {
    return (float) sqrt( pow((x-x2),2) + pow((y-y2),2) + pow((z-z2),2) );
}

char** getLinesInFile(char* filename, int maxLines) {
    int BUFSIZE = 1000;
    char** lines = malloc(maxLines * sizeof(char*) * 1000);
    FILE *fp = fopen(filename, "r");

    int count = 0;

    char* line = malloc(BUFSIZE * sizeof(char));
    while (fgets(line, BUFSIZE, fp) != NULL) {

        for (int i=0; i<strlen(line); i++) {
            if (line[i] == '\n') {
                line[i] = '\0';
            }
        }

        lines[count] = malloc(sizeof(line));
        strcpy(lines[count], line);
        count++;
    }

    return lines;
}

bool isValidLine(char* line) {
    int csvCount = 0;

    if ( isdigit(line[0]) ) {
        csvCount++;
    }

    for (int i=0; i+1<strlen(line); i++) {
        if ( line[i] == ',') {
            csvCount++;
        }
    }

    return (csvCount == 3);
}

char** getLineVals(char* line, int totVals) {
    char** values = malloc((totVals+1) * sizeof(line));
    char* dup = strdup(line);
    char* value = strtok(dup, ",");

    int count = 0;
    while ( value != NULL) {
        values[count] = malloc(sizeof(value));
        strcpy(values[count], value);
        count++;
        value = strtok(NULL, ",");
    }

    return values;
}




